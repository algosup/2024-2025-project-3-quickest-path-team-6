#include <iostream>
#include "../Input/userInput.hpp"

using namespace std;

void mainMenu();
void findMyWayMenu();

const int LOWEST_ID = 1;
const int HIGHEST_ID = 23000000;

int departurePoint = 0;
int destinationPoint = 0;

int input = 1;
bool inputException = false;

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
    while (input != 0 || inputException)
    {
        clearScreen();
        cout << "          Welcome on QuickPath !\n"
            << "-----------------------------------------\n"
            << "1| Find my way\n"
            << "2| Credits\n"
            << "0| Exit\n" << endl;
            if (inputException)
            {
                cout << "Invalid input! Expected a number from the list." << endl;
                inputException = false;
            }
            else
                cout << endl;
        cout << "Your choice -> ";
        input = userInputInt(&inputException);
        if(input == 1)
        {
            findMyWayMenu();
        } else if (input == 2)
        {
            break;
        } else if (input != 0)
        {
            inputException = true;
        }
        
    }
}

void findMyWayMenu()
{
    clearScreen();
    cout << "               Find my way\n"
         << "-----------------------------------------\n"
         << "Available points between " << LOWEST_ID << " and " << HIGHEST_ID << "\n"
         << "Choose a departure ";
    departurePoint = userInputInt(&inputException);
    cout << "Choose a destination ";
    destinationPoint = userInputInt(&inputException);
}