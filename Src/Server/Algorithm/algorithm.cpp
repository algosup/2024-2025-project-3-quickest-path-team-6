#ifndef ALGORITHM_CPP
#define ALGORITHM_CPP
#include "../Includes/includes.hpp"

struct Edge {
    int from;
    int to;
    int time;

    bool operator==(const Edge& other) const {
        return from == other.from && to == other.to && time == other.time;
    }
};


int min_id = 1, max_id = 0;
vector<Edge> visited_paths;
vector<Edge> data_graph;

void modifiedDijkstra(const vector<Edge>& graph, int start) {

    int visited_node_count = 1;

    // Min-heap: (total time, landmark ID)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    // Distance vector to store the shortest path time to each landmark
    vector<int> distances(max_id + 1, numeric_limits<int>::infinity());
    vector<int> previous(max_id + 1, -1); // To reconstruct the path

    distances[start] = 0;
    pq.push({0, start});
    
    while (!pq.empty())
    {
        if (visited_node_count > max_id)
            break;

        auto [current_time, current_node] = pq.top();
        pq.pop();

        bool has_neighbors = false;
        
        for (const auto& edge : graph) { 
            if (edge.from == current_node) {  // Find outgoing edges
                has_neighbors = true;
                int new_time = current_time + edge.time;

                if (new_time < distances[edge.to]) {
                    distances[edge.to] = new_time;
                    previous[edge.to] = current_node;
                    pq.push({new_time, edge.to});
                }
            }
        }

        if (!has_neighbors) {
            continue; // Skip nodes with no outgoing edges
        }

        visited_node_count++;

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