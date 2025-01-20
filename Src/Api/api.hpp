#ifndef API_H
#define API_H

#include <string>
#include <vector>
#include "../Algorithm/algorithm.cpp"

#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "Ws2_32.lib")
#else
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#endif

using namespace std;

class Api {
public:
    // initializes the server with a specific port
    Api(int port);

    // Starts the server
    void start();

private:
    int port;                  
    int server_socket;

    // Handles client connections
    void handleClient(int client_socket);

    // Processes HTTP requests and generates appropriate responses
    std::string processRequest(const std::string& request);

    // Helper function to send error responses
    std::string generateErrorResponse(const std::string &error_message, int status_code);

    std::string createHttpResponse(const std::string &body, const std::string &contentType);

    void closeSocket(int socket); 
};

#endif
