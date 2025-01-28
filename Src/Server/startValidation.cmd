@echo off

g++ -std=c++17 DataValidation/validateCsv.cpp -o Bin\dataValidation.exe
.\Bin\dataValidation.exe
pause