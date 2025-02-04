#include "../Includes/includes.hpp"
#include "loadData.hpp"

using namespace std;
using namespace std::chrono;

/*
 * ALT_heuristic:
 * -------------------------------
 * This function computes the ALT (A*, Landmarks, Triangle inequality) heuristic value for a given node.
 *
 * The heuristic is computed using precomputed distances from selected landmarks:
 *   h(n) = max(|d(landmark, target) - d(landmark, n)|)
 *
 * It iterates over each landmark in the global 'landmarks' vector.
 * If both the distance from the landmark to the current node and from the landmark to the target are known,
 * it calculates the absolute difference between these two distances.
 * The maximum of these differences is returned as the heuristic estimate.
 *
 * Parameters:
 *   - node: The current node for which the heuristic is being computed.
 *   - target: The destination node.
 *
 * Returns:
 *   - An integer representing the heuristic (lower-bound estimate) from the node to the target.
 */
int ALT_heuristic(int node, int target) {
    int bestEstimate = 0;
    // Iterate over each landmark's distance vector.
    for (const auto &distances : landmarkDistancesVector) {
        // We assume that each 'distances' is a vector<int> of size (max_id + 1)
        // and that INF represents an unreachable distance.
        if (distances[node] != INF && distances[target] != INF) {
            int estimatedDist = abs(distances[target] - distances[node]);
            bestEstimate = max(bestEstimate, estimatedDist);
        }
    }
    return bestEstimate;
}


/*
 * bidirectionalDijkstra:
 * -------------------------------
 * This function performs a bidirectional search using an ALT-accelerated Dijkstra's algorithm.
 * It simultaneously searches from the start node (forward search) and from the end node (backward search),
 * using the ALT heuristic to guide the search.
 *
 * The algorithm uses two priority queues (one for each search direction). The priority value for a node
 * is defined as (current distance + heuristic estimate).
 *
 * During the search, the function keeps track of:
 *   - The best known path length (bestPath)
 *   - A meeting point (meetingPoint) where both searches have met.
 *
 * The search loop terminates when the sum of the smallest estimates from both directions is greater than or equal
 * to the best path found so far.
 *
 * After termination, the function reconstructs the final path:
 *   1. Reconstruct the forward path from the start node to the meeting point using the 'prevF' map.
 *   2. Reconstruct the backward path from the meeting point to the end node using the 'prevB' map.
 *   3. Concatenate both paths to form the complete path.
 *
 * Parameters:
 *   - graph: The full graph represented as an unordered_map from node IDs to vectors of Edge structures.
 *   - start: The starting node ID.
 *   - end: The destination node ID.
 *   - time: A pointer to an integer where the total travel time (cost) of the computed path will be stored.
 *
 * Returns:
 *   - A vector of integers representing the sequence of node IDs on the computed path.
 *     If no path is found, an empty vector is returned.
 */
