@echo off

g++ -std=c++17 -o Bin\pathQuick.exe  main.cpp ../Libraries/Tinyxml2/tinyxml2.cpp -lws2_32
Bin\pathQuick.exe
pause