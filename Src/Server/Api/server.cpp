#include "api.cpp"

int main() {
    const int PORT = 8080;

    graph = loadDataset();

    Api apiServer(PORT);
    apiServer.start();

    return 0;
}


