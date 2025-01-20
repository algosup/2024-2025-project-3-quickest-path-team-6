@echo off
g++ -std=c++17 Api/main.cpp Libraries/Tinyxml2/tinyxml2.cpp -o Bin/server.exe
Bin\server.exe