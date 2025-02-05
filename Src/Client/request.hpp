#ifndef REQUEST_HPP
#define REQUEST_HPP

/*
    Handles HTTP requests, socket management, and response processing to send requests to the server
*/

#include "Includes/includes.hpp"
#include "../Libraries/Nlohmann/json.hpp"

using json = nlohmann::json;
using namespace std;

// Global variable to track server status
bool server_is_online = false;

void sendRequest(string http_request, string &body);

/*
    Closes a socket connection based on the operating system

    Parameters: 
        - socket, integer representing the file descriptor
*/
void closeSocketRequest(int socket) {
#ifdef _WIN32
    closesocket(socket); // Use Winsock's closesocket on Windows
#else
    close(socket); // Use POSIX's close on Linux/macOS
#endif
}

/*
    Writes the response body to a file in the specified format

    Parameters: 
        - format, constant string reference as the file format (e.g., JSON, XML)
        - body, constant string reference as the response content to be written
*/
void writeToFile(const string& format, const string& body) {
    string filename = "Bin/pathQuick." + format;
    ofstream file(filename, ios::out);
    if (!file) {
        cerr << "Error opening file for writing!" << endl;
        return;
    }
    file << body;
    file.close();
    cout << "Response written to " << filename;
}

/*
    Encodes a URL string by converting special characters into percent-encoded format
    This function returns an encoded URL string

    Parameters:
        - str, constant string reference as the string to encode
*/
string urlEncode(const string &str) {
    ostringstream encoded;
    for (unsigned char c : str) {
        if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~') {
            encoded << c;
        } else {
            encoded << '%' << setw(2) << setfill('0') << hex << (int)c;
        }
    }
    return encoded.str();
}

/*
    Sends a request to calculate the shortest path and processes the response.

    Parameters:
        - start, integer as the start point identifier
        - end, integer as the end point identifier
        - file_format, string as the desired response format (e.g., JSON, XML)
*/
void sendRequestQuickPath(int start, int end, string file_format) {
    cout << "Calculating shortest path..." << endl << endl;
    auto time_start = chrono::high_resolution_clock::now();

    string encoded_source = urlEncode(to_string(start));
    string encoded_destination = urlEncode(to_string(end));
    string encoded_format = urlEncode(file_format);

    string http_request = "GET /route?source=" + encoded_source + "&destination=" + encoded_destination + "&format=" + encoded_format + " HTTP/1.1\r\n"
                          "Host: localhost:8080\r\n"
                          "Connection: close\r\n"
                          "\r\n";

    string body;
    sendRequest(http_request, body);

    // Verifying if the server is online to send the request
    if (server_is_online) {
        writeToFile(file_format, body);
        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(stop - time_start);
        cout << endl << "Path calculated in " << duration.count() << " milliseconds." << endl;
    } else {
        cerr << "Error connecting to server!" << endl;
    }
}

/*
    Sends a request to retrieve the lowest and highest available IDs of the .csv file from the server

    Parameters:
        - lowest_id, integer reference to store the lowest ID
        - highest_id, integer reference to store the highest ID
*/
void sendRequestId(int &lowest_id, int &highest_id) {
    while (true) {
        string http_request = "GET /id? HTTP/1.1\r\n"
                              "Host: localhost:8080\r\n"
                              "Connection: close\r\n"
                              "\r\n";
        
        string body;
        sendRequest(http_request, body);

        if (!server_is_online) {
            lowest_id = 0;
            highest_id = 0;
        } else if (server_is_online && lowest_id == 0 && highest_id == 0) {
            istringstream query_stream(body);
            string param;
            while (getline(query_stream, param, '&')) {
                size_t eq_pos = param.find('=');
                if (eq_pos != string::npos) {
                    string key = param.substr(0, eq_pos);
                    string value = param.substr(eq_pos + 1);
                    if (key == "min_id") lowest_id = stoi(value);
                    else if (key == "max_id") highest_id = stoi(value);
                }
            }
        }
    }
}

/*
    Sends an HTTP request and retrieves the response body

    Parameters:
        - http_request, string as the formatted HTTP request string
        - body, string reference to store the response body
*/
void sendRequest(string http_request, string &body) {
#ifdef _WIN32
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        return; // Winsock initialization failed
    }
#endif
    
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        cerr << "Error creating socket!" << endl;
        return;
    }

    sockaddr_in server_addr{};
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        closeSocketRequest(sockfd);
        server_is_online = false;
        return;
    }

    server_is_online = true;
    send(sockfd, http_request.c_str(), http_request.size(), 0);

    string response;
    char buffer[4096];
#ifdef _WIN32
    SSIZE_T bytes_received;
#else
    ssize_t bytes_received;
#endif
    while ((bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_received] = '\0';
        response += buffer;
    }

    closeSocketRequest(sockfd);
    size_t header_end = response.find("\r\n\r\n");
    if (header_end != string::npos) {
        body = response.substr(header_end + 4);
    }
}

#endif // REQUEST_HPP