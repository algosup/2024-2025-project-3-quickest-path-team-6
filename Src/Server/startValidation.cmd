@echo off

g++ -std=c++17 DataValidation/validateCsv.cpp -DSTANDALONE -o Bin\dataValidation.exe
.\Bin\dataValidation.exe
pause