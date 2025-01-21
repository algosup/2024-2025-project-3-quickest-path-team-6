#include <iostream>
#include "../Input/userInput.hpp"
#include "../../Algorithm/algorithm.cpp"

using namespace std;

void mainMenu();
void findMyWayMenu();
void creditsMenu();

const int LOWEST_ID = 1;
const int HIGHEST_ID = 23947347;

int page = 1;

void clearScreen(){
    // clears the console depending on your architecture
    #if defined _WIN32
        system("cls");
    #elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__) || defined (__APPLE__)
        system("clear");
    #endif
}

void display(){
    while(page != 0){
        switch(page){
            case 1:
                mainMenu();
                break;
            case 2:
                findMyWayMenu();
                break;
            case 3:
                creditsMenu();
                break;
            default:
                page = 0;
                break;
        }
    }
    cout << "\nBye! See you later!\n" << endl;
}

void mainMenu(){
    while (page == 1 || inputException){
        clearScreen();
        cout << "+-------------------------------------------_--------------_--------------+\n"
             << "| \\    / _  |  _  _  ._ _   _    _|_  _    |_) _. _|_ |_  / \\     o  _ |  |\n"
             << "|  \\/\\/ (/_ | (_ (_) | | | (/_    |_ (_)   |  (_|  |_ | | \\_X |_| | (_ |< |\n"
             << "++-------------+----------------------------------------------------------+\n"
             << "1| Find my way |                                            | M   |        \n"
             << "-+-------------+                                            \\'_' /        \n"
             << "2| Credits     |                                            |/ \\|         \n"
             << "-+-------------+\n"
             << "0| Exit        |\n" 
             << "-+-------------+" << endl;
        handleException();
        cout << "Your choice -> ";
        input = userInputInt(&inputException);
        switch(input){
            case 0:
                page = 0;
                break;
            case 1:
                page = 2;
                break;
            case 2:
                page = 3;
                break;
            default:
                inputException = true;
                break;
        }
    }
    input = 0;
}

void findMyWayMenu(){
    int travelTime = 0;
    int departurePoint = 0;
    int destinationPoint = 0;
    bool isAlgorithmDone = false;
    while(page == 2 || inputException){
        clearScreen();
        cout << "+----------------------_-------------------_-----------------------------+\n"
             << "|                     |_ o ._   _| m \\/\\/ (_| \\/              |/ \\|       |\n"
             << "|  |\\ /|              |  | | | (_| y          /                           |\n"
             << "+-------------------------------------------------------------------------+\n";
        if(input != 1 && !isAlgorithmDone){
            cout << "Available points between " << LOWEST_ID << " and " << HIGHEST_ID << "\n" << endl;
            if(departurePoint <= 0 || departurePoint > HIGHEST_ID){
                handleException();
                cout << "Choose a departure -> ";
                departurePoint = userInputInt(&inputException);
            }
            else if(destinationPoint <= 0 || destinationPoint > HIGHEST_ID){
                cout << "+----------\n"
                     << "| Departure: " << departurePoint << "\n"
                     << "+----------" << endl;
                handleException();
                cout << "Choose a destination -> ";
                destinationPoint = userInputInt(&inputException);
            }
            else if(departurePoint != 0 && destinationPoint != 0 || inputException){
                cout << "+----------\n"
                     << "| Departure: " << departurePoint << "\n"
                     << "|     \\/\n"
                     << "| Destination: " << destinationPoint << "\n"
                     << "+----------\n" << endl;
                cout << "-+-----------------------+\n"
                     << "1| Everything is correct |\n"
                     << "-+-----------------------+\n"
                     << "2| Redefine my path      |\n"
                     << "-+-----------------------+\n"
                     << "0| Go back to main menu  |\n" 
                     << "-+-----------------------+\n" << endl;
                handleException();
                cout << "Your choice -> ";
                input = userInputInt(&inputException);
                switch(input){
                    case 0:
                        page = 1;
                        break;
                    case 1:
                        break;
                    case 2:
                        departurePoint = 0;
                        destinationPoint = 0;
                        break;
                    default:
                        inputException = true;
                        break;
                }
            }
        }
        else if(input == 1 || inputException){
            cout << "| Departure: " << departurePoint << "\n"
                 << "|     \\/\n"
                 << "| Destination: " << destinationPoint << "\n" 
                 << "+----------\n" << endl;
            if(!isAlgorithmDone){
                travelTime = algorithm(departurePoint, destinationPoint, HIGHEST_ID);
                isAlgorithmDone = true;
            }
            cout << endl << "Travel time: " << travelTime << "\n" << endl;
            handleException();
            cout << "0| Go to main menu? -> ";
            input = userInputInt(&inputException);
            if(input != 0)
                inputException = true;
            else
                page = 1;
        }
    }
}

void creditsMenu()
{
    while(page == 3 || inputException)
    {
        clearScreen();
        cout << "+--------------------------_----------------------------------------------+\n"
             << "|                         /  ._ _   _| o _|_  _                           |\n"
             << "|                         \\_ | (/_ (_| |  |_ _>                           |\n"
             << "+-------------------------------------------------------------------------+\n"
             << "|                  All credits are given to the team 6                    |\n"
             << "|                          Special thanks to                              |\n"
             << "|                                                                         |\n"
             << "|                     -> the Software Engineers:                          |\n"
             << "|                             Pavlo PRENDI                                |\n"
             << "|                            Mariem ZAIANE                                |\n"
             << "|                                                                         |\n"
             << "|                      -> the Technical Leader:                           |\n"
             << "|                           Enzo GUILLOUCHE                               |\n"
             << "|                                                                         |\n"
             << "|                      -> the Quality Assurance:                          |\n"
             << "|                           Maxime THIZEAU                                |\n"
             << "|_ ___                                                                    |\n"
             << "|_] O/                  -> the Program Manager:                           |\n"
             << "|_  O|                      Manech LAGUENS                                |\n"
             << "|_]__\\                                                                    |\n"
             << "|                      -> the Technical Writer:                           |\n"
             << "|                         Aurélien FERNANDEZ                              |\n"
             << "|                                                                         |\n"
             << "|                       -> the Project Manager:                           |\n"
             << "|                             Evan UHRING                                 |\n"
             << "+-------------------------------------------------------------------------+\n";
        handleException();
        cout << "0| Go to main menu? -> ";
        input = userInputInt(&inputException);
        if(input != 0)
            inputException = true;
        else
            page = 1;
    }
}