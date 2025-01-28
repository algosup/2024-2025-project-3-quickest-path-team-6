#include <queue>
#include <algorithm>
#include "loadData.cpp"

using namespace std::chrono;

const int HIGHEST_ID = 23947347;

unordered_map<int, vector<Edge>> graph; // get the entire graph (need to be handled by the server)

vector<int> modifiedDijkstra(const unordered_map<int, vector<Edge>>& graph, int start, int end, int* time) {

    vector<int> path;

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