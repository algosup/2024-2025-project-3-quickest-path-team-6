#ifndef API_H
#define API_H

#include <string>
#include <vector>

#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "Ws2_32.lib")
#else
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#endif


class Api {
public:
    // Constructor initializes the server with a specific port
    Api(int port);

    // Starts the server
    void start();

private:
    int port;                  // Server port
    int server_socket;         // Server socket descriptor

    // Handles client connections
    void handleClient(int client_socket);

    // Processes HTTP requests and generates appropriate responses
    std::string processRequest(const std::string& request);

    // Helper function to send error responses
    std::string generateErrorResponse(const std::string& error_message);

    void closeSocket(int socket); // Declaration of closeSocket function
};

#endif // API_H
