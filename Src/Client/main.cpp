#include "./includes/includes.hpp"
#include "Display/display.hpp"

int main()
{
    cout << "\e[1;37m";
    thread(sendRequestId, ref(lowest_id), ref(highest_id)).detach();
    display();
    return 0;
}
