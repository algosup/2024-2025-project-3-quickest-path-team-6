#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include "../Includes/includes.hpp"
#include "../Input/userInput.hpp"
#include "../request.hpp"

// Function prototypes for menu displays
void mainMenu();
void findMyWayMenu();
void creditsMenu();

// Global variables to track ID range and current page state
int lowest_id = 0;
int highest_id = 0;
int page = 1;

// Function to clear the console screen based on OS
void clearScreen(){
    #if defined _WIN32
        system("cls"); // Windows
    #elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__) || defined (__APPLE__)
        system("clear"); // Linux/macOS
    #endif
}

// Main display loop handling different menu pages
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

// Main menu function handling user input and navigation
void mainMenu(){
    while (page == 1 || input_exception){
        clearScreen();
        
        // Display menu options
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
        
        handleException(server_is_online, page);
        cout << "Your choice -> ";
        input = userInputInt(&input_exception);

        // Handle user input
        switch(input){
            case 0:
                page = 0;
                break;
            case 1:
                if(server_is_online)
                    page = 2;
                else
                    page = 1;
                break;
            case 2:
                page = 3;
                break;
            default:
                input_exception = true;
                break;
        }
    }
    input = 0;
}

// Menu for finding a path between landmarks
void findMyWayMenu(){
    int travel_time = 0;
    int departure_point = 0;
    int destination_point = 0;
    bool chosen_format = false; // false = JSON, true = XML
    bool is_algorithm_done = false;

    while(page == 2 && server_is_online || input_exception){
        clearScreen();
        
        // Display menu header
        cout << "+----------------------_-------------------_------------------------------+\n"
             << "|                     |_ o ._   _| M \\/\\/ (_| \\/              |/ \\|       |\n"
             << "|  |\\ /|              |  | | | (_| Y          /                           |\n"
             << "+-------------------------------------------------------------------------+\n";
        
        if(input != 1 && !is_algorithm_done){
            cout << "Available points between " << lowest_id << " and " << highest_id << "\n" << endl;

            // User chooses departure point
            if(departure_point <= 0){
                handleException(server_is_online, page);
                cout << "Choose a departure -> ";
                departure_point = userInputInt(&input_exception);
                if (departure_point > highest_id  || departure_point <= 0){
                    input_exception = true;
                    departure_point = 0;
                }
            }
            // User chooses destination point
            else if(destination_point <= 0 || destination_point > highest_id){
                cout << "+----------\n"
                     << "| Departure: " << departure_point << "\n"
                     << "+----------" << endl;
                handleException(server_is_online, page);
                cout << "Choose a destination -> ";
                destination_point = userInputInt(&input_exception);
                if (destination_point > highest_id || destination_point <= 0){
                    input_exception = true;
                    destination_point = 0;
                }
            }
            // Confirm choices and handle options
            else if(departure_point != 0 && destination_point != 0 || input_exception){
                cout << "+----------\n"
                     << "| Departure: " << departure_point << "\n"
                     << "|     \\/\n"
                     << "| Destination: " << destination_point << "\n"
                     << "+----------\n"
                     << "Output file format: " << (chosen_format == false ? "JSON\n" : "XML\n") << endl;
                
                cout << "-+-----------------------+\n"
                     << "1| Everything is correct |\n"
                     << "-+-----------------------+\n"
                     << "2| Change file format    |\n"
                     << "-+-----------------------+\n"
                     << "3| Redefine my path      |\n"
                     << "-+-----------------------+\n"
                     << "0| Go back to main menu  |\n" 
                     << "-+-----------------------+\n" << endl;
                
                handleException(server_is_online, page);
                cout << "Your choice -> ";
                input = userInputInt(&input_exception);

                switch(input){
                    case 0:
                        page = 1;
                        break;
                    case 1:
                        page = 2;
                        break;
                    case 2:
                        page = 2;
                        chosen_format = !chosen_format;
                        break;
                    case 3:
                        page = 2;
                        departure_point = 0;
                        destination_point = 0;
                        break;
                    default:
                        page = 2;
                        input_exception = true;
                        break;
                }
            }
        }
        else if(input == 1 || input_exception){
            cout << "| Departure: " << departure_point << "\n"
                << "|     \\/\n"
                << "| Destination: " << destination_point << "\n" 
                << "+----------\n" << endl;
            if(!is_algorithm_done){
                string format = chosen_format == false ? "json" : "xml";
                sendRequestQuickPath(departure_point, destination_point, format);
                is_algorithm_done = true;
            }
            handleException(server_is_online, page);
            cout << "0| Go to main menu? -> ";
            input = userInputInt(&input_exception);
            if(input != 0)
                input_exception = true;
            else
                page = 1;
        }
        if (!server_is_online){
            input_exception = false;
            page = 1;
        }
    }
}

// Credits menu displaying team members
void creditsMenu(){
    while(page == 3 || input_exception){
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
             << "|                         Aurelien FERNANDEZ                              |\n"
             << "|                                                                         |\n"
             << "|                       -> the Project Manager:                           |\n"
             << "|                             Evan UHRING                                 |\n"
             << "+-------------------------------------------------------------------------+\n";

        cout << endl << "Algorithm's worst-case complexity: O(N^2)." << endl;
        
        handleException(server_is_online, page);
        cout << "0| Go to main menu? -> ";
        input = userInputInt(&input_exception);
        if(input != 0)
            input_exception = true;
        else
            page = 1;
    }
}

#endif // DISPLAY_HPP