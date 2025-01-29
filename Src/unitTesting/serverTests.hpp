#ifndef SERVER
#define SERVER

#include "unitTesting.hpp"
#include "display.hpp"

/**
 * This function tests the Dijkstra's algorithm.
 * @param None
 * @result A list of 14 tests, each test is displayed on the terminal.
 * If the test takes longer than expected or is incorrect, it is highlighted
 * along with the reason for the failure.
 */
void serverTests()
{
    // Compile server.cpp and run it in another terminal
    system("start cmd.exe /K \"title Server && g++ -std=c++17 ../Server/Api/server.cpp ../Libraries/Tinyxml2/tinyxml2.cpp -o server.exe -IInclude -Llib -lws2_32 && server.exe\"");
    std::this_thread::sleep_for(std::chrono::seconds(5));

    

    system("pause");
}

#endif // !SERVER
