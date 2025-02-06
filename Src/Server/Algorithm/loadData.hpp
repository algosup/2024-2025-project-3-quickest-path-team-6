#ifndef LOADDATA_HPP
#define LOADDATA_HPP

#include "../Includes/includes.hpp"
#include "../DataValidation/validateCsv.cpp"  // Adjust if needed

using namespace std;
using namespace std::chrono;
namespace fs = std::filesystem;

// -----------------------------------------------------------------------------
// Global Variables
// -----------------------------------------------------------------------------
inline int min_id = 1, max_id = 0;      // Track minimum and maximum node IDs encountered.
inline ifstream file;                   // File stream for reading CSV data.
inline bool ended = false;              // Flag indicating completion of data loading.
inline bool datasetLoaded = false;              // Flag indicating completion of graph construction.
inline const int INF = numeric_limits<int>::max();
inline vector<string> found_paths = {};

// -----------------------------------------------------------------------------
// Edge Structure
// -----------------------------------------------------------------------------
struct Edge {  
    int to;  
    int time;  
};

// -----------------------------------------------------------------------------
// Graph Data Structures
// -----------------------------------------------------------------------------
// The graph is stored in two maps; landmarks will be computed dynamically.
inline unordered_map<int, vector<Edge>> data_graph;
// Replace the unordered_map version of landmark distances with a vector-of-vectors.
// For each landmark (in the same order as in the 'landmarks' vector), the inner vector
// is of size (max_id+1) where index i gives the distance from that landmark to node i.
inline vector<vector<int>> landmarkDistancesVector;
// The landmarks vector will be computed dynamically using farthest-point sampling.
inline vector<int> landmarks;

// -----------------------------------------------------------------------------
// Utility Function
// -----------------------------------------------------------------------------
inline void wait_ms(int milliseconds) {
#ifdef _WIN32
    Sleep(milliseconds);
#else
    usleep(milliseconds * 1000);
#endif
}

// -----------------------------------------------------------------------------
// Forward Declarations
// -----------------------------------------------------------------------------
inline void getData(const string& file_name);
inline void computeDynamicLandmarks(int num);
inline void computeLandmarkDistances();
inline void verifyData(const string& file_name);
inline bool loadDataset();
inline void loadingCat(string s);

// -----------------------------------------------------------------------------
// Function Definitions
// -----------------------------------------------------------------------------

/*
    Checks if a given string represents a valid integer
    This functions returns true if the string represents an integer, false otherwise

    Parameters: 
        - input, the string to check
*/
bool isInteger(const string &input) {
    int number;
    size_t i = 0;

    // Ensure all characters are digits (does not handle negative numbers correctly)
    while (i < input.size()) {
        if (!isdigit(input[i])) return false;
        i++;
    }

    // Try converting string to integer
    try {
        number = stoi(input);
    } catch (const out_of_range &) {
        return false; // Handle cases where the number is too large
    }

    return true; // String is a valid integer
}

// Function to clear the console screen based on OS
void clearScreen(){
    #if defined _WIN32
        system("cls"); // Windows
    #elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__) || defined (__APPLE__)
        system("clear"); // Linux/macOS
    #endif
}

inline void getData(const string& file_name) {
    if (!file.is_open()) {
        file.open(file_name);
    }
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        int from, to, time;
        char comma;
        if (!(ss >> from >> comma >> to >> comma >> time))
            continue;
        if (from > max_id) max_id = from;
        if (to > max_id) max_id = to;
        data_graph[from].push_back({to, time});
        data_graph[to].push_back({from, time});
    }
    datasetLoaded = true;
    computeDynamicLandmarks(8);
    computeLandmarkDistances();
    ended = true;
}

/*
 * computeDynamicLandmarks:
 * Uses farthest-point sampling to choose 'num' landmarks dynamically.
 */
