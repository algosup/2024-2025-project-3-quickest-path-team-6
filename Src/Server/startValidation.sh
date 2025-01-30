cd "$(dirname "$0")"
clear
g++ -std=c++17 DataValidation/validateCsv.cpp -o Bin/dataValidation 
./Bin/dataValidation