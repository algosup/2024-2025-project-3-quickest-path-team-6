#include <iostream>
#include <vector>
#include <fstream>
#include "../../Libraries/Nlohmann/json.hpp"
#include <iomanip>

using namespace std;

void convertIntoJson(vector<int> path, int task_duration, nlohmann::json &json_data) {

    // Convert vector to JSON
    json_data["path"] = path;
    json_data["time"] = task_duration;

    cout << "Request completed. Path converted into JSON response.\n" << endl;
}