inline void computeDynamicLandmarks(int num = 8) {
    landmarks.clear();
    if (data_graph.empty()) return;
    // Choose the first landmark arbitrarily (the first key in data_graph)
    int first = data_graph.begin()->first;
    landmarks.push_back(first);
    vector<int> minDistances(max_id + 1, INF);
    {
        // Run Dijkstra from the first landmark to initialize minDistances.
        vector<int> dist(max_id + 1, INF);
        using NodeEntry = pair<int, int>;
        auto cmp = [](const NodeEntry &a, const NodeEntry &b){ return a.first > b.first; };
        priority_queue<NodeEntry, vector<NodeEntry>, decltype(cmp)> pq(cmp);
        dist[first] = 0;
        pq.push({0, first});
        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d != dist[u]) continue;
            if (data_graph.find(u) == data_graph.end()) continue;
            for (auto &edge : data_graph[u]) {
                int v = edge.to;
                int nd = d + edge.time;
                if (nd < dist[v]) {
                    dist[v] = nd;
                    pq.push({nd, v});
                }
            }
        }
        for (int i = 0; i < (int)minDistances.size(); i++) {
            minDistances[i] = dist[i];
        }
    }
    
    // Iteratively select additional landmarks.
    for (int i = 1; i < num; i++) {
        int candidate = -1;
        int candidateDist = -1;
        for (auto &p : data_graph) {
            int node = p.first;
            if (minDistances[node] > candidateDist) {
                candidate = node;
                candidateDist = minDistances[node];
            }
        }
        if (candidate == -1) break;
        landmarks.push_back(candidate);
        
        // Run Dijkstra from the new candidate.
        vector<int> distCandidate(max_id + 1, INF);
        using NodeEntry = pair<int, int>;
        auto cmp = [](const NodeEntry &a, const NodeEntry &b){ return a.first > b.first; };
        priority_queue<NodeEntry, vector<NodeEntry>, decltype(cmp)> pq(cmp);
        distCandidate[candidate] = 0;
        pq.push({0, candidate});
        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d != distCandidate[u]) continue;
            if (data_graph.find(u) == data_graph.end()) continue;
            for (auto &edge : data_graph[u]) {
                int v = edge.to;
                int nd = d + edge.time;
                if (nd < distCandidate[v]) {
                    distCandidate[v] = nd;
                    pq.push({nd, v});
                }
            }
        }
        // Update minDistances.
        for (int j = 0; j < (int)minDistances.size(); j++) {
            if (distCandidate[j] < minDistances[j])
                minDistances[j] = distCandidate[j];
        }
    }
}

/*
 * computeLandmarkDistances:
 * For each landmark in the global 'landmarks' vector, compute the shortest-path
 * distances from that landmark to every node in data_graph using Dijkstra's algorithm.
 * The results are stored in landmarkDistancesVector.
 */
inline void computeLandmarkDistances() {
    landmarkDistancesVector.clear();
    for (int landmark : landmarks) {
        vector<int> distances(max_id + 1, INF);
        using NodeEntry = pair<int, int>;
        auto cmp = [](const NodeEntry &a, const NodeEntry &b){ return a.first > b.first; };
        priority_queue<NodeEntry, vector<NodeEntry>, decltype(cmp)> pq(cmp);
        if (landmark > max_id) continue;  // Safety check.
        distances[landmark] = 0;
        pq.push({0, landmark});
        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d != distances[u]) continue;
            if (data_graph.find(u) == data_graph.end()) continue;
            for (const auto &edge : data_graph[u]) {
                int v = edge.to;
                int nd = d + edge.time;
                if (nd < distances[v]) {
                    distances[v] = nd;
                    pq.push({nd, v});
                }
            }
        }
        landmarkDistancesVector.push_back(distances);
    }
}

/*
 * verifyData:
 * Checks the integrity of the CSV file using functions assumed to be defined in validateCsv.cpp.
 */
