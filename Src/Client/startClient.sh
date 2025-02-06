cd "$(dirname "$0")"
clear
g++ -std=c++17 main.cpp ../Libraries/Tinyxml2/tinyxml2.cpp -o Bin/pathQuick 
# Compile for unit tests
g++ -std=c++17 main.cpp ../Libraries/Tinyxml2/tinyxml2.cpp -o ../UnitTesting/Bin/pathQuick
./Bin/pathQuick