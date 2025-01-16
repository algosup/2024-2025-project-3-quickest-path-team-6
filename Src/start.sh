#!/bin/bash
g++ -std=c++17 -I/opt/homebrew/include -L/opt/homebrew/lib -ltinyxml2 main.cpp -o Bin/pathQuick
./Bin/pathQuick
