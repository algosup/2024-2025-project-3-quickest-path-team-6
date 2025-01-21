@echo off
<<<<<<< Updated upstream
g++ -std=c++17 Api/main.cpp Api/api.cpp -o Bin/server.exe
=======
g++ -std=c++17 Api/server.cpp Libraries/Tinyxml2/tinyxml2.cpp -o Bin/server.exe -IInclude -Llib -lws2_32 
>>>>>>> Stashed changes
Bin\server.exe