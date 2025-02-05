#ifndef API_HPP
#define API_HPP

#ifndef NOMINMAX
#define NOMINMAX  // Prevent redefinition of min/max macros
#endif

#define NOCRYPT
#define NOGDI
#define WIN32_LEAN_AND_MEAN

#include "../Includes/includes.hpp"

/*
 * Api class
 * -----------
 * Provides the interface for initializing and running the HTTP server.
 */
class Api {
public:
    // Constructor: initializes the server with the given port.
    Api(int port);

    // Starts the server.
    void start();

private:
    int port;           // Server port.
    int server_socket;  // Socket descriptor.

    // Accepts client connections in a loop.
    void serverOnline(int server_socket);

    // Handles a single client connection.
    void handleClient(int client_socket);

    // Processes an HTTP request and returns an appropriate response.
    std::string processRequest(const std::string& request);

    // Constructs and returns an error response.
    std::string generateErrorResponse(const std::string &error_message, int status_code);

    // Constructs a standard HTTP response with the given body and content type.
    std::string createHttpResponse(const std::string &body, const std::string &content_type);

    // Closes a socket using the appropriate platform-specific function.
    void closeSocket(int socket); 
};

#endif
