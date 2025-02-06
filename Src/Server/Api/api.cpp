#ifndef API_CPP
#define API_CPP

#include "../Includes/includes.hpp"
#include "../Algorithm/loadData.hpp"
#include "../Algorithm/algorithm.cpp"
#include "../Formatting/conversionJson.hpp"
#include "../Formatting/conversionXml.hpp"
#include "api.hpp"

// Global flag for sleep animation
bool sleeping = false;
void sleepingAnimation();

// Close a socket using the appropriate platform-specific call
void Api::closeSocket(int socket) {
#ifdef _WIN32
    closesocket(socket);
#else
    close(socket);
#endif
}

// Constructor: Initializes the API with a specific port
Api::Api(int port) : port(port), server_socket(-1) {}

// Starts the server: initializes networking, loads the graph, and listens for connections
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

    std::cout << "Server running on port " << port << "...\n";
    std::cout << "Press 'C' to verify the target .csv file." << std::endl;
    std::cout << "Press 'SPACE' to shut down the server.\n" << std::endl;

    //Start sleep animation and server online thread.
    std::thread(sleepingAnimation).detach();
    std::thread(&Api::serverOnline, this, server_socket).detach();
    
    //main loop: process user input for verification or shutdown 
    char key;
    while(true){
        std::cin.get(key);
        if (key == 'c' || key == 'C') {
            std::string file_name;
            std::string constructed_path_str_dbg = "../../Src";
            std::string ext(".csv");
            for (auto& p : std::filesystem::recursive_directory_iterator(constructed_path_str_dbg)) {
                if (p.path().extension() == ext){
                    std::cout << "Verifying " << p.path().string() << "\n" << std::endl;
                    file_name = p.path().string();
                    break;
                }
            }
            std::thread(verifyData, file_name).detach();
        } else if (key == ' ') {
            break;
        }
    }
}

// Handles a single client connection
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

// Constructs an HTTP response with the specified body and content type 
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

// Processes an HTTP request and generates an appropriate response
std::string Api::processRequest(const std::string &request) {
    size_t query_pos = request.find("/route?");
    if (query_pos != std::string::npos) {
        query_pos += 7; // Skip "/route?"
        size_t end_pos = request.find(" ", query_pos);
        std::string query_string = request.substr(query_pos, end_pos - query_pos);

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
            return generateErrorResponse("Source or destination cannot be empty\n", 400);
        } else if (std::stoi(source) > max_id || std::stoi(destination) > max_id) {
            return generateErrorResponse("Source or destination cannot be over " + std::to_string(max_id) + "\n", 400);
        } else if (std::stoi(source) < min_id || std::stoi(destination) < min_id) {
            return generateErrorResponse("Source or destination cannot be under " + std::to_string(min_id) + "\n", 400);
        } else if (!isInteger(source) || !isInteger(destination)){
            return generateErrorResponse("Source and destination need to be integers\n", 400);
        }

        int start = std::stoi(source);
        int end = std::stoi(destination);
        int path_time;
        sleeping = false;
        std::vector<int> path = bidirectionalDijkstra(data_graph, start, end, &path_time);

        // Generate JSON or XML response based on the format
        if (format == "json") {
            nlohmann::json json_data;
            convertIntoJson(path, path_time, json_data);
            std::string json_body = json_data.dump(4);
            return Api::createHttpResponse(json_body, "application/json");
        } else if (format == "xml") {
            tinyxml2::XMLDocument xml_doc;
            convertIntoXml(path, path_time, xml_doc);
            tinyxml2::XMLPrinter printer;
            xml_doc.Print(&printer);
            return Api::createHttpResponse(printer.CStr(), "application/xml");
        } else {
            std::ostringstream response;
            std::cout << "Request completed with unrecognized file format. Path converted into plain text response.\n" << std::endl;
            response << "File format not recognized.\nTravel Time: " << path_time << "\nPath: ";
            for (const auto &landmark : path) {
                response << landmark << " ";
            }
            return Api::createHttpResponse(response.str(), "text/plain");
        }
    } 
    query_pos = request.find("/id?");
    if(query_pos != std::string::npos) {
        std::ostringstream response;
        response << "min_id=" << min_id << "&max_id=" << max_id;
        return Api::createHttpResponse(response.str(), "text/plain");
    } else {
        return generateErrorResponse("Invalid request path", 400);
    }
}

// Generates an error HTTP response
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

// Continuously accepts clients connections and spawns a new thread for each
void Api::serverOnline(int server_socket) {
    while(true) {
        int client_socket = accept(server_socket, nullptr, nullptr);
        if (client_socket < 0) {
            perror("Accept failed");
            continue;
        }
        std::thread(&Api::handleClient, this, client_socket).detach();
    }
}

// Displays a simple sleep animation; toggles state based on elapsed time.
void sleepingAnimation() {
    int cat_state = 0;
    while(true){
        while(pause_cat == true){wait_ms(1);}
        auto start = high_resolution_clock::now();
        while(!sleeping && pause_cat == false){
            cout << "\\(^owo^)  " << "\r" << flush;
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<seconds>(stop - start);
            if(duration.count() >= 10){
                sleeping = true;
            }
            wait_ms(1);
        }
        while(sleeping && pause_cat == false){
            if(cat_state == 0) {
                cout << "_(^-w-^)z " << "\r" << flush;
                cat_state = 1;
            } else if(cat_state == 1) {
                cout << "_(^-w-^) z" << "\r" << flush;
                cat_state = 0;
            }
            wait_ms(500);
        }
        sleeping = false;
    }
}

#endif
