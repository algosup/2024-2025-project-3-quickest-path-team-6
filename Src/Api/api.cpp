#include "api.hpp"
#include <iostream>
#include <sstream>
#include <thread>
#include <vector>
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "Ws2_32.lib")
#include "../Algorithm/algorithm.cpp"
#include "../Headers/Formatting/convertionJson.hpp"
#include "../Headers/Formatting/convertionXml.hpp"

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
}

std::string Api::processRequest(const std::string &request) {
    // Parse the request for "source" and "dest" parameters
    size_t source_pos = request.find("source=");
    size_t dest_pos = request.find("&dest=");

    // Check if "source=" and "&dest=" are present
    if (source_pos == std::string::npos || dest_pos == std::string::npos) {
        return generateErrorResponse("Missing source or destination parameters", 400);
    }

    // Extract source and destination
    source_pos += 7; // Skip "source="
    std::string source_id = request.substr(source_pos, dest_pos - source_pos);

    dest_pos += 6; // Skip "&dest="
    size_t end_pos = request.find(" ", dest_pos);
    std::string destination_id = request.substr(dest_pos, end_pos - dest_pos);

    // Validate if the source or destination is empty
    if (source_id.empty() || destination_id.empty()) {
        return generateErrorResponse("Source or destination cannot be empty", 400);
    }

    // Validate landmarks (replace this mock with actual graph checks)
    if (source_id != "LandmarkA" && source_id != "LandmarkB" && source_id != "LandmarkC") {
        return generateErrorResponse("Landmark not found: " + source_id, 404);
    }
    if (destination_id != "LandmarkA" && destination_id != "LandmarkB" && destination_id != "LandmarkC") {
        return generateErrorResponse("Landmark not found: " + destination_id, 404);
    }

    // Mock backend logic (to be replaced)
    int travel_time = 15; // Placeholder value
    std::vector<std::string> path = {source_id, "Intermediate", destination_id};

    // Generate the response
    std::ostringstream response;
    response << "HTTP/1.1 200 OK\r\n"
             << "Content-Type: text/plain\r\n"
             << "Content-Length: " << 40 + path.size() * 10 << "\r\n"
             << "Connection: close\r\n"
             << "\r\n"
             << "Travel Time: " << travel_time << " minutes\n"
             << "Path: ";
    for (const auto &landmark : path) {
        response << landmark << " ";
    }

    return response.str();
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







