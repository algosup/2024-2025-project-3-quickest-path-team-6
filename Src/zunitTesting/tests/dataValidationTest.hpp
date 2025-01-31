#ifndef DATA_VALIDATION_TEST
#define DATA_VALIDATION_TEST

#include "../unitTesting.hpp"
#include "../display.hpp"

/**
 * This function requests the verification of the first csv file found in the "Src" folder.
 * @param None
 * @result Prints if there are duplicates, loops or mistakes in the format of a csv file.
 */
void dataValidationTest()
{
    string file_name;

    string constructed_path_str_dbg = "../../Src";
    string ext(".csv");
    // Get the first csv available
    for (auto &p : recursive_directory_iterator(constructed_path_str_dbg))
    {
        if (p.path().extension() == ext)
        {
            cout << "Verifying " << p << "\n"
                 << endl;
            file_name = p.path().string();
            break;
        }
    }
    verifyData(file_name);
    system("pause");
    filesystem::remove("../unitTest.csv");
}

#endif // !DATA_VALIDATION_TEST
