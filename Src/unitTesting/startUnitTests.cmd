@echo off
g++ -std=gnu++20 -O3 -o Bin/unitTesting.exe ./unitTesting.cpp -lws2_32
cls
Bin\unitTesting.exe
pause