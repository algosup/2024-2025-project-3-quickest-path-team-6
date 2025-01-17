#include <queue>
#include <unordered_map>
#include <limits>
#include "loadData.cpp"
#include "../Headers/Formatting/convertionJson.hpp"
#include "../Headers/Formatting/convertionXml.hpp"
#include <chrono>

using namespace std::chrono;
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

        if (current_node == end) {
            *time = current_time;
            break; // Early exit if we reach the destination
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
    for (int at = end; at != 0; at = previous[at]) {
        
        path.push_back(at);
        if (at == start) break; // Reached the start point
    }

    reverse(path.begin(), path.end());
    return path;
}

double algorithm(int start, int end) {
    cout << "Calculating shortest path..." << endl;
    double pathTime;
    auto timeStart = high_resolution_clock::now(); // get time
    vector<int> path = modifiedDijkstra(graph, start, end, &pathTime);


    if (path.empty() || path.front() != start) {
        cout << endl << "No path found between " << start << " and " << end << "!" << endl;
    } else {
        cout << endl << "Shortest path from " << start << " to " << end << ":" << endl;
        convertIntoJson(path);
        convertIntoXml(path);

        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - timeStart); // get task duration
        if (duration.count() > 2000) {
            cout << endl << "Path calculated in " << duration.count()/1000 << " seconds." << endl;
        } else {
            cout << endl << "Path calculated in " << duration.count() << " milliseconds." << endl;
        }
        
    }

    return pathTime;
}
