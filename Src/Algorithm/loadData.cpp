#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;
#include <chrono>
using namespace std::chrono;

struct Edge {
    int to;
    double time;
};

unordered_map<int, vector<Edge>> loadDataset() {
    unordered_map<int, vector<Edge>> graph;
    string filename = "USA-roads.csv";

    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
        exit(EXIT_FAILURE);
    }

    cout << "Loading dataset..." << endl;
    
    auto start = high_resolution_clock::now(); // get time

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        int from, to;
        double time;
        char comma;
        ss >> from >> comma >> to >> comma >> time;

        graph[from].push_back({to, time});
        graph[to].push_back({from, time}); // Bidirectional connection
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(stop - start); // get task duration

    cout << "Dataset loaded successfully in " << duration.count() << " seconds!" << endl;
    return graph;
}
