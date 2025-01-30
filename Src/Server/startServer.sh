cd "$(dirname "$0")"
g++ -std=gnu++20 -O3 -o Bin/server Api/server.cpp ../Libraries/Tinyxml2/tinyxml2.cpp
clear
./Bin/server