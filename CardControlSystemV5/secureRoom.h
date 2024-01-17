/**
 * @file   secureRoom.h
 * @brief  Header file for the Secure_Room class.
 *
 * The Secure_room class is a derived class from the base Room class.
 * It includes methods for saving Secure_Room data to a file and granting access based on the CardHolder's role and current time.
 */

#pragma once

#include <iostream>
#include "room.h" 
#include "cardHolder.h"

using namespace std;

/**
 * @class Secure_Room
 * @brief Represents a secure room in the Card Control System.
 * @details Inherits from the base Room class.
 */

class Secure_Room : public Room {
public:
    /**
    * @brief Constructor to initialize a Secure_Room object with building code, floor, and room number.
    *
    * @param buildingCode The building code of the Secure_Room.
    * @param floor The floor of the Secure_Room.
    * @param roomNumber The room number of the Secure_Room.
    */
    Secure_Room(string buildingCode, int floor, int roomNumber)
        : Room(buildingCode, floor, roomNumber, SECURE_ROOM) {}

    /**
    * @brief Saves the Secure_Room object to a file.
    *
    * @param outFile Reference to the output file stream to write data to.
    */
    void saveToFile(ofstream& outFile) const;

    /**
    * @brief Grants access to the Secure_Room based on the CardHolder's role and current time.
    *
    * This method provides specific access rules for Secure_Room.
    *
    * @param cardHolder Reference to the CardHolder attempting to access the room.
    * @return true if access is granted, false otherwise.
    */

    bool grantAccess(const CardHolder& cardHolder) const;

    /**
    * @brief Loads additional data from a file for Secure_Room.
    *
     * @param inFile Reference to the input file to read data from.
    */

    void loadFromFile(ifstream& inFile) {
        Room::loadFromFile(inFile); //call the base class loadFromFile
        //will write room data from file
    }
};