inline void verifyData(const string& file_name) {
    unordered_map<int, vector<int>> graphValidation;
    UnionFind uf;
    bool has_duplicates = false;
    if (!processFile(file_name, graphValidation, uf, has_duplicates)) {
        cerr << "Error while processing the file." << "\r" << flush;
        return;
    }
    if (isAcyclic(graphValidation))
        cout << "The file is free of loops." << endl;
    else
        cout << "The file contains loops." << endl;
    if (isFullyConnected(uf))
        cout << "The graph is fully connected. Every node can reach every other node." << endl;
    else
        cout << "The graph is NOT fully connected. Some nodes are unreachable." << endl;
    if (has_duplicates)
        cout << "The file contains duplicate connections." << endl;
    else
        cout << "No duplicate connections found." << endl;
    cout << endl << endl;
}
/**
 * @brief getCsvFile returns the name of the chosen .csv file to analyze. 
 * This function checks all possible .csv file in the Src directory, and let the user choose which one he wants
 */
string getCsvFile(){
    string file;
    string path = "../../Src";
    string ext(".csv");
    bool file_found = false;

    // First, check the current folder
    for (const auto& p : fs::directory_iterator(path)) {
        if (p.is_regular_file() && p.path().extension() == ext) {
            found_paths.push_back(p.path().string());
            file_found = true;
        }
    }
    // If not found, check subfolders
    if (!file_found) {
        for (const auto& p : fs::recursive_directory_iterator(path)) {
            if (p.is_regular_file() && p.path().extension() == ext) {
                found_paths.push_back(p.path().string());
                file_found = true;
            }
        }
    }
    // If no csv found, return false
    if (!file_found) {
        return "File not Found";
    } else if (found_paths.size() > 1) {
        bool found = false;
        while (found == false){
            clearScreen();
            cout << "Files found:" << endl;
            int i = 1;
            for (const string& path : found_paths) {
                cout << i << ". " << path << endl;
                i++;
            }

            cout << endl << "Choose the .csv file: ";
            i = 1;
            string input;
            
            getline(cin, input); // Read input from the user


            if (input != "" && isInteger(input)){
                for (const string& path : found_paths) {
                    if (stoi(input) == i) {
                        clearScreen();
                        file = path;
                        cout << "\nOpening " << path << endl << endl;
                        found = true;
                        break;
                    }
                    i++;
                }
            }
        }
    } else {
        clearScreen();
        file = found_paths[0];
        cout << "Opening " << file << endl << endl;
    }

    return file;
}

/*
 * loadDataset:
 * Loads a CSV file from "../../Src", builds the data_graph, displays a loading animation,
 * computes dynamic landmarks using farthest-point sampling, and then computes landmark distances.
 * Returns the constructed data_graph.
 */
inline bool loadDataset() {
    auto start = high_resolution_clock::now();
    string file_name = getCsvFile();

    if (file_name == "File not Found"){
        return false;
    }
    
    thread getDataThread(getData, file_name);
    thread loadingCatThread(loadingCat, "Loading the file");
    getDataThread.join();
    loadingCatThread.join();

    file.close();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(stop - start);
    cout << "\nLoaded in " << duration.count() << " seconds!\n"
         << "Available landmarks from " << min_id << " to " << max_id << "\n" << endl;

    cout << "Graph loaded successfully." << endl;
    return true;
}

/*
 * initServer:
 * Loads the dataset and builds the graph, returning true if successful.
 */
inline bool initServer() {
    try {
        return loadDataset();
    } catch (const exception &e) {
        cerr << "Error during graph creation: " << e.what() << endl;
        return false;
    } catch (...) {
        cerr << "Unknown error during graph creation." << endl;
        return false;
    }
}

// -----------------------------------------------------------------------------
// Loading Cat Animation (Moved to the Bottom)
// -----------------------------------------------------------------------------
inline void loadingCat(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        cout << " ";
    }
    
    cout << "    /\\_/\\\n" << flush;
    while(!ended){
        cout << s << ".. / o.o \\" << "\r" << flush;
        wait_ms(1000);
        cout << s << ".. / -.- \\" << "\r" << flush;
        wait_ms(150);
        if (datasetLoaded && s != "Setting the data"){
            s = "Setting the data";
        }
    }
    cout << "Dataset loaded!    / ^.^ \\" << "\r" << flush;
}

#endif // LOADDATA_HPP
