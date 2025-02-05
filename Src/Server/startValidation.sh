cd "$(dirname "$0")"
clear
g++ -std=c++17 DataValidation/validateCsv.cpp -DSTANDALONE -o Bin/dataValidation 
./Bin/dataValidation