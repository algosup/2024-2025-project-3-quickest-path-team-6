#ifndef VALIDATE_CSV
#define VALIDATE_CSV

#include "../Includes/includes.hpp"
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
bool processFile(const string& file_name, unordered_map<int, vector<int>>& graph, UnionFind& uf, bool& has_duplicates) {

    ifstream file(file_name);
    if (!file.is_open()) {
        file.open(file_name);
    }
    unordered_set<pair<int, int>, PairHash> edges;
    string line;
    size_t line_count = 0;
    
    while (getline(file, line)) {
        line_count++;
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
                has_duplicates = true;
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

    }

    cout << endl;
    file.close();
    return true;
}
// DFS function to check for cycles
bool hasCycle(int node, unordered_map<int, vector<int>>& graph, unordered_set<int>& visited, unordered_set<int>& recursion_stack) {
    visited.insert(node);
    recursion_stack.insert(node);
    for (int neighbor : graph[node]) {
        if (recursion_stack.count(neighbor)) {
            return true;
        }
        if (!visited.count(neighbor) && hasCycle(neighbor, graph, visited, recursion_stack)) {
            return true;
        }
    }
    recursion_stack.erase(node);
    return false;
}
// Function to check if the graph is acyclic
bool isAcyclic(unordered_map<int, vector<int>>& graph) {
    unordered_set<int> visited;
    unordered_set<int> recursion_stack;
    for (const auto& entry : graph) {
        int node = entry.first;
        if (!visited.count(node) && hasCycle(node, graph, visited, recursion_stack)) {
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

// Ensure `main` is properly defined when compiling standalone
#ifdef STANDALONE
// Function to clear the console screen based on OS
void clearScreen(){
    #if defined _WIN32
        system("cls"); // Windows
    #elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__) || defined (__APPLE__)
        system("clear"); // Linux/macOS
    #endif
}

/*
    Checks if a given string represents a valid integer
    This functions returns true if the string represents an integer, false otherwise

    Parameters: 
        - input, the string to check
*/
bool isInteger(const std::string &input) {
    int number;
    size_t i = 0;

    // Ensure all characters are digits (does not handle negative numbers correctly)
    while (i < input.size()) {
        if (!std::isdigit(input[i])) return false;
        i++;
    }

    // Try converting string to integer
    try {
        number = std::stoi(input);
    } catch (const std::out_of_range &) {
        return false; // Handle cases where the number is too large
    }

    return true; // String is a valid integer
}

// main function to be executed on standalone
int main() {
    string file_name;
    string constructed_path_str_dbg = "../../Src";
    string ext(".csv");
    for (auto& p : fs::recursive_directory_iterator(constructed_path_str_dbg))
    {
        if (p.path().extension() == ext){
            cout << "Opening " << p << '\n' << endl;
            file_name = p.path().string();
            break;
        }
    }
    unordered_map<int, vector<int>> graph;
    UnionFind uf;
    bool has_duplicates = false;
    std::string choice;
    int input;
    bool error_detected = false;

    while (true) {
        clearScreen();

        if (error_detected)
            cout << "Invalid input. Please enter 1, 2, or 3.\n" << endl;
        cout << "Select an option:\n";
        cout << "1. Check for duplicates\n";
        cout << "2. Check for loops\n";
        cout << "3. Check for full connectivity\n";
        cout << "Enter your choice: ";
        
        getline(cin, choice); // Read input from the user

        if (choice == "") {
            error_detected = true;
        } else if (isInteger(choice)) {
            input = std::stoi(choice);
            if (input >= 1 && input <= 3) {
                break; // Valid input, exit loop
                error_detected = false;
            } else {
                error_detected = true;
            }
        } else {
            error_detected = true;
        }
    }

    clearScreen();
    cout << "Processing..." << endl;

    if (!processFile(file_name, graph, uf, has_duplicates)) {
        cerr << "Error while processing the file." << endl;
        return 1;
    }
    switch (input) {
        case 1:
            cout << (has_duplicates ? "The file contains duplicate connections." : "No duplicate connections found.") << endl;
            break;
        case 2:
            cout << (isAcyclic(graph) ? "The file is free of loops." : "The file contains loops.") << endl;
            break;
        case 3:
            cout << (isFullyConnected(uf) ? "The graph is fully connected. Every node can reach every other node." : "The graph is NOT fully connected. Some nodes are unreachable.") << endl;
            break;
    }
    return 0;
}
#endif

#endif // !VALIDATE_CSV