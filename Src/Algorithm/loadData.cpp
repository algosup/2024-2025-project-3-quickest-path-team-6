#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unistd.h>
#include <thread>

using namespace std;
#include <chrono>
using namespace std::chrono;

bool ended = false;
void getData();
void loadingCat();

struct Edge {
    int to;
    double time;
};

ifstream file;
unordered_map<int, vector<Edge>> dataGraph;

unordered_map<int, vector<Edge>> loadDataset() {
    string filename = "USA-roads.csv";

    file.open(filename);

    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
        exit(EXIT_FAILURE);
    }
    
    auto start = high_resolution_clock::now(); // get time

    thread getDataThread(getData);

    thread loadingCatThread(loadingCat);

    loadingCatThread.join();
    getDataThread.join();

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(stop - start); // get task duration

    cout << "\nLoaded in " << duration.count() << " seconds!\n" << endl;
    return dataGraph;
}

void getData()
{
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        int from, to;
        double time;
        char comma;
        ss >> from >> comma >> to >> comma >> time;

        dataGraph[from].push_back({to, time});
        dataGraph[to].push_back({from, time}); // Bidirectional connection
    }
    ended = true;
}

void loadingCat()
{
    cout << "                   /\\_/\\\n" << flush;
    while(!ended){
        cout << "Loading dataset.. / o.o \\" << "\r" << flush;
        usleep(1000000);
        cout << "Loading dataset.. / -.- \\" << "\r" << flush;
        usleep(150000);
    }
    cout << "Dataset loaded!   / ^.^ \\" << flush;
}