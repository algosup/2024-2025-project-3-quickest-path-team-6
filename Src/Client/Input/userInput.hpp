#ifndef USER_INPUT_HPP
#define USER_INPUT_HPP

#include "../Includes/includes.hpp"

int input = 0; // Stores the user's input
bool input_exception = false; // Flag to indicate input errors

/*
    Checks if a given string represents a valid integer
    This functions returns true if the string represents an integer, false otherwise

    Parameters: 
        - input, the string to check
*/
bool isInteger(const std::string &input) {
    int number;
    size_t i = 0;

    // Ensure all characters are digits (does not handle negative numbers correctly)
    while (i < input.size()) {
        if (!std::isdigit(input[i])) return false;
        i++;
    }

    // Try converting string to integer
    try {
        number = std::stoi(input);
    } catch (const std::out_of_range &) {
        return false; // Handle cases where the number is too large
    }

    return true; // String is a valid integer
}

/*
    Reads an integer input from the user
    This functions returns the valid integer input or -1 if an error occurs
    If the input is not a valid integer, it sets the exception flag

    Parameters: 
        - exception, pointer to a boolean to indicate input errors
*/
int userInputInt(bool* exception) {
    string num;

    getline(cin, num); // Read input from the user

    // If input is empty, return -1
    if (num == "")
        return -1;

    // Validate if the input is a valid integer
    if (!isInteger(num)) {
        *exception = true; // Set exception flag
        return -1; // Return an error indicator
    } else {
        *exception = false; // Reset exception flag
        return stoi(num); // Convert string to integer and return
    }
}

/*
    Handles errors and displays appropriate messages
    This function checks for input errors and server connectivity issues, displaying corresponding messages to the user

    Parameters: 
        - server_is_online, boolean indicating whether the server is connected
        - page, integer representing the current page or state of the application
*/
void handleException(bool server_is_online, int page) {
    if (input_exception) {
        cout << "Invalid input! Expected a number from the list." << endl;
        input_exception = false; // Reset exception flag
    } else if (!server_is_online && input == 1 && page == 1) {
        cout << "Server not connected. Wait until it is connected." << endl;
    } else {
        cout << endl; // Print a blank line for formatting
    }
}

#endif // USER_INPUT_HPP