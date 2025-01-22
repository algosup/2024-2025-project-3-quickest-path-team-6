#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <functional>

using namespace std;

// Custom hash function for pair<int, int>
struct PairHash {
    template <typename T1, typename T2>
    size_t operator()(const pair<T1, T2>& p) const {
        return hash<T1>{}(p.first) ^ (hash<T2>{}(p.second) << 1);
    }
};

// Function to create an ordered pair for edge uniqueness
pair<int, int> createEdgePair(int a, int b) {
    return (a < b) ? make_pair(a, b) : make_pair(b, a);
}

// Function to add an edge to the adjacency list
void addEdge(unordered_map<int, vector<int>>& graph, int u, int v) {
    graph[u].push_back(v);
}

// Function to check for duplicates and build the graph simultaneously
bool processFile(const string& filename, unordered_map<int, vector<int>>& graph) {
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Error: Could not open file." << endl;
        return false;
    }

    unordered_set<pair<int, int>, PairHash> edges; // Store unique edges
    string line;
    size_t lineCount = 0;
    size_t duplicateCount = 0;

    while (getline(inputFile, line)) {
        lineCount++;

        // Parse the line and build the graph
        stringstream ss(line);
        string token;
        vector<int> edge;

        while (getline(ss, token, ',')) {
            edge.push_back(stoi(token));
        }

        if (edge.size() == 3) { // Ensure each line has exactly 3 values
            auto road = createEdgePair(edge[0], edge[1]);

            if (edges.find(road) != edges.end()) {
                duplicateCount++;
            } else {
                edges.insert(road);
                addEdge(graph, edge[0], edge[1]);
            }
        } else {
            cerr << "Error: Invalid line format at line " << lineCount << ": " << line << endl;
        }

        // Periodic progress display
        if (lineCount % 100000 == 0) {
            cout << "Processed " << lineCount << " lines..." << endl;
        }
    }

    inputFile.close();

    cout << "Total lines processed: " << lineCount << endl;
    cout << "Duplicate connections detected: " << duplicateCount << endl;
    return true;
}

// Function to perform DFS and check for cycles
bool hasCycle(int node, unordered_map<int, vector<int>>& graph, unordered_set<int>& visited, unordered_set<int>& recursionStack) {
    visited.insert(node);
    recursionStack.insert(node);

    for (int neighbor : graph[node]) {
        if (recursionStack.count(neighbor)) {
            return true;
        }
        if (!visited.count(neighbor) && hasCycle(neighbor, graph, visited, recursionStack)) {
            return true;
        }
    }

    recursionStack.erase(node);
    return false;
}

// Function to check if the graph has cycles
bool isAcyclic(unordered_map<int, vector<int>>& graph) {
    unordered_set<int> visited;
    unordered_set<int> recursionStack;

    for (const auto& entry : graph) {
        int node = entry.first;
        if (!visited.count(node) && hasCycle(node, graph, visited, recursionStack)) {
            return false;
        }
    }
    return true;
}

int main() {
    string filename = "USA-roads.csv";
    unordered_map<int, vector<int>> graph;

    // Process the file: check for duplicates and build the graph
    if (!processFile(filename, graph)) {
        cerr << "Error while processing the file." << endl;
        return 1;
    }

    // Check if the graph is acyclic
    if (isAcyclic(graph)) {
        cout << "The file is free of loops." << endl;
    } else {
        cout << "The file contains loops." << endl;
    }

    return 0;
}
