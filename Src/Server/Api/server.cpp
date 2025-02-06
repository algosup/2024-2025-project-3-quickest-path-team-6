#include "api.cpp"

// Disable terminal input echo and line buffering.
void disableInput() {
    #ifdef _WIN32
        HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
        DWORD prevMode;
        GetConsoleMode(hInput, &prevMode); // Get current mode
        SetConsoleMode(hInput, prevMode & ~ENABLE_ECHO_INPUT & ~ENABLE_LINE_INPUT);
    #else
        termios tty;
        tcgetattr(STDIN_FILENO, &tty); // Get current settings
        tty.c_lflag &= ~ICANON;        // Disable canonical mode
        tty.c_lflag &= ~ECHO;          // Disable echo
        tcsetattr(STDIN_FILENO, TCSANOW, &tty); // Apply changes
    #endif
}

// Re-enable terminal input echo and line buffering.
void enableInput() {
    #ifdef _WIN32
        HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
        DWORD prevMode;
        GetConsoleMode(hInput, &prevMode); // Get current mode
        SetConsoleMode(hInput, prevMode | ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT);
    #else
        termios tty;
        tcgetattr(STDIN_FILENO, &tty); // Get current settings
        tty.c_lflag |= ICANON;         // Enable canonical mode
        tty.c_lflag |= ECHO;           // Enable echo
        tcsetattr(STDIN_FILENO, TCSANOW, &tty); // Apply changes
    #endif
}

int main() {
    const int PORT = 8080;

    // Initialize the server (loads dataset and builds the graph).
    if (!initServer()) {
        cout << "No .csv file found. Server shutting down." << "\r" << flush << endl;
        return 0;
    }
    
    disableInput();

    Api apiServer(PORT);
    apiServer.start();

    enableInput();
    cout << "Server shutting down. See you later!" << "\r" << flush << endl;
    return 0;
}
