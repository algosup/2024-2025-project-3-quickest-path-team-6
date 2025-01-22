#include <iostream>
#include "Display/display.hpp"

int main()
{
    cout << "\e[1;37m";
    display();
    return 0;
}
