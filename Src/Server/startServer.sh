cd "$(dirname "$0")"
g++ -std=gnu++20 -O3 -o Bin/server Api/server.cpp ../Libraries/Tinyxml2/tinyxml2.cpp
# Compile for unit tests
g++ -std=gnu++20 -O3 -o ../UnitTesting/Bin/server Api/server.cpp ../Libraries/Tinyxml2/tinyxml2.cpp
clear
./Bin/server