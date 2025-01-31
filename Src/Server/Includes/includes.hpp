#ifndef INCLUDES_HPP
#define INCLUDES_HPP

// ============ Input/Output ============
#include <iostream> 
#include <iomanip>
// =============== Streams ==============
#include <fstream> 
#include <sstream> 
// =============== Types ===============
#include <string> 
#include <vector> 
#include <queue>
#include <unordered_map>
#include <unordered_set>
// ========== Chrono & Threads ==========
#include <chrono> 
#include <thread> 
// =============== Windows ==============
#ifdef _WIN32
#include <cstddef>
namespace my_std = std;
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "Ws2_32.lib")
#define byte windows_byte
#include <windows.h>
#undef byte
// ============= Unix/Linux =============
#else
#include <unistd.h>
#include <sys/socket.h>
#include <termios.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#endif
// ================ JSON ================
#include "../../Libraries/nlohmann/json.hpp"
// ================= XML ================
#include "../../Libraries/Tinyxml2/tinyxml2.h"
// ================ Maths ===============
#include <limits>
#include <algorithm>

#include <filesystem>

namespace fs = std::filesystem;
using namespace std;
using namespace fs;
using namespace std::chrono;


#endif // !INCLUDES_HPP