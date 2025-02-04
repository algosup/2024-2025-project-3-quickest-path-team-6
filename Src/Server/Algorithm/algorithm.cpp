#include "loadData.hpp"
#include <queue>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;
using namespace std::chrono;

/*
 * ALT_heuristic:
 * -------------------------------
 * Computes the ALT heuristic for node 'node' toward target 'target'.
 * It returns the maximum over all landmarks of:
 *     |distance(landmark, target) - distance(landmark, node)|
 * The precomputed distances are stored in the global vector-of-vectors 
 * 'landmarkDistancesVector'. This provides a lower-bound estimate for A*.
 */
int ALT_heuristic(int node, int target) {
    int bestEstimate = 0;
    for (const auto &distances : landmarkDistancesVector) {
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
 * Performs a bidirectional A* search using the ALT heuristic.
 * The function expands nodes from both the start and target until a meeting point is found
 * or the lower-bound estimate of unexplored paths exceeds the best solution.
 *
 * It uses vector-based arrays for distances, predecessors, and visited flags for fast access,
 * and per-query caches to avoid redundant heuristic computations.
 *
 * Parameters:
 *   - graph: The full graph (global, defined in loadData.hpp).
 *   - start: Starting node ID.
 *   - end: Destination node ID.
 *   - time: Pointer to an int that will receive the total cost of the computed path.
 *
 * Returns:
 *   - A vector of node IDs representing the computed path (empty if no path is found).
 */
vector<int> bidirectionalDijkstra(const unordered_map<int, vector<Edge>>& graph, int start, int end, int* time) {
    // Initialize vectors for forward and backward search.
    vector<int> distF(max_id + 1, INF), distB(max_id + 1, INF);
    vector<int> prevF(max_id + 1, -1), prevB(max_id + 1, -1);
    vector<bool> visitedF(max_id + 1, false), visitedB(max_id + 1, false);
    
    // Priority queues store pairs: <estimated_total_cost, node>.
    using NodeEntry = pair<int, int>;
    auto cmp = [](const NodeEntry &a, const NodeEntry &b) { return a.first > b.first; };
    priority_queue<NodeEntry, vector<NodeEntry>, decltype(cmp)> pqF(cmp), pqB(cmp);
    
    // Allocate per-query caches for ALT heuristic values.
    vector<int> altCacheForward(max_id + 1, -1);
    vector<int> altCacheBackward(max_id + 1, -1);
    
    // Lambda for forward heuristic (target = end).
    auto ALT_forward = [&](int node) -> int {
        if (altCacheForward[node] != -1)
            return altCacheForward[node];
        int val = ALT_heuristic(node, end);
        altCacheForward[node] = val;
        return val;
    };
    
    // Lambda for backward heuristic (target = start).
    auto ALT_backward = [&](int node) -> int {
        if (altCacheBackward[node] != -1)
            return altCacheBackward[node];
        int val = ALT_heuristic(node, start);
        altCacheBackward[node] = val;
        return val;
    };

    // Set initial distances and push start and target into the queues.
    distF[start] = 0;
    distB[end] = 0;
    pqF.push({ALT_forward(start), start});
    pqB.push({ALT_backward(end), end});
    
    int bestPath = INF;
    int meetingPoint = -1;
    const double approxFactor = 1.1;  // Allow 10% approximation.

    // Main bidirectional search loop.
    while (!pqF.empty() && !pqB.empty()) {
        int f_min = pqF.empty() ? INF : pqF.top().first;
        int b_min = pqB.empty() ? INF : pqB.top().first;
        // Early termination: if the best found path is within approxFactor*(f_min+b_min), stop.
        if (bestPath <= approxFactor * (f_min + b_min))
            break;
        
        // Forward expansion.
        if (!pqF.empty()) {
            auto [fEst, fNode] = pqF.top();
            pqF.pop();
            if (visitedF[fNode])
                continue;
            visitedF[fNode] = true;
            // Update bestPath if this node was already processed in the backward search.
            if (visitedB[fNode]) {
                int totalDist = distF[fNode] + distB[fNode];
                if (totalDist < bestPath) {
                    bestPath = totalDist;
                    meetingPoint = fNode;
                }
            }
            // Relax all outgoing edges from fNode.
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
        
        // Backward expansion.
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
        return {};  // No valid path found.
    
    // Reconstruct the path by combining the forward and backward search trees.
    vector<int> forwardPath;
    for (int cur = meetingPoint; cur != start; cur = prevF[cur])
        forwardPath.push_back(cur);
    forwardPath.push_back(start);
    reverse(forwardPath.begin(), forwardPath.end());
    
    vector<int> backwardPath;
    for (int cur = meetingPoint; cur != end; cur = prevB[cur])
        backwardPath.push_back(prevB[cur]);
    
    vector<int> finalPath = forwardPath;
    finalPath.insert(finalPath.end(), backwardPath.begin(), backwardPath.end());
    
    return finalPath;
}
