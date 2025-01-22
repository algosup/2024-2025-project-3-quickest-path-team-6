#include <iostream>
#include <vector>
#include <fstream>
#include "../../Libraries/Nlohmann/json.hpp"
#include <iomanip>

using namespace std;

void convertIntoJson(vector<int> path, int taskDuration) {

    // Convert vector to JSON
    nlohmann::json jsonData;
    jsonData["path"] = path;
    jsonData["time"] = taskDuration;

    // Write JSON to file
    ofstream outFile("../Client/Bin/pathQuick.json");
    if (outFile.is_open()) {
        outFile << setw(4) << jsonData.dump(4); // Pretty print with 4 spaces
        outFile.close();
        cout << endl << "Path converted into JSON, data written to pathQuick.json\n" << endl;
    } else {
        cerr << endl << "Error opening JSON file for writing" << endl;
    }
}
