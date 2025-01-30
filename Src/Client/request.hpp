#ifndef REQUEST_HPP
#define REQUEST_HPP

#include "Includes/includes.hpp"
#include "../Libraries/Nlohmann/json.hpp"

using json = nlohmann::json;
using namespace std;

bool server_is_online = false;

void sendRequest(string http_request, string &body);

void closeSocketRequest(int socket)
{
#ifdef _WIN32
    closesocket(socket); // Use Winsock's closesocket on Windows
#else
    close(socket); // Use POSIX's close on Linux/macOS
#endif
}

// URL encoding function
string urlEncode(const string &str)
{
    ostringstream encoded;
    for (unsigned char c : str)
    {
        if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~')
        {
            encoded << c;
        }
        else
        {
            encoded << '%' << setw(2) << setfill('0') << hex << (int)c;
        }
    }
    return encoded.str();
}

// Function to send the request and handle the response
void sendRequestQuickPath(int start, int end, string file_format)
{
    cout << "Calculating shortest path..." << endl
         << endl;
    auto time_start = chrono::high_resolution_clock::now(); // get time

    // Prepare the API request
    string source = to_string(start);
    string destination = to_string(end);
    string format = file_format;

    // URL-encode the source, destination, and format
    string encoded_source = urlEncode(source);
    string encoded_destination = urlEncode(destination);
    string encoded_format = urlEncode(format);

    // Build the HTTP GET request
    string http_request = "GET /route?source=" + encoded_source + "&destination=" + encoded_destination + "&format=" + encoded_format + " HTTP/1.1\r\n"
                                                                                                                                        "Host: localhost:8080\r\n"
                                                                                                                                        "Connection: close\r\n"
                                                                                                                                        "\r\n";

    string body;
    sendRequest(http_request, body);

    if (server_is_online)
    {
        // Write the body to a file
        string filename = "Bin/pathQuick." + format;
        ofstream file(filename, ios::out);
        if (!file)
        {
            cerr << "Error opening file for writing!" << endl;
            return;
        }
        if (format == "json")
        {
            json json_obj = json::parse(body);
            file << setw(4) << json_obj.dump(4);
            ;
        }
        else
        {
            file << body;
        }
        file.close();

        cout << "Response written to " << filename;

        // Measure time
        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(stop - time_start);
        if (duration.count() > 2000)
        {
            cout << endl
                 << "Path calculated in " << duration.count() / 1000 << " seconds." << endl;
        }
        else
        {
            cout << endl
                 << "Path calculated in " << duration.count() << " milliseconds." << endl;
        }
    }
    else
        cerr << "Error connecting to server!" << endl;
}

void sendRequestId(int &lowest_id, int &highest_id)
{
    while (true)
    {
        // Build the HTTP GET request
        string http_request = "GET /id? HTTP/1.1\r\n"
                              "Host: localhost:8080\r\n"
                              "Connection: close\r\n"
                              "\r\n";

        string body;
        sendRequest(http_request, body);

        if (!server_is_online)
        {
            lowest_id = 0;
            highest_id = 0;
        }
        else if (server_is_online && lowest_id == 0 && highest_id == 0)
        {
            istringstream query_stream(body);
            string param;

            while (getline(query_stream, param, '&'))
            {
                size_t eq_pos = param.find('=');
                if (eq_pos == string::npos)
                    continue;

                string key = param.substr(0, eq_pos);
                string value = param.substr(eq_pos + 1);

                if (key == "min_id")
                {
                    lowest_id = stoi(value);
                }
                else if (key == "max_id")
                {
                    highest_id = stoi(value);
                }
            }
        }
    }
}

void sendRequest(string http_request, string &body)
{
    #ifdef _WIN32

    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        // Handle Winsock initialization error
        return;
    }
    #endif
    // Set up the socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {

        cerr << "Error creating socket!" << endl;
        return;
    }

    sockaddr_in server_addr{};
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);                     // Server port
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr); // Server address

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        closeSocketRequest(sockfd);
        server_is_online = false;
        return;
    }

    server_is_online = true;
    // Send the HTTP request
    send(sockfd, http_request.c_str(), http_request.size(), 0);

    // Receive the response
    string response;
    char buffer[4096];
#ifdef _WIN32
    SSIZE_T bytes_received;
#else
    ssize_t bytes_received;
#endif

    while ((bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0)) > 0)
    {
        buffer[bytes_received] = '\0';
        response += buffer;
    }

    closeSocketRequest(sockfd); // Close the socket

    // Separate the HTTP headers and body
    size_t header_end = response.find("\r\n\r\n");
    if (header_end == string::npos)
    {
        return;
    }

    body = response.substr(header_end + 4); // Skip the "\r\n\r\n"
}
#endif // !REQUEST_HPP
