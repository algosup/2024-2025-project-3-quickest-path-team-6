#include "algorithm.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>

// Function to load the graph from a CSV file
Graph loadGraph(const std::string& filename) {
    Graph graph;
    std::ifstream file(filename);

    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + filename);
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string landmarkA, landmarkB, timeStr;

        // Parse the line (format: Landmark_A_ID,Landmark_B_ID,Time)
        std::getline(iss, landmarkA, ',');
        std::getline(iss, landmarkB, ',');
        std::getline(iss, timeStr);

        int time = std::stoi(timeStr);

        // Add the bidirectional edge to the graph
        graph[landmarkA].emplace_back(landmarkB, time);
        graph[landmarkB].emplace_back(landmarkA, time);
    }

    file.close();
    return graph;
}
