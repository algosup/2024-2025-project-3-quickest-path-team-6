#ifndef INCLUDES_HPP
#define INCLUDES_HPP

/*
    Header file containing necessary includes
        - input/output
        - string handling
        - threading
        - networking
        - platform-specific operations
*/

// ============ Input/Output ============
#include <iostream>  // Standard I/O operations
#include <iomanip>   // Input/output manipulators

// =============== Streams ==============
#include <fstream>   // File input/output operations
#include <sstream>   // String stream processing

// =============== String ===============
#include <string>    // String manipulation utilities

// ========== Chrono & Threads ==========
#include <chrono>    // Time measurement and delays
#include <thread>    // Multi-threading support

// =============== Windows ==============
#ifdef _WIN32
#include <winsock2.h>  // Windows socket API
#include <ws2tcpip.h>  // Additional Windows socket functions
#include <windows.h>   // Windows API functions

// ============= Unix =============
#else
#include <unistd.h>    // Unix standard functions
#include <sys/socket.h> // Socket programming
#include <netinet/in.h> // Internet address family
#include <termios.h>   // Terminal control
#include <arpa/inet.h> // IP address conversion functions
#endif

#include <limits>      // Numeric limits

using namespace std;

#endif // INCLUDES_HPP