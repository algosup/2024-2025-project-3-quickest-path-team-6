#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;

// Custom hash function for pair<int, int>
struct PairHash {
    size_t operator()(const pair<int, int>& p) const {
        return hash<int>{}(p.first) ^ (hash<int>{}(p.second) << 1);
    }
};

// Union-Find (Disjoint Set) with path compression and union by rank
class UnionFind {
public:
    unordered_map<int, int> parent;
    unordered_map<int, int> rank;

    int find(int node) {
        if (parent[node] != node) {
            parent[node] = find(parent[node]);
        }
        return parent[node];
    }

    void unite(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);
        if (rootA != rootB) {
            if (rank[rootA] > rank[rootB]) {
                parent[rootB] = rootA;
            } else if (rank[rootA] < rank[rootB]) {
                parent[rootA] = rootB;
            } else {
                parent[rootB] = rootA;
                rank[rootA]++;
            }
        }
    }

    void addNode(int node) {
        if (parent.find(node) == parent.end()) {
            parent[node] = node;
            rank[node] = 0;
        }
    }
};

// Function to add an edge to the adjacency list
void addEdge(unordered_map<int, vector<int>>& graph, int u, int v) {
    graph[u].push_back(v);
}

// Function to check for duplicates and build the graph
bool processFile(const string& filename, unordered_map<int, vector<int>>& graph, UnionFind& uf, bool& hasDuplicates) {
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Error: Could not open file." << endl;
        return false;
    }

    unordered_set<pair<int, int>, PairHash> edges;
    string line;
    size_t lineCount = 0;

    while (getline(inputFile, line)) {
        lineCount++;
        stringstream ss(line);
        vector<int> edge;
        string token;

        while (getline(ss, token, ',')) {
            edge.push_back(stoi(token));
        }

        if (edge.size() == 3) {  // Ensure each line has exactly 3 values
            pair<int, int> road = make_pair(min(edge[0], edge[1]), max(edge[0], edge[1]));

            // Check for duplicates
            if (edges.find(road) != edges.end()) {
                cerr << "Duplicate found: " << edge[0] << "," << edge[1] << endl;
                hasDuplicates = true;
            } else {
                edges.insert(road);
            }

            // Build the graph and union-find structure
            addEdge(graph, edge[0], edge[1]);
            uf.addNode(edge[0]);
            uf.addNode(edge[1]);
            uf.unite(edge[0], edge[1]);
        } else {
            cerr << "Error: Invalid line format: " << line << endl;
            return false;
        }

        if (lineCount % 100000 == 0) {
            cout << "Processed " << lineCount << " lines..." << endl;
        }
    }

    inputFile.close();
    return true;
}

// DFS function to check for cycles
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

// Function to check if the graph is acyclic
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

// Function to check if the graph is fully connected using Union-Find
bool isFullyConnected(UnionFind& uf) {
    if (uf.parent.empty()) {
        return false;
    }

    int representative = uf.find(uf.parent.begin()->first);
    for (const auto& entry : uf.parent) {
        if (uf.find(entry.first) != representative) {
            return false;
        }
    }
    return true;
}

int main() {
    string filename = "USA-roads.csv";
    unordered_map<int, vector<int>> graph;
    UnionFind uf;
    bool hasDuplicates = false;

    cout << "Select an option:\n";
    cout << "1. Check for duplicates\n";
    cout << "2. Check for loops\n";
    cout << "3. Check for full connectivity\n";
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;

    if (!processFile(filename, graph, uf, hasDuplicates)) {
        cerr << "Error while processing the file." << endl;
        return 1;
    }

    if (choice == 1) {
        if (hasDuplicates) {
            cout << "The file contains duplicate connections." << endl;
        } else {
            cout << "No duplicate connections found." << endl;
        }
    } else if (choice == 2) {
        if (isAcyclic(graph)) {
            cout << "The file is free of loops." << endl;
        } else {
            cout << "The file contains loops." << endl;
        }
    } else if (choice == 3) {
        if (isFullyConnected(uf)) {
            cout << "The graph is fully connected. Every node can reach every other node." << endl;
        } else {
            cout << "The graph is NOT fully connected. Some nodes are unreachable." << endl;
        }
    } else {
        cout << "Invalid choice." << endl;
        return 1;
    }

    return 0;
}
