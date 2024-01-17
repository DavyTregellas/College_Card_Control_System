/**
 * @file   MenuUserFeatures.h
 * @brief  Header file for the MenuUserFeatures class.
 *
 * The MenuUserFeatures class provides functionalities related to user management in the Card Control System.
 * It includes methods for adding a user, deleting a user, viewing users, loading users from a file, and saving users to a file.
 */

#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "cardHolder.h"
#include "room.h"
#include "lectureHall.h"
#include "teachingRoom.h"

class MenuUserFeatures {
public:

    /**
     * @brief Adds a new user to the system.
     *
     * This function allows users to add new individuals to the system. User input for Swipe Card ID, Name, and Role is required.
     * The function creates a new `CardHolder` object based on the provided input and saves it to the 'people' vector, this is then saved to file.
     *
     * @param people Reference to the vector containing CardHolder objects.
     */
    void addUser(std::vector<CardHolder>& people);

    /**
     * @brief Deletes a user from the system.
     *
     * Users can be removed from the system based on Swipe Card ID.
     * The function searches for the specified user in the 'people' vector, deletes it, and saves the updated vector to a file.
     *
     * @param people Reference to the vector containing CardHolder objects.
     */
    void deleteUser(std::vector<CardHolder>& people);

    /**
     * @brief Views the list of saved users in the system.
     *
     * This function allows users to view all card holders saved in the system ('people' vector).
     * The function loads the user data from a file and displays it line by line.
     *
     * @param people Reference to the vector containing CardHolder objects.
     */
    void viewUsers(const std::vector<CardHolder>& people);

    /**
     * @brief Loads users from a file into the system.
     *
     * This function clears the existing user data and loads users from a file into the 'people' vector.
     *
     * @param people Reference to the vector containing CardHolder objects, allowing for the loading of user data from a file.
     */
    void loadUsersFromFile(std::vector<CardHolder>& people);

    /**
     * @brief Saves users to a file.
     *
     * This function saves the user data in the 'people' vector to a file.
     *
     * @param people Reference to the vector containing CardHolder objects, enabling the saving of user data to a file.
     */
    void saveUsersToFile(const std::vector<CardHolder>& people);
};

