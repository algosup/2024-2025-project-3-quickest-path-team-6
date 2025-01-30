#ifndef SERVER
#define SERVER

#include "../unitTesting.hpp"
#include "../display.hpp"
#include "../../Client/request.hpp"
#include "../../Libraries/nlohmann/json.hpp"

void sendPingRequest()
{
    // Build a lightweight HTTP GET request
    string http_request = "GET /ping HTTP/1.1\r\n"
                          "Host: localhost:8080\r\n"
                          "Connection: close\r\n"
                          "\r\n";

    string body;
    sendRequest(http_request, body);
}

void compareJSON(const json &expected, int testID)
{
    // Open the file
    ifstream file("./Bin/pathQuick.json");
    if (!file)
    {
        cout << "\e[0;31mTest failed, json file does not exists.\e[0;37m\n";
        return;
    }

    // Parse the file content as JSON
    json fileJson;
    try
    {
        file >> fileJson;
    }
    catch (const json::parse_error &e)
    {
        cout << "\e[0;31mTest failed, unable to read json file.\e[0;37m\n";
        return;
    }
    // Check the result
    if (fileJson["time"] == expected["time"] && fileJson["path"] == expected["path"])
    {
        cout << "\e[0;32mTest " << testID << " passed\e[0;37m\n";
    }
    else
    {
        cout << "\e[0;31m===========================Test " << testID << "===========================\n";
        cout << "Expected Value:\n"
             << "Time: " << expected["time"].get<int>() // Correctly extract the scalar value
             << "\n"
             << "Path: ";
        printVector(expected["path"].get<vector<int>>()); // Ensure the correct type
        cout << "\nOutput Value:\n"
             << "Time: " << fileJson["time"].get<int>() // Correctly extract the scalar value
             << "\n"
             << "Path: ";
        printVector(fileJson["path"].get<vector<int>>()); // Ensure the correct type
        cout << "============================================================\n\e[0;37m";
    }

    return;
}

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
    for (int i = 0; i < 10; i++)
    {
        this_thread::sleep_for(std::chrono::seconds(5));
        sendPingRequest();
        if (server_is_online)
        {
            break;
        }
    }
    if (!server_is_online)
    {
        cout << "\e[0;31mTest failed, unable to connect with the server.\e[0;37m\n";
        system("pause");
        return;
    }

    // Declare and initialize testPaths
    list<pair<int, int>> testPaths = {
        {1, 2},     // Test 1
        {9, 6},     // Test 2
        {1, 1},     // Test 3
        {946, 483}, // Test 4
        {123, 321}, // Test 5
    };
    list<json> results = {
        {// Test 1
         {"path", {1, 2}},
         {"time", 5062}},
        // Test 2
        {{"path", {9, 10, 11, 27, 24, 5, 6}},
         {"time", 64267}},
        // Test 3
        {{"path", {1}},
         {"time", 0}},
        // Test 4
        {{"path", {946, 862, 945, 876, 949, 1043, 1038, 986, 988, 1173, 1122, 1246, 201, 202, 1224, 1222, 1223, 1282, 1220, 1221, 1216, 1217, 1199, 1200, 1305, 4527, 1303, 1304, 1135, 1182, 1300, 1181, 1179, 1180, 482, 483}},
         {"time", 432917}},
        // Test 5
        {{"path", {123, 82031, 100, 99, 120, 121, 122, 82045, 82044, 82043, 82037, 82035, 82036, 82033, 82163, 82164, 82135, 82134, 82136, 4386, 93, 83, 56, 189, 186, 187, 283, 143, 132, 128, 129, 280, 127, 126, 242, 319, 320, 321}},
         {"time", 296801}},
    };
    auto pathIt = testPaths.begin();
    auto resultIt = results.begin();
    int testID = 1;

    // Iterate through testPaths and results simultaneously
    for (; pathIt != testPaths.end() && resultIt != results.end(); ++pathIt, ++resultIt)
    {
        const auto &[start, end] = *pathIt;
        int path_time;    // Resulting time
        vector<int> path; // Resulting path

        // Use a promise and future to handle the timeout
        promise<bool> resultPromise;
        auto resultFuture = resultPromise.get_future();

        thread thread([&]()
                      {
            try {
                sendRequestQuickPath(start, end, "json");
                resultPromise.set_value(true);
            }
            catch (...) {
                resultPromise.set_exception(current_exception());
            } });

        // Wait for the result with a timeout
        if (resultFuture.wait_for(chrono::seconds(1)) == future_status::timeout)
        {
            cout << "\e[0;31m===========================Test " << testID << "===========================\n";
            cout << "Test timed out after 1 second.\n";
            cout << "============================================================\n\e[0;37m";
            thread.detach(); // Let the thread run in the background
        }
        else
        {
            thread.join(); // Ensure the thread finishes
            compareJSON(*resultIt, testID);
        }
        testID++;

        // Iterate through testPaths and results simultaneously
    }
    system("pause");
}
#endif // !SERVER
