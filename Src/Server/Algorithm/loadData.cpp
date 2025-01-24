#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>
#include <thread>
#include <chrono>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

using namespace std;
using namespace std::chrono;

bool ended = false;
void getData();
void loadingCat();

struct Edge {
    int to;
    double time;
};

void wait(int time)
{
    #ifdef _WIN32
    Sleep(time/1000);
    #else
    usleep(time);
    #endif
}

ifstream file;
unordered_map<int, vector<Edge>> data_graph;

unordered_map<int, vector<Edge>> loadDataset() {
    string file_name = "../USA-roads.csv";

    file.open(file_name);

    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
        exit(EXIT_FAILURE);
    }
    
    auto start = high_resolution_clock::now(); // get time

    thread getDataThread(getData);
    thread loadingCatThread(loadingCat);

    getDataThread.join();
    loadingCatThread.join();

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(stop - start); // get task duration

    cout << "\nLoaded in " << duration.count() << " seconds!\n" << endl;
    return data_graph;
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

        data_graph[from].push_back({to, time});
        data_graph[to].push_back({from, time}); // Bidirectional connection
    }
    ended = true;
}

void loadingCat()
{
    cout << "                   /\\_/\\\n" << flush;
    while(!ended){
        cout << "Loading dataset.. / o.o \\" << "\r" << flush;
        wait(1000000);
        cout << "Loading dataset.. / -.- \\" << "\r" << flush;
        wait(150000);
    }
    cout << "Dataset loaded!   / ^.^ \\" << flush;
}