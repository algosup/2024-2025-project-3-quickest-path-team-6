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


int min_id = 1, max_id = 0;
vector<Edge> visited_paths;
unordered_map<int, vector<Edge>> data_graph;

void modifiedDijkstra(const unordered_map<int, vector<Edge>>& data_graph, int start) {

    vector<int> path;
    int visited_node_count = 1;
    int time = 0;

    // Min-heap: (total time, landmark ID)
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<>> pq;

    // Distance vector to store the shortest path time to each landmark
    vector<double> distances(max_id + 1, numeric_limits<double>::infinity());
    vector<int> previous(max_id + 1, -1); // To reconstruct the path

    distances[start] = 0;
    pq.push({0, start});

    while (visited_node_count <= 10)
    {
        while (!pq.empty())
        {
            if (visited_node_count > 10)
                break;
            auto [current_time, current_node] = pq.top();
            pq.pop();

            if (data_graph.find(current_node) == data_graph.end()) {
                continue; // Skip nodes with no outgoing edges
            }

            for (const auto& edge : data_graph.at(current_node)) {
                double new_time = current_time + edge.time;

                if (new_time < distances[edge.to]) {
                    distances[edge.to] = new_time;
                    previous[edge.to] = current_node;
                    pq.push({new_time, edge.to});
                }

            }

            // Add the path to the visited ones
            Edge edge_to_add = {start, current_node, current_time};

            if (!(find(visited_paths.begin(), visited_paths.end(), edge_to_add) != visited_paths.end()) && edge_to_add.to != start)
            {
                visited_paths.push_back(edge_to_add);
                visited_node_count++;
            }

        }
    }
}

void aStarAlgorithm(){

}

#endif // !ALGORITHM_CPP