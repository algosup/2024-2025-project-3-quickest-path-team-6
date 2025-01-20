#include <queue>
#include <unordered_map>
#include <limits>
#include "loadData.cpp"
#include <chrono>
#include <curl/curl.h>

using namespace std::chrono;

unordered_map<int, vector<Edge>> graph; // get the entire graph (need to be handled by the server)

vector<int> modifiedDijkstra(const unordered_map<int, vector<Edge>>& graph, int start, int end, double* time) {

    vector<int> path;

    if (start == end){
        path.push_back(end);
        reverse(path.begin(), path.end());
        return path;
    }

    // Min-heap: (total time, landmark ID)
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<>> pq;

    // Distance map to store the shortest path time to each landmark
    unordered_map<int, double> distances;
    unordered_map<int, int> previous; // To reconstruct the path

    for (const auto& node : graph) {
        distances[node.first] = numeric_limits<double>::infinity();
    }

    distances[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [current_time, current_node] = pq.top();
        pq.pop();

        if (current_node == end) {
            *time = current_time;
            break; // Early exit if we reach the destination
        }

        for (const auto& edge : graph.at(current_node)) {
            double new_time = current_time + edge.time;

            if (new_time < distances[edge.to]) {
                distances[edge.to] = new_time;
                previous[edge.to] = current_node;
                pq.push({new_time, edge.to});
            }
        }
    }

    // Reconstruct the path
    for (int at = end; at != 0; at = previous[at]) {
        
        path.push_back(at);
        if (at == start) break; // Reached the start point
    }

    reverse(path.begin(), path.end());
    return path;
}

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

void sendRequest(int start, int end, string fileFormat) {
    cout << "Calculating shortest path..." << endl << endl;
    auto timeStart = high_resolution_clock::now(); // get time

    // Prepare the API request (building the URL)
    string source = to_string(start);
    string destination = to_string(end);
    string format = fileFormat; // or you can set this based on user input

    string api_url = "http://localhost:8080/route?source=" + source + "&destination=" + destination + "&format=" + format;

    // Make an HTTP GET request to the API
    CURL* curl;
    CURLcode res;
    string response_string;
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, api_url.c_str());         // Set the URL for the request
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback); // Set the callback to capture the response
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_string);  // Store the response in response_string
        
        res = curl_easy_perform(curl); // Execute the request
        
        if (res != CURLE_OK) {
            cerr << "CURL request failed: " << curl_easy_strerror(res) << endl;
        } else {
            // Process the response from the API
            cout << "API Response: " << endl << response_string << endl;
            // Parse response to extract the path and time (you can use a JSON parser here)
            // For example:
            // if (response_string contains valid JSON, extract the travelTime and path)
        }

        curl_easy_cleanup(curl); // Clean up the curl object
    }

    curl_global_cleanup(); // Clean up global curl environment


    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - timeStart); // get task duration
    if (duration.count() > 2000) {
        cout << endl << "Path calculated in " << duration.count()/1000 << " seconds." << endl;
    } else {
        cout << endl << "Path calculated in " << duration.count() << " milliseconds." << endl;
    }
    
}
