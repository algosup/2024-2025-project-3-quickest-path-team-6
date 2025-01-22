#include <queue>
#include <unordered_map>
#include <limits>
#include "loadData.cpp"
#include <chrono>
#include <cstdlib>
#include <iomanip>
#include <algorithm>

using namespace std::chrono;

const int HIGHEST_ID = 23947347;

unordered_map<int, vector<Edge>> graph; // get the entire graph (need to be handled by the server)

vector<int> modifiedDijkstra(const unordered_map<int, vector<Edge>>& graph, int start, int end, double* time) {

    vector<int> path;

    if (start == end){
        path.push_back(end);
        reverse(path.begin(), path.end());
        return path;
    }

    // Min-heap: (total time, landmark ID)
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<>> pq;

    // Distance vector to store the shortest path time to each landmark
    vector<double> distances(HIGHEST_ID + 1, numeric_limits<double>::infinity());
    vector<int> previous(HIGHEST_ID + 1, -1); // To reconstruct the path

    distances[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [current_time, current_node] = pq.top();
        pq.pop();

        if (current_node == end) {
            *time = current_time;
            break; // Early exit if we reach the destination
        }

        if (graph.find(current_node) == graph.end()) {
            continue; // Skip nodes with no outgoing edges
        }

        for (const auto& edge : graph.at(current_node)) {
            double new_time = current_time + edge.time;

            if (new_time < distances[edge.to]) {
                distances[edge.to] = new_time;
                previous[edge.to] = current_node;
                pq.push({new_time, edge.to});
            }
        }
    }

    // Reconstruct the path
    for (int at = end; at != -1; at = previous[at]) {
        path.push_back(at);
        if (at == start) break; // Reached the start point
    }

    reverse(path.begin(), path.end());
    return path;
}

string urlEncode(const string& str) {
    ostringstream encoded;
    for (unsigned char c : str) {
        if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~') {
            encoded << c;
        } else {
            encoded << '%' << setw(2) << setfill('0') << hex << (int)c;
        }
    }
    return encoded.str();
}

void sendRequest(int start, int end, string fileFormat) {
    cout << "Calculating shortest path..." << endl << endl;
    auto timeStart = high_resolution_clock::now(); // get time

    // Prepare the API request (building the URL)
    string source = to_string(start);
    string destination = to_string(end);
    string format = fileFormat; // or you can set this based on user input

    // URL-encode the source, destination, and format values
    string encodedSource = urlEncode(source);
    string encodedDestination = urlEncode(destination);
    string encodedFormat = urlEncode(format);

    // Construct the full curl command with quotes to handle spaces/special characters
    string api_url = "curl \"http://localhost:8080/route?source=" + encodedSource + "&destination=" + encodedDestination + "&format=" + encodedFormat + "\"";

    // Make an HTTP GET request to the API
    int result = system(api_url.c_str());

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - timeStart); // get task duration
    if (duration.count() > 2000) {
        cout << endl << "Path calculated in " << duration.count()/1000 << " seconds." << endl;
    } else {
        cout << endl << "Path calculated in " << duration.count() << " milliseconds." << endl;
    }
    
}
