#include <iostream>
#include "Headers/Display/display.hpp"

int main()
{
    cout << "\e[1;37m";
    graph = loadDataset();
    display();
    return 0;
}
