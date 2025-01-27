#include <assert.h>
#include <list>
#include "../Server/Algorithm/algorithm.cpp"

void printVector(const std::vector<int> &vec)
{
    std::cout << "[";
    for (size_t i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i];
        if (i != vec.size() - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << "]\n";
}

int main()
{
    // Declare and initialize testPaths
    list<pair<int, int>> testPaths = {
        {4, 1},  // Test 1
        {9, 3},  // Test 2
        {2, 10}, // Test 3
        {7, 5},  // Test 4
        {6, 8},  // Test 5
        {5, 10}, // Test 6
        {3, 2},  // Test 7
        {8, 8},  // Test 8
        {9, 6},  // Test 9
        {3, 7},  // Test 10
        {1, 8},  // Test 11
        {6, 1},  // Test 12
        {10, 8}, // Test 13
        {9, 8}   // Test 14
    };

    // Declare and initialize results
    list<tuple<double, vector<int>>> results = {
        {11, vector<int>{4, 6, 3, 1}},  // Test 1
        {12, vector<int>{9, 8, 3}},     // Test 2
        {23, vector<int>{2, 4, 10}},    // Test 3
        {12, vector<int>{7, 8, 5}},     // Test 4
        {13, vector<int>{6, 3, 8}},     // Test 5
        {26, vector<int>{5, 4, 10}},    // Test 6
        {9, vector<int>{3, 2}},         // Test 7
        {0, vector<int>{8}},            // Test 8
        {14, vector<int>{9, 8, 3, 6}},  // Test 9
        {14, vector<int>{3, 6, 7}},     // Test 10
        {17, vector<int>{1, 3, 8}},     // Test 11
        {8, vector<int>{6, 3, 1}},      // Test 12
        {28, vector<int>{10, 4, 2, 8}}, // Test 13
        {1, vector<int>{9, 8}}          // Test 14
    };
    graph = loadDataset();

    cout << "Testing Dijkstra's algorithm:\n";

    auto pathIt = testPaths.begin();
    auto resultIt = results.begin();

    vector<int> path; // Resulting path of the algorithm
    double path_time; // Resulting time
    int testID = 1;
    // Iterate through testPaths and results simultaneously
    for (; pathIt != testPaths.end() && resultIt != results.end(); ++pathIt, ++resultIt)
    {
        const auto &[start, end] = *pathIt;

        path = modifiedDijkstra(graph, start, end, &path_time);
        if (make_tuple(path_time, path) == *resultIt)
        {
            cout << "\e[0;32mTest " << testID << " passed\e[0;37m\n";
        }
        else
        {
            cout << "\e[0;31m===========================Test " << testID << "===========================\n";
            cout << "Expected Value:\n"
                 << "Time: " << get<0>(*resultIt)
                 << "\n"
                 << "Path: ";
            printVector(get<1>(*resultIt));
            cout << "\nOutput Value:\n"
                 << "Time: " << path_time
                 << "\n"
                 << "Path: ";
            printVector(path);
            cout << "============================================================\n";

            cout << "\e[0;37m";
        }
        testID++;
    }
    return 0;
}