vector<int> bidirectionalDijkstra(const unordered_map<int, vector<Edge>>& graph, int start, int end, int* time) {
    // Create vectors for distances, predecessors, and visited flags.
    vector<int> distF(max_id + 1, INF), distB(max_id + 1, INF);
    vector<int> prevF(max_id + 1, -1), prevB(max_id + 1, -1);
    vector<bool> visitedF(max_id + 1, false), visitedB(max_id + 1, false);
    
    // Priority queue entries: pair<estimated_total_cost, node>
    using NodeEntry = pair<int, int>;
    auto cmp = [](const NodeEntry &a, const NodeEntry &b) { return a.first > b.first; };
    priority_queue<NodeEntry, vector<NodeEntry>, decltype(cmp)> 
        pqF(cmp), pqB(cmp);
    
    // Allocate vector-based caches for ALT heuristic computations.
    // They are sized max_id+1 and initialized to -1 (meaning "not computed yet").
    vector<int> altCacheForward(max_id + 1, -1);
    vector<int> altCacheBackward(max_id + 1, -1);
    
    // Lambda for forward ALT heuristic with caching.
    auto ALT_forward = [&](int node) -> int {
        if (altCacheForward[node] != -1)
            return altCacheForward[node];
        int val = ALT_heuristic(node, end);
        altCacheForward[node] = val;
        return val;
    };
    
    // Lambda for backward ALT heuristic with caching.
    auto ALT_backward = [&](int node) -> int {
        if (altCacheBackward[node] != -1)
            return altCacheBackward[node];
        int val = ALT_heuristic(node, start);
        altCacheBackward[node] = val;
        return val;
    };

    // Initialize starting conditions.
    distF[start] = 0;
    distB[end] = 0;
    pqF.push({ALT_forward(start), start});
    pqB.push({ALT_backward(end), end});
    
    int bestPath = INF;
    int meetingPoint = -1;
    const double approxFactor = 1.1;  // Allow a 10% approximation.

    // Main search loop.
    while (!pqF.empty() && !pqB.empty()) {
        int f_min = pqF.empty() ? INF : pqF.top().first;
        int b_min = pqB.empty() ? INF : pqB.top().first;
        // Early termination condition: if our best path is within approxFactor*(f_min + b_min), we stop.
        if (bestPath <= approxFactor * (f_min + b_min))
            break;
        
        // ----- Forward Search Step -----
        if (!pqF.empty()) {
            auto [fEst, fNode] = pqF.top();
            pqF.pop();
            if (visitedF[fNode])
                continue;
            visitedF[fNode] = true;
            
            // If this node has been visited in the backward search, update the best path.
            if (visitedB[fNode]) {
                int totalDist = distF[fNode] + distB[fNode];
                if (totalDist < bestPath) {
                    bestPath = totalDist;
                    meetingPoint = fNode;
                }
            }
            
            // Expand all neighbors in the forward direction.
            if (graph.find(fNode) != graph.end()) {
                for (const auto& edge : graph.at(fNode)) {
                    int newDist = distF[fNode] + edge.time;
                    if (newDist < distF[edge.to]) {
                        distF[edge.to] = newDist;
                        prevF[edge.to] = fNode;
                        int heuristic = ALT_forward(edge.to);
                        pqF.push({newDist + heuristic, edge.to});
                    }
                }
            }
        }
        
        // ----- Backward Search Step -----
        if (!pqB.empty()) {
            auto [bEst, bNode] = pqB.top();
            pqB.pop();
            if (visitedB[bNode])
                continue;
            visitedB[bNode] = true;
            
            if (visitedF[bNode]) {
                int totalDist = distF[bNode] + distB[bNode];
                if (totalDist < bestPath) {
                    bestPath = totalDist;
                    meetingPoint = bNode;
                }
            }
            
            if (graph.find(bNode) != graph.end()) {
                for (const auto& edge : graph.at(bNode)) {
                    int newDist = distB[bNode] + edge.time;
                    if (newDist < distB[edge.to]) {
                        distB[edge.to] = newDist;
                        prevB[edge.to] = bNode;
                        int heuristic = ALT_backward(edge.to);
                        pqB.push({newDist + heuristic, edge.to});
                    }
                }
            }
        }
    }
    
    *time = bestPath;
    if (meetingPoint == -1)
        return {};  // No path found.
    
    // ----- Path Reconstruction -----
    // Reconstruct the forward path from start to meetingPoint.
    vector<int> forwardPath;
    for (int cur = meetingPoint; cur != start; cur = prevF[cur]) {
        forwardPath.push_back(cur);
    }
    forwardPath.push_back(start);
    reverse(forwardPath.begin(), forwardPath.end());
    
    // Reconstruct the backward path from meetingPoint to end.
    vector<int> backwardPath;
    for (int cur = meetingPoint; cur != end; cur = prevB[cur]) {
        backwardPath.push_back(prevB[cur]);
    }
    
    // Combine both parts to form the complete path.
    vector<int> finalPath = forwardPath;
    finalPath.insert(finalPath.end(), backwardPath.begin(), backwardPath.end());
    
    return finalPath;
}


