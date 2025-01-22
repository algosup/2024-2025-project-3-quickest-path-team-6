#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;
using namespace chrono;

string urlEncode(const string& str) {
    ostringstream encoded;
    for (unsigned char c : str) {
        if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~') {
            encoded << c;
        } else {
            encoded << '%' << setw(2) << setfill('0') << hex << (int)c;
        }
    }
    return encoded.str();
}

void sendRequest(int start, int end, string fileFormat) {
    cout << "Calculating shortest path..." << endl << endl;
    auto timeStart = chrono::high_resolution_clock::now(); // get time

    // Prepare the API request (building the URL)
    string source = to_string(start);
    string destination = to_string(end);
    string format = fileFormat; // or you can set this based on user input

    // URL-encode the source, destination, and format values
    string encodedSource = urlEncode(source);
    string encodedDestination = urlEncode(destination);
    string encodedFormat = urlEncode(format);

    // Construct the full curl command with quotes to handle spaces/special characters
    string api_url = "curl \"http://localhost:8080/route?source=" + encodedSource + "&destination=" + encodedDestination + "&format=" + encodedFormat + "\"";

    // Make an HTTP GET request to the API
    int result = system(api_url.c_str());

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - timeStart); // get task duration
    if (duration.count() > 2000) {
        cout << endl << "Path calculated in " << duration.count()/1000 << " seconds." << endl;
    } else {
        cout << endl << "Path calculated in " << duration.count() << " milliseconds." << endl;
    }
}