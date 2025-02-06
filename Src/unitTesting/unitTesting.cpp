#include "unitTesting.hpp"
#include "./tests/pathingTest.hpp"
#include "./tests/serverTest.hpp"
#include "./tests/dataValidationTest.hpp"
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

        getline(cin, input);
        
        if (input == "0")
        {
            clearScreen();
            return 0;
        }
        else if (input == "1")
        {
            clearScreen();
            copyFile("../csv/correct.csv");

            pathingTesting();
            filesystem::remove("./unitTest.csv");
        }
        else if (input == "2")
        {
            clearScreen();
            serverTests();
            filesystem::remove("./unitTest.csv");
            clearScreen();
        }
        else if (input == "3")
        {
            clearScreen();
            cout<<"This test is fully manual, first you'll have to select either a clean or unclean csv.\n"
                << "Once selected, the program should print the result, if it is the clean csv,\n"
                <<"it should indicate no loop, duplicate or format error. If it is the unclean csv\n"
                <<"it should indicate duplicates and format errosr.\n";
            system("pause");
            csvSelection();
            clearScreen();
            dataValidationTest();
        }
        else
        {
            invalid = true;
        }
    }
}
