#include "api.hpp"
#include <iostream>
#include <sstream>
#include <vector>
#include <chrono>
#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>
#else
#include <unistd.h>
#include <sys/socket.h>
#include <Kernel/netinet/in.h>
#include <termios.h>
#endif
#pragma comment(lib, "Ws2_32.lib")
#include "../Algorithm/algorithm.cpp"
#include "../Formatting/conversionJson.hpp"
#include "../Formatting/conversionXml.hpp"

bool sleeping = false;
void sleepingAnimation();

void Api::closeSocket(int socket) {
    #ifdef _WIN32
        closesocket(socket); // Use Winsock's closesocket on Windows
    #else
        close(socket);       // Use POSIX's close on Linux/macOS
    #endif
}

// Constructor to initialize the API with a specific port
Api::Api(int port) : port(port), server_socket(-1) {}

void Api::start() {
    #ifdef _WIN32
        WSADATA wsa_data;
        if (WSAStartup(MAKEWORD(2, 2), &wsa_data) != 0) {
            std::cerr << "WSAStartup failed\n";
            exit(EXIT_FAILURE);
        }
    #endif

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket creation failed");
        #ifdef _WIN32
            WSACleanup();
        #endif
        exit(EXIT_FAILURE);
    }

    // Set SO_REUSEADDR to avoid "address already in use" errors
    int opt = 1;
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, (char*)&opt, sizeof(opt)) < 0) {
        perror("setsockopt failed");
        closeSocket(server_socket);
        exit(EXIT_FAILURE);
    }

    sockaddr_in serverAddr{};
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(port);

    int bind_result = ::bind(server_socket, (sockaddr*)&serverAddr, sizeof(serverAddr));
    if (bind_result < 0) {
        perror("Bind failed");
        closeSocket(server_socket);
        #ifdef _WIN32
            WSACleanup();
        #endif
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, SOMAXCONN) < 0) {
        perror("Listen failed");
        closeSocket(server_socket);
        #ifdef _WIN32
            WSACleanup();
        #endif
        exit(EXIT_FAILURE);
    }

    cout << "Server running on port " << port << "...\n";
    cout << "Press \'C\' to verify the target .csv file." << endl;
    cout << "Press \'SPACE\' to shut down the server.\n" << endl;

    thread(sleepingAnimation).detach();
    thread(&Api::serverOnline, this, server_socket).detach();
    
    char key;
    while(true){
        cin.get(key);
        if (key == 'c' || key == 'C')
        {
            string file_name;

            string constructed_path_str_dbg = "../../Src";
            string ext(".csv");
            for (auto& p : recursive_directory_iterator(constructed_path_str_dbg))
            {
                if (p.path().extension() == ext){
                    cout << "Verifying " << p << "\n" << endl;
                    file_name = p.path().string();
                    break;
                }
            }

            thread(verifyData, file_name).detach();
        }
        else if (key == ' '){
            break;
        }
    }
}

void Api::handleClient(int client_socket) {
    try {
        char buffer[1024] = {0};
        int bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);

        if (bytes_received <= 0) {
            closeSocket(client_socket);
            return;
        }

        std::string request(buffer, bytes_received);
        std::string response = processRequest(request);

        send(client_socket, response.c_str(), response.size(), 0);
    } catch (const std::exception &e) {
        std::cerr << "Error handling client: " << e.what() << std::endl;
    }

    closeSocket(client_socket);
    sleeping = false;
}

std::string Api::createHttpResponse(const std::string &body, const std::string &content_type) {
    std::ostringstream response;
    response << "HTTP/1.1 200 OK\r\n"
             << "Content-Type: " << content_type << "\r\n"
             << "Content-Length: " << body.size() << "\r\n"
             << "Connection: close\r\n"
             << "\r\n"
             << body;
    return response.str();
}

std::string Api::processRequest(const std::string &request) {
    // Find the starting position of the query string
    size_t query_pos = request.find("/route?");
    if (query_pos == std::string::npos) {
        return generateErrorResponse("Invalid request path", 400);
    }

    // Extract the query string
    query_pos += 7; // Skip "/route?"
    size_t end_pos = request.find(" ", query_pos); // End of the query
    std::string query_string = request.substr(query_pos, end_pos - query_pos);

    // Parse the query string for parameters
    std::string source, destination, format;
    std::istringstream query_stream(query_string);
    std::string param;

    while (std::getline(query_stream, param, '&')) {
        size_t eq_pos = param.find('=');
        if (eq_pos == std::string::npos) continue;

        std::string key = param.substr(0, eq_pos);
        std::string value = param.substr(eq_pos + 1);

        if (key == "source") {
            source = value;
        } else if (key == "destination") {
            destination = value;
        } else if (key == "format") {
            format = value;
        }
    }

    // Validate parameters
    if (source.empty() || destination.empty()) {
        return generateErrorResponse("Source or destination cannot be empty", 400);
    }

    // Perform your graph traversal using the parsed parameters
    int start = std::stoi(source);
    int end = std::stoi(destination);
    int path_time;

    std::vector<int> path = modifiedDijkstra(graph, start, end, &path_time);

    // Generate JSON, XML or plain text response based on the format
    if (format == "json") {
        convertIntoJson(path, path_time);
        return createHttpResponse("Data converted into JSON.", "application/json");
    } if (format == "xml") {
        convertIntoXml(path, path_time);
        return createHttpResponse("Data converted into XML.", "application/xml");
    } else {
        // Default to plain text response
        std::ostringstream response;
        response << "Travel Time: " << path_time << "\nPath: ";
        for (const auto &landmark : path) {
            response << landmark << " ";
        }
        return createHttpResponse(response.str(), "text/plain");
    }
}

std::string Api::generateErrorResponse(const std::string &error_message, int status_code) {
    std::ostringstream response;
    response << "HTTP/1.1 " << status_code;

    if (status_code == 400) {
        response << " Bad Request";
    } else if (status_code == 404) {
        response << " Not Found";
    } else if (status_code == 500) {
        response << " Internal Server Error";
    }

    response << "\r\nContent-Type: text/plain\r\n\r\n" << error_message;
    return response.str();
}

void Api::serverOnline(int server_socket){
    while(true){
        int client_socket = accept(server_socket, nullptr, nullptr);
        if (client_socket < 0) {
            perror("Accept failed");
            continue;
        }

        thread(&Api::handleClient, this, client_socket).detach();
    }
}

void sleepingAnimation()
{
    while(true){
        auto start = high_resolution_clock::now();
        while(!sleeping){
            cout << "\\(^•w•^)                             " << "\r" << flush;
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<seconds>(stop - start);
            if(duration.count() >= 10){
                sleeping = true;
            }
            wait(1000);
        }
        while(sleeping){
            cout << "_(^-w-^)z                            " << "\r" << flush;
            wait(500000);
            cout << "_(^-w-^) z                           " << "\r" << flush;
            wait(500000);
        }
        sleeping = false;
    }
}