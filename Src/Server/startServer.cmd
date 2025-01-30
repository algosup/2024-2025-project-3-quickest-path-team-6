@echo off
g++ -std=gnu++20 -O3 -o Bin/server.exe Api/server.cpp ../Libraries/Tinyxml2/tinyxml2.cpp -IInclude -Llib -lws2_32
cls
Bin\server.exe
pause