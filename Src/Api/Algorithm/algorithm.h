#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <string>
#include <unordered_map>
#include <vector>

using Graph = std::unordered_map<std::string, std::vector<std::pair<std::string, int>>>;

// Function to load the graph from a CSV file
Graph loadGraph(const std::string& filename);

#endif // ALGORITHM_H
