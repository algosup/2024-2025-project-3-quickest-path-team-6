#include "Input/userInput.hpp"

using namespace std;

void mainMenu();
void findMyWayMenu();

void clearScreen(){
    // clears the console depending on your architecture
    #if defined _WIN32
        system("cls");
    #elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__) || defined (__APPLE__)
        system("clear");
    #endif
}

int main()
{
    mainMenu();
    return 0;
}

void mainMenu()
{
    clearScreen();
    cout << "   Welcome on QuickPath !\n"
         << "----------------------------\n"
         << "1| Find my way\n"
         << "2| Credits\n"
         << "0| Exit\n\n"
         << "Your choice -> ";
}

void findMyWayMenu()
{
    clearScreen();
    cout << "         Find my way\n"
         << "----------------------------\n"
         << "1| Find my way\n"
         << "2| Credits\n"
         << "0| Exit\n\n"
         << "Your choice -> ";
}