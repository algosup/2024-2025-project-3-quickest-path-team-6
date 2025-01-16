#include <iostream>
#include <vector>
#include <fstream>
#include <nlohmann/json.hpp>

using namespace std;

void convertIntoJson(vector<int> path) {

    // Convert vector to JSON
    nlohmann::json jsonData = path;

    // Write JSON to file
    ofstream outFile("Bin/pathQuick.json");
    if (outFile.is_open()) {
        outFile << jsonData.dump(4); // Pretty print with 4 spaces
        outFile.close();
        cout << endl << "Path converted into JSON, data written to pathQuick.json" << endl;
    } else {
        cerr << endl << "Error opening file for writing" << endl;
    }
}
