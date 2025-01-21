#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// Function to add an edge to the adjacency list
void addEdge(unordered_map<int, vector<int>>& graph, int u, int v) {
    graph[u].push_back(v);
}

// Function to perform DFS and check for cycles
bool hasCycle(int node, unordered_map<int, vector<int>>& graph, unordered_set<int>& visited, unordered_set<int>& recursionStack) {
    // Mark the current node as visited and add it to the recursion stack
    visited.insert(node);
    recursionStack.insert(node);

    // Visit all neighbors
    for (int neighbor : graph[node]) {
        // If the neighbor is in the recursion stack, a cycle is detected
        if (recursionStack.count(neighbor)) {
            return true;
        }
        // If the neighbor is not visited, recursively check for cycles
        if (!visited.count(neighbor) && hasCycle(neighbor, graph, visited, recursionStack)) {
            return true;
        }
    }

    // Remove the current node from the recursion stack
    recursionStack.erase(node);
    return false;
}

// Function to check if the graph has cycles
bool isAcyclic(unordered_map<int, vector<int>>& graph) {
    unordered_set<int> visited;
    unordered_set<int> recursionStack;

    // Perform DFS for each unvisited node
    for (const auto& entry : graph) {
        int node = entry.first;
        if (!visited.count(node) && hasCycle(node, graph, visited, recursionStack)) {
            return false;
        }
    }

    return true;
}

int main() {
    ifstream inputFile("USA-roads.csv");
    if (!inputFile.is_open()) {
        cerr << "Error: Could not open file." << endl;
        return 1;
    }

    unordered_map<int, vector<int>> graph;
    string line;

    // Parse the CSV file
    while (getline(inputFile, line)) {
        stringstream ss(line);
        string token;
        vector<int> edge;

        while (getline(ss, token, ',')) {
            edge.push_back(stoi(token));
        }

        if (edge.size() == 3) { // Ensure each line has exactly 3 values
            addEdge(graph, edge[0], edge[1]);
        } else {
            cerr << "Error: Invalid line format: " << line << endl;
            return 1;
        }
    }

    inputFile.close();

    // Check if the graph is acyclic
    if (isAcyclic(graph)) {
        cout << "The file is free of loops." << endl;
    } else {
        cout << "The file contains loops." << endl;
    }

    return 0;
}
