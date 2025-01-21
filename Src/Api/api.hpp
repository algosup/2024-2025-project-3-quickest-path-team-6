#ifndef API_HPP
#define API_HPP

#include <string>
#include <vector>

#define NOCRYPT
#define NOGDI
#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <cstddef>
namespace my_std = std;
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "Ws2_32.lib")
#define byte windows_byte
#include <windows.h>
#undef byte
#include <string>
#include <vector>
#include <iostream>

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


    void closeSocket(int socket); 
};

#endif
