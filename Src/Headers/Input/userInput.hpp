#include <iostream>

using namespace std;

int userInputInt(bool* exception)
{
    int num;

    cin >> num;

    // Check for type mismatch of the input
    if (cin.fail()) 
    {
        // Clear the failbit and ignore the remaining input
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        *exception = true;
    }
    else 
    {
        // Input is valid
        *exception = false;
    }

    return num;
}