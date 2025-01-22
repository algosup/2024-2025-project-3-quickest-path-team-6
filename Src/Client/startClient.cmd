@echo off

g++ -std=c++17 main.cpp ../Libraries/Tinyxml2/tinyxml2.cpp -o Bin\pathQuick.exe
.\Bin\pathQuick.exe
pause