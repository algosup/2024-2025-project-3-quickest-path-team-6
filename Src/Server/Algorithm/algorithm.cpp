#ifndef ALGORITHM_CPP
#define ALGORITHM_CPP
#include "../Includes/includes.hpp"

struct Edge {
    int from;
    int to;
    double time;

    bool operator==(const Edge& other) const {
        return from == other.from && to == other.to && time == other.time;
    }
};

vector<Edge> visited_paths;
vector<Edge> data_graph;

void modifiedDijkstra(const vector<Edge>& graph, int start, int max_id) {

    int visited_node_count = 1;

    // Min-heap: (total time, landmark ID)
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<>> pq;

    // Distance vector to store the shortest path time to each landmark
    vector<double> distances(max_id + 1, numeric_limits<double>::infinity());

    distances[start] = 0;
    pq.push({0, start});
    
    while (!pq.empty())
    {
        if (visited_node_count > 1000)
            break;

        auto [current_time, current_node] = pq.top();
        pq.pop();
        
        for (const auto& edge : graph) { 
            if (edge.from == current_node) {  // Find outgoing edges
                double new_time = current_time + edge.time;

                if (new_time < distances[edge.to]) {
                    distances[edge.to] = new_time;
                    visited_node_count++;
                    pq.push({new_time, edge.to});
                }
            }
        }
    }
    // Add the path to the visited ones
    for (int i = 1; i < max_id + 1; i++){
        visited_paths.push_back({start, i, distances[i]});
    }
}

void aStarAlgorithm(){
    // TO-DO
}

#endif // !ALGORITHM_CPP