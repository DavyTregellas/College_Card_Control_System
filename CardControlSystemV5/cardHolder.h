#pragma once

#include <iostream>
#include <fstream>

using namespace std;

/**
 * @file   cardHolder.h
 * @brief  Header file for the CardHolder class.
 *
 * The CardHolder class represents an individual with access to the Card Control System. It includes methods for saving and loading data from files.
 */

//roles have been assigned to integer values for saving and loading onto file
enum CollegeRole {
    STAFF = 0,
    STUDENT = 1,
    VISITOR = 2,
    CLEANER = 3,
    MANAGER = 4,
    SECURITY = 5,
    EMERGENCY_RESPONDER = 6
};

/**
 * @class CardHolder
 * @brief Represents a Card holder within the college.
 */

class CardHolder {
private:
    int swipeCardID; /**< The unique identifier for the CardHolder. */
    string name; /**< The name of the CardHolder. */
    CollegeRole role; /**< The role assigned to the CardHolder. */

public:

    /**
    * @brief Constructor to initialize a CardHolder object with a swipe card ID, name, and role.
    *
    * @param swipeCardID The unique identifier for the CardHolder.
    * @param name The name of the CardHolder.
    * @param role The role assigned to the CardHolder.
    */

    // Constructor for CardHolder
    CardHolder(int swipeCardID, string name, CollegeRole role) : swipeCardID(swipeCardID), name(name), role(role) {
        // Additional initialization if needed
    }

    /**
    * @brief Default constructor for the CardHolder class.
    */

    CardHolder() = default;  //now I am able to create an instance without perameters


    /**
     * @brief Loads data from a file into the CardHolder object.
     *
     * @param inFile Reference to the input file stream to read data from.
     * @return true if the file is successfully loaded, false otherwise.
     */

    //load data from a file, using a bool so if the file is empty the function returns false
    bool loadFromFile(ifstream& inFile);

     /**
     * @brief Getter method to retrieve the role of the CardHolder.
     *
     * @return The role of the CardHolder.
     */

    CollegeRole getRole() const {
        return role;
    }

    /**
    * @brief Getter method to retrieve the role of the CardHolder as a string.
    *
    * @return The role of the CardHolder as a string.
    */

    string getRoleAsString() const {
        switch (role) {
        case STAFF:
            return "Staff";
        case STUDENT:
            return "Student";
        case VISITOR:
            return "Visitor";
        case CLEANER:
            return "Cleaner";
        case MANAGER:
            return "Manager";
        case SECURITY:
            return "Security";
        case EMERGENCY_RESPONDER:
            return "Emergency Responder";
        default:
            return "Unknown Role";
        }
    }


    /**
    * @brief Getter method to retrieve the name of the CardHolder.
    *
    * @return The name of the CardHolder.
    */

    string getName() const {
        return name;
    }

     /**
     * @brief Getter method to retrieve the swipe card ID of the CardHolder.
     *
     * @return The swipe card ID of the CardHolder.
     */

    int getSwipeCardID() const {
        return swipeCardID;
    }

};