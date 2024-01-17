/**
 * @file   userMenu.h
 * @brief  Header file for the Lecture_Hall class.
 *
 * The userMenu file hold the user interface. This allows the user to intract with the program. 
 */

#pragma once

#include <iostream>

using namespace std;

class User_Menu {
public:
    /**
    * @brief Loads the user interface
    */
    void menu();

    /**
    * @brief Prints a greeting message
    */
    void greetingMessage();
};