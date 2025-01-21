@echo off
g++ -std=c++17 Api/server.cpp Libraries/Tinyxml2/tinyxml2.cpp -o Bin/server.exe -IInclude -Llib -lws2_32 
Bin\server.exe