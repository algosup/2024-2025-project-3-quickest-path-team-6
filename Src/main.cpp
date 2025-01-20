#include "api.hpp"

int main() {
    const int PORT = 8080;

    Api apiServer(PORT);
    apiServer.start();

    return 0;
}


#include <iostream>
#include "Headers/Display/display.hpp"

int main()
{
    graph = loadDataset();
    display();
    return 0;
}
