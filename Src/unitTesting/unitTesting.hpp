#ifndef UNIT_TESTING
#define UNIT_TESTING

#include <assert.h>
#include <list>
#include <fstream>
#include <thread>
#include <future>

#include "../Server/Algorithm/algorithm.cpp"

string input;         // User input
bool invalid = false; // A boolean to identify the input as valid or not

/**
 * This function takes a file and duplicates it a file into the "Src" folder.
 * @param sourceFile: A string representing a file path.
 * @result The file is copied in a new file named "unitTest.csv" into the Src folder.
 */
bool copyFile(const string &sourceFile)
{
    // Open the source file in binary mode
    ifstream source(sourceFile, ios::binary);
    if (!source)
    {
        cerr << "Error: Cannot open source file: " << sourceFile << endl;
        return false;
    }

    // Open the destination file in binary mode
    ofstream destination("../unitTest.csv", ios::binary);
    if (!destination)
    {
        cerr << "Error: Cannot open destination file " << endl;
        return false;
    }

    // Copy the file content
    destination << source.rdbuf();

    return true;
}

#endif // !UNIT_TESTING