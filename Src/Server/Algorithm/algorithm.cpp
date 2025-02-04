#ifndef ALGORITHM_CPP
#define ALGORITHM_CPP
#include "../Includes/includes.hpp"

struct Edge {
    int from;
    int to;
    int time;
};

unordered_map<int, vector<Edge>> heuristic_graph;
unordered_map<int, vector<Edge>> data_graph;
vector<int> global_nodes = {};

int modifiedDijkstra(const unordered_map<int, vector<Edge>>& graph, int start, int max_id) {
    int farthest = 0;
    int farthest_distance = 0;
    // Min-heap: (total time, landmark ID)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    // Distance vector to store the shortest path time to each landmark
    vector<int> distances(max_id + 1, numeric_limits<int>::max());

    distances[start] = 0;
    pq.push({0, start});
    
    while (!pq.empty())
    {
        auto [current_time, current_node] = pq.top();
        pq.pop();
        
        for (const auto& edge : data_graph[current_node]) {
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
            heuristic_graph[start].push_back({start, i, -1}); // -1 means no path found
        } else {
            heuristic_graph[start].push_back({start, i, distances[i]});
        }
        for (const int& node : global_nodes) {
            if (distances[i] > farthest_distance && farthest != node) {
                farthest = i;
                farthest_distance = distances[i];
            }
        }
        
    }
    return farthest;
}

void aStarAlgorithm(){
    // TO-DO
}

#endif // !ALGORITHM_CPP