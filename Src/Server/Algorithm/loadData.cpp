#include <thread>
#include <chrono>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include "../DataValidation/validateCsv.cpp"

using namespace std;
using namespace std::chrono;
namespace fs = std::filesystem;


int min_id = 1, max_id = 0;

ifstream file;
bool ended = false;
void getData(const string& file_name);
void loadingCat(string s);

struct Edge {
    int to;
    int time;
};

void wait(int time)
{
    #ifdef _WIN32
    Sleep(time/1000);
    #else
    usleep(time);
    #endif
}

unordered_map<int, vector<Edge>> data_graph;

unordered_map<int, vector<Edge>> loadDataset() {

    auto start = high_resolution_clock::now(); // get time
    string file_name;

    string path = "../../Src";
    string ext(".csv");
    for (auto& p : fs::recursive_directory_iterator(path))
    {
        if (p.path().extension() == ext){
            cout << "Opening " << p << '\n' << endl;
            file_name = p.path().string();
            break;
        }
    }

    thread getDataThread(getData, file_name);
    thread loadingCatThread(loadingCat, "Loading the file");

    getDataThread.join();
    loadingCatThread.join();

    file.close();

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(stop - start); // get task duration

    cout << "\nLoaded in " << duration.count() << " seconds!\n" 
         << "Available landmarks from " << min_id << " to " << max_id << "\n" << endl;
    return data_graph;
}

void getData(const string& file_name)
{
    if (!file.is_open()) {
        cerr << "Opening file to get data" << "\r" << flush;
        file.open(file_name);
    }
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        int from, to;
        int time;
        char comma;
        ss >> from >> comma >> to >> comma >> time;

        if(from > max_id){
            max_id = from;
        }
        if(to > max_id){
            max_id = to;
        }
        data_graph[from].push_back({to, time});
        data_graph[to].push_back({from, time}); // Bidirectional connection
    }
    ended = true;
}

void verifyData(const string& file_name)
{
    unordered_map<int, vector<int>> graph;
    UnionFind uf;
    bool has_duplicates = false;
    if (!processFile(file_name, graph, uf, has_duplicates)) {
        cerr << "Error while processing the file." << "\r" << flush;
        return;
    }

    if (isAcyclic(graph)) {
        cout << "The file is free of loops." << endl;
    } else {
        cout << "The file contains loops." << endl;
    } if (isFullyConnected(uf)) {
        cout << "The graph is fully connected. Every node can reach every other node." << endl;
    } else {
        cout << "The graph is NOT fully connected. Some nodes are unreachable." << endl;
    }
    if (has_duplicates) {
        cout << "The file contains duplicate connections." << endl;
    } else {
        cout << "No duplicate connections found." << endl;
    }

    cout << endl << endl;
}

void loadingCat(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        cout << " ";
    }
    
    cout << "    /\\_/\\\n" << flush;
    while(!ended){
        cout << s << ".. / o.o \\" << "\r" << flush;
        wait(1000000);
        cout << s << ".. / -.- \\" << "\r" << flush;
        wait(150000);
    }
    cout << "Dataset loaded!    / ^.^ \\" << "\r" << flush;
}