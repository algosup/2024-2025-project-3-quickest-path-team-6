#include <iostream>
#include "../Input/userInput.hpp"
#include "../../Algorithm/algorithm.cpp"

using namespace std;

void mainMenu();
void findMyWayMenu();
void creditsMenu();

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

void handleException()
{
    if (inputException)
    {
        cout << "Invalid input! Expected a number from the list." << endl;
        inputException = false;
    }
    else
        cout << endl;
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
        handleException();

        cout << "Your choice -> ";
        input = userInputInt(&inputException);

        if(input == 1)
        {
            findMyWayMenu();
            input = 1;
        } else if (input == 2)
        {
            creditsMenu();
            input = 1;
        } else if (input != 0)
        {
            inputException = true;
        }
    }
}

void findMyWayMenu()
{
    departurePoint = 0;
    destinationPoint = 0;
    int validation = 3;
    while(validation != 2 && validation != 1 && validation != 0 || inputException)
    {
        clearScreen();
        cout << "               Find my way\n"
             << "-----------------------------------------\n"
             << "Available points between " << LOWEST_ID << " and " << HIGHEST_ID << "\n" << endl;
        if(departurePoint == 0)
        {
            handleException();
            cout << "Choose a departure -> ";
            departurePoint = userInputInt(&inputException);
        }
        else if(destinationPoint == 0)
        {
            cout << "Departure: " << departurePoint << endl;
            handleException();
            cout << "Choose a destination -> ";
            destinationPoint = userInputInt(&inputException);
        }
        else if(validation != 2 && validation != 1 && validation != 0 || inputException)
        {
            cout << "Departure: " << departurePoint << endl;
            cout << "Destination: " << destinationPoint << "\n" << endl;
            cout << "1| Everything is correct\n"
                 << "2| Redefine my path\n"
                 << "0| Go back to main menu\n" << endl;
            handleException();
            cout << "Your choice -> ";
            validation = userInputInt(&inputException);
            if(validation != 0 && validation != 1 && validation != 2)
                inputException = true;
        }
        else if(validation == 0 && departurePoint != 0 && destinationPoint != 0 && !inputException)
            break;
        if(validation == 2)
        {
            departurePoint = 0;
            destinationPoint = 0;
            validation = 3;
        }
    }
    if(validation == 1)
    {
        clearScreen();
        cout << "               Find my way\n"
             << "-----------------------------------------\n";
        cout << "Departure: " << departurePoint << endl;
        cout << "Destination: " << destinationPoint << "\n" << endl;
        algorithm(departurePoint, destinationPoint);
        while(input != 0)
        {
            handleException();
            cout << "\n0| Go to main menu? -> ";
            input = userInputInt(&inputException);
            if(input != 0)
                inputException = true;
        }
    }
}

void creditsMenu()
{
    while(input != 0 || inputException)
    {
        clearScreen();
        cout << "                Credits\n"
             << "-----------------------------------------\n"
             << "   All credits are given to the team 6   \n"
             << "           Special thanks to             \n\n"
             << "      -> the Software Engineers:         \n"
             << "              Pavlo PRENDI               \n"
             << "             Mariem ZAIANE               \n\n"
             << "       -> the Technical Leader:          \n"
             << "            Enzo GUILLOUCHE              \n\n"
             << "       -> the Quality Assurance:         \n"
             << "            Maxime THIZEAU               \n\n"
             << "        -> the Program Manager:          \n"
             << "            Manech LAGUENS               \n\n"
             << "       -> the Technical Writer:          \n"
             << "          Aurélien FERNANDEZ             \n\n"
             << "        -> the Project Manager:          \n"
             << "              Evan UHRING                \n" << endl;
        handleException();
        cout << "0| Go to main menu? -> ";
        input = userInputInt(&inputException);
        if(input != 0)
            inputException = true;
    }
}