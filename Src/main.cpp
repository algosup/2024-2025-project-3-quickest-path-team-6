#include "api.h"

int main() {
    const int PORT = 8080;

    Api apiServer(PORT);
    apiServer.start();

    return 0;
}


