#include "api.h"
#include "JsonXml/jsonParser.h"
#include "JsonXml/xmlParser.h"
#include <iostream>
#include <sstream>
#include <thread>

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
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "WSAStartup failed\n";
        exit(EXIT_FAILURE);
    }
#endif

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        std::cerr << "Socket creation failed\n";
#ifdef _WIN32
        WSACleanup();
#endif
        exit(EXIT_FAILURE);
    }

    sockaddr_in serverAddr{};
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(port);

    if (bind(server_socket, (sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        std::cerr << "Bind failed\n";
        closeSocket(server_socket);
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, SOMAXCONN) < 0) {
        std::cerr << "Listen failed\n";
        closeSocket(server_socket);
        exit(EXIT_FAILURE);
    }

    std::cout << "Server running on port " << port << "...\n";

    while (true) {
        int client_socket = accept(server_socket, nullptr, nullptr);
        if (client_socket < 0) {
            std::cerr << "Accept failed\n";
            continue;
        }

        std::thread(&Api::handleClient, this, client_socket).detach();
    }
}

void Api::handleClient(int client_socket) {
    char buffer[1024] = {0};
    int bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
    if (bytes_received <= 0) {
        closeSocket(client_socket);
        return;
    }

    std::string request(buffer, bytes_received);
    std::string response = processRequest(request);

    send(client_socket, response.c_str(), response.size(), 0);
    closeSocket(client_socket);
}

std::string Api::processRequest(const std::string& request) {
    size_t source_pos = request.find("source=");
    size_t dest_pos = request.find("&dest=");
    if (source_pos == std::string::npos || dest_pos == std::string::npos) {
        return generateErrorResponse("Missing source or destination parameters");
    }

    source_pos += 7;
    std::string source_id = request.substr(source_pos, dest_pos - source_pos);

    dest_pos += 6;
    size_t end_pos = request.find(" ", dest_pos);
    std::string destination_id = request.substr(dest_pos, end_pos - dest_pos);

    int travel_time = 15;
    std::vector<std::string> path = {"LandmarkA", "LandmarkB", "LandmarkC"};

    if (request.find("Accept: application/xml") != std::string::npos) {
        return "HTTP/1.1 200 OK\r\nContent-Type: application/xml\r\n\r\n" +
               XmlParser::formatResponse(travel_time, path);
    }

    return "HTTP/1.1 200 OK\r\nContent-Type: application/json\r\n\r\n" +
           JsonParser::formatResponse(travel_time, path);
}

std::string Api::generateErrorResponse(const std::string& error_message) {
    return "HTTP/1.1 400 Bad Request\r\nContent-Type: text/plain\r\n\r\n" + error_message;
}

// Helper function to close a socket
void Api::closeSocket(int socket) {
#ifdef _WIN32
    closesocket(socket);
#else
    close(socket);
#endif
}
