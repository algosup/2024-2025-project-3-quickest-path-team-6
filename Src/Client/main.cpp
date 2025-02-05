#include "Includes/includes.hpp"
#include "Display/display.hpp"

/*
    The main program of the client side
    From here, every other file is included
*/
int main()
{
    cout << "\e[1;37m"; // set the terminal text in bold

    /* 
        Send a request to the server to get the lowest_id and highest_id, found in the handled .csv file
        The .detach() method is used to perform the request independently while the rest of the program is executed
        It serves also to know if the server is online or not
    */
    thread(sendRequestId, ref(lowest_id), ref(highest_id)).detach();

    display(); // call the main client method
    return 0;
}
