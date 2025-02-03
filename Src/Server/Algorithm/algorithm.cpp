#ifndef ALGORITHM_CPP
#define ALGORITHM_CPP
#include "../Includes/includes.hpp"

struct Edge {
    int from;
    int to;
    int time;
};

vector<Edge> heuristic_graph;
vector<Edge> data_graph;

void modifiedDijkstra(const vector<Edge>& graph, int start, int max_id) {
    // Min-heap: (total time, landmark ID)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    // Distance vector to store the shortest path time to each landmark
    vector<int> distances(max_id + 1, numeric_limits<int>::max());

    distances[start] = 0;
    pq.push({0, start});

    unordered_map<int, vector<Edge>> adj_list;
    for (const auto& edge : graph) {
        adj_list[edge.from].push_back(edge);
    }
    
    while (!pq.empty())
    {
        auto [current_time, current_node] = pq.top();
        pq.pop();
        
        for (const auto& edge : adj_list[current_node]) {
            int new_time = current_time + edge.time;

            if (new_time < distances[edge.to]) {
                distances[edge.to] = new_time;
                pq.push({new_time, edge.to});
            }
        }
    }
    // Add the path to the visited ones
    for (int i = 1; i < max_id + 1; i++){
        if (distances[i] == numeric_limits<int>::max()) {
            heuristic_graph.push_back({start, i, -1}); // -1 means no path found
        } else {
            heuristic_graph.push_back({start, i, distances[i]});
        }
    }
}

void aStarAlgorithm(){
    // TO-DO
}

#endif // !ALGORITHM_CPP