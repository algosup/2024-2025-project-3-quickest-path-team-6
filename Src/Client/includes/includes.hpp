#ifndef INCLUDES_HPP
#define INCLUDES_HPP

// ============ Input/Output ============
#include <iostream> 
#include <iomanip>
// =============== Streams ==============
#include <fstream> 
#include <sstream> 
// =============== String ===============
#include <string> 
// ========== Chrono & Threads ==========
#include <chrono> 
#include <thread>
// =============== Windows ==============
#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>
// ============= Unix/Linux =============
#else
#include <unistd.h>
#include <sys/socket.h>
#include <Kernel/netinet/in.h>
#include <termios.h>
#endif

#include <limits>
using namespace std;

#endif // !INCLUDES_HPP