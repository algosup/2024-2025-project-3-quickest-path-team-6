#include "unitTesting.hpp"
#include "./tests/dijsktraTests.hpp"
#include "./tests/serverTests.hpp"
#include "display.hpp"

int main()
{
    while (true)
    {
        clearScreen();
        cout << "+---------------------------------------------------------------+\n";
        cout << "| Welcome to PathQuick's unit tests, what do you want to test?  |\n";
        cout << "++-------------------+------------------------------------------+\n";
        cout << "1| Pathing algorithm |\n";
        cout << "-+-------------------+\n";
        cout << "2| Server functions  |\n";
        cout << "-+-------------------+\n";
        cout << "3| Data validation   |\n";
        cout << "-+-------------------+\n";
        cout << "0| Quit              |\n";
        cout << "-+-------------------+\n";

        handleException(); // If the previous input is invalid, print an error message

        cout << "\n";
        cin >> input;
        if (input == "0")
        {
            clearScreen();
            return 0;
        }
        else if (input == "1")
        {
            clearScreen();
            copyFile("./correct.csv");

            dijkstraTesting();
        }
        else if (input == "2")
        {
            clearScreen();
            serverTests();
            clearScreen();
        }
        else if (input == "3")
        {
            clearScreen();
            csvSelection();
        }
        else
        {
            invalid = true;
        }
    }
}
