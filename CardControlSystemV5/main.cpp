#include "userMenu.h"
#include "gtest/gtest.h"
#include <iostream>

User_Menu menu;

int main(int argc, char** argv) {
    // Initialize Google Test
    ::testing::InitGoogleTest(&argc, argv);

    // Run the tests
    int testResult = RUN_ALL_TESTS();

    // Check the test result
    if (testResult != 0) {
        cout << "Tests failed. Exiting.\n";
        return testResult;
    }

    menu.menu();

    cout << "bye";
    return 0;
}

