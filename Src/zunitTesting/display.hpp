#ifndef DISPLAY
#define DISPLAY
#include "unitTesting.hpp"

/**
 * This function prints all nodes from a defined path defined as a vector of ints.
 * @param vec: a vector of ints
 * @result Prints a list of ints with this format [1, 2, 3].
 */
void printVector(const vector<int> &vec)
{
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i)
    {
        cout << vec[i];
        if (i != vec.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "]\n";
}

/**
 * Clear the terminal.
 * @param None
 * @result The terminal is cleared.
 */
void clearScreen()
{
#if defined _WIN32
    system("cls");
#elif defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
#elif defined(__APPLE__)
    system("clear");
#endif
}

/**
 * This function handles exceptions related to user inputs.
 * @param None
 * @result If the user entered an incorrect input, prints an error message.
 */
void handleException()
{
    if (invalid)
    {
        cout << "Invalid input!\n";
        invalid = false;
    }
}

/**
 * This function requests the selection of an correct or an incorrect csv file.
 * @param None
 * @result Copy the file selected by the user into the "Src folder".
 */
void csvSelection()
{
    while (true)
    {

        clearScreen();
        cout << "+---------------------------------------------------------------+\n";
        cout << "|                    Which file do you wish to use?             |\n";
        cout << "++---------------------------------------------+----------------+\n";
        cout << "1| A clean CSV file                            |\n";
        cout << "-+---------------------------------------------+\n";
        cout << "2| A CSV file with loops, repetitions, etc...  |\n";
        cout << "-+---------------------------------------------+\n";
        cout << "0| Cancel                                      |\n";
        cout << "-+---------------------------------------------+\n";

        handleException();
        cout << "\n";
        cin >> input;

        if (input == "0")
        {
            return;
        }
        else if (input == "1")
        {
            return;
        }
        else if (input == "2")
        {
            copyFile("incorrect.csv");
            return;
        }
        else
        {
            invalid = true;
        }
    }
}
#endif // !DISPLAY