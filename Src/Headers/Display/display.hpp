#include <iostream>
#include "../Input/userInput.hpp"

using namespace std;

void mainMenu();
void findMyWayMenu();

int lowestID = 1;
int highestID = 23000000;

int departurePoint = 0;
int destinationPoint = 0;

int input = 1;

void clearScreen()
{
    // clears the console depending on your architecture
    #if defined _WIN32
        system("cls");
    #elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__) || defined (__APPLE__)
        system("clear");
    #endif
}

void display()
{
    mainMenu();
}

void mainMenu()
{
    while (input != 0)
    {
        clearScreen();
        cout << "          Welcome on QuickPath !\n"
            << "-----------------------------------------\n"
            << "1| Find my way\n"
            << "2| Credits\n"
            << "0| Exit\n\n"
            << "Your choice -> ";
        input = userInputInt();
        if(input == 1 || input == 2)
        {
            break;
        }
    }
}

void findMyWayMenu()
{
    clearScreen();
    cout << "               Find my way\n"
         << "-----------------------------------------\n"
         << "Available points between " << lowestID << " and " << highestID << "\n"
         << "Choose a departure -> ";
    departurePoint = userInputInt();
    cout << "Choose a destination -> ";
    destinationPoint = userInputInt();

    cout << departurePoint << "  " << destinationPoint;
}