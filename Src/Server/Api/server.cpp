#include "api.cpp"

void disableInput() {
    termios tty;
    tcgetattr(STDIN_FILENO, &tty); // Get current terminal settings
    tty.c_lflag &= ~ICANON;        // Disable canonical mode
    tty.c_lflag &= ~ECHO;          // Disable echo
    tcsetattr(STDIN_FILENO, TCSANOW, &tty); // Apply changes
}

void enableInput() {
    termios tty;
    tcgetattr(STDIN_FILENO, &tty); // Get current terminal settings
    tty.c_lflag |= ICANON;         // Re-enable canonical mode
    tty.c_lflag |= ECHO;           // Re-enable echo
    tcsetattr(STDIN_FILENO, TCSANOW, &tty); // Apply changes
}

int main() {
    disableInput();
    const int PORT = 8080;

    graph = loadDataset();

    Api apiServer(PORT);
    apiServer.start();

    enableInput();
    cout << "Server shutting down. See you later!" << "\r" << flush << endl;
    return 0;
}


