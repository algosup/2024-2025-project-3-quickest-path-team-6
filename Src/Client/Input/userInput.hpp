#ifndef USER_INPUT_HPP
#define USER_INPUT_HPP
#include "../Includes/includes.hpp"

int input = 0;
bool input_exception = false;

bool isInteger(const std::string &input) {
    int number;
    // Check if input contains only digits (allowing negative numbers)
    size_t i = 0;

    while (i < input.size()) {
        if (!std::isdigit(input[i])) return false; // Ensure all characters are digits
        i++;
    }

    try {
        number = std::stoi(input); // Convert string to integer
    } catch (const std::out_of_range &) {
        return false; // Handle integer overflow
    }

    return true; // Valid integer
}

int userInputInt(bool* exception)
{
    string num;

    // cin >> num;
    getline(cin, num);

    if (num == "")
        return -1;
    // Check for type mismatch of the input
    if (!isInteger(num)) {
        *exception = true;
        return -1;
    } else {
        *exception = false;
        return stoi(num);
    }
}

void handleException(bool server_is_online, int page)
{
    if (input_exception) {
        cout << "Invalid input! Expected a number from the list." << endl;
        input_exception = false;
    } else if (!server_is_online && input == 1 && page == 1){
        cout << "Server not connected. Wait until it is connected." << endl;
    } else
        cout << endl;
}
#endif // !USER_INPUT_HPP