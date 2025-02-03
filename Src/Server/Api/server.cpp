#include "api.cpp"

void disableInput() {
    #ifdef _WIN32
        HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
        DWORD prevMode;
        GetConsoleMode(hInput, &prevMode);          // Get current input mode
        SetConsoleMode(hInput, prevMode & ~ENABLE_ECHO_INPUT & ~ENABLE_LINE_INPUT); // Disable echo and line input
    #else
        termios tty;
        tcgetattr(STDIN_FILENO, &tty); // Get current terminal settings
        tty.c_lflag &= ~ICANON;        // Disable canonical mode
        tty.c_lflag &= ~ECHO;          // Disable echo
        tcsetattr(STDIN_FILENO, TCSANOW, &tty); // Apply changes
    #endif
}

void enableInput() {
    #ifdef _WIN32
        HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
        DWORD prevMode;
        GetConsoleMode(hInput, &prevMode);          // Get current input mode
        SetConsoleMode(hInput, prevMode | ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT); // Re-enable echo and line input
    #else
        termios tty;
        tcgetattr(STDIN_FILENO, &tty); // Get current terminal settings
        tty.c_lflag |= ICANON;         // Re-enable canonical mode
        tty.c_lflag |= ECHO;           // Re-enable echo
        tcsetattr(STDIN_FILENO, TCSANOW, &tty); // Apply changes
    #endif
}

int main() {
    disableInput();
    const int PORT = 8080;

    if(!loadDataset()){
        cout << "No .csv file found. Server shutting down." << "\r" << flush << endl;
        return 0;
    }

    Api apiServer(PORT);
    apiServer.start();

    enableInput();
    cout << "Server shutting down. See you later!" << "\r" << flush << endl;
    return 0;
}


