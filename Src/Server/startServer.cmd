@echo off
g++ -std=gnu++20 -O3 -o Bin/server.exe -IInclude -Llib -lws2_32 Api/server.cpp ../Libraries/Tinyxml2/tinyxml2.cpp
Bin\server.exe