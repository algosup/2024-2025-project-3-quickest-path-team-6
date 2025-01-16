@echo off

set INCLUDE_PATH=C:\msys64\mingw64\include
set LIBRARY_PATH=C:\msys64\mingw64\lib

g++ -std=c++17 -I%INCLUDE_PATH% -L%LIBRARY_PATH% -ltinyxml2 main.cpp -o Bin\pathQuick.exe
Bin\pathQuick.exe
