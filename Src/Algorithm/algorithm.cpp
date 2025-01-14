#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <limits>
#include "loadData.cpp"

using namespace std;
#include <chrono>
using namespace std::chrono;

vector<int> modifiedDijkstra(const unordered_map<int, vector<Edge>>& graph, int start, int end) {
    // Min-heap: (total time, landmark ID)
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<>> pq;

    // Distance map to store the shortest path time to each landmark
    unordered_map<int, double> distances;
    unordered_map<int, int> previous; // To reconstruct the path

    for (const auto& node : graph) {
        distances[node.first] = numeric_limits<double>::infinity();
    }

    distances[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [current_time, current_node] = pq.top();
        pq.pop();

        if (current_node == end) break; // Early exit if we reach the destination

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
    vector<int> path;
    for (int at = end; at != 0; at = previous[at]) {
        path.push_back(at);
        if (at == start) break; // Reached the start point
    }

    reverse(path.begin(), path.end());
    return path;
}

void algorithm(int start, int end) {

    unordered_map<int, vector<Edge>> graph = loadDataset(); // get the entire graph (need to be handled by the server)

    cout << "Calculating shortest path..." << endl;
    auto timeStart = high_resolution_clock::now(); // get time
    vector<int> path = modifiedDijkstra(graph, start, end);


    if (path.empty() || path.front() != start) {
        cout << "No path found between " << start << " and " << end << "!" << endl;
    } else {
        cout << "Shortest path from " << start << " to " << end << ":" << endl;
        for (int landmark : path) {
            cout << landmark << " ";
        }
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<seconds>(stop - timeStart); // get task duration
        cout << endl << "Path calculated in " << duration.count() << " seconds." << endl;
    }
}
