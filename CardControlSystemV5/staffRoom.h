/**
 * @file   staffRoom.h
 * @brief  Header file for the Staff_Room class.
 *
 * The Staff_Room class is a derived class from the base Room class.
 * It includes methods for saving Staff_Room data to a file and granting access based on the CardHolder's role and current time.
 */

#pragma once

#include <iostream>
#include "room.h"
#include "cardHolder.h"

using namespace std;

/**
 * @class Staff_Room
 * @brief Represents a staff room in the Card Control System.
 * @details Inherits from the base Room class.
 */

class Staff_Room : public Room {
public:
    /**
    * @brief Constructor to initialize a Staff_Room object with building code, floor, and room number.
    *
    * @param buildingCode The building code of the Staff_Room.
    * @param floor The floor of the Staff_Room.
    * @param roomNumber The room number of the Staff_Room.
    */
    Staff_Room(string buildingCode, int floor, int roomNumber)
        : Room(buildingCode, floor, roomNumber, STAFF_ROOM) {}

    /**
    * @brief Saves the Staff_Room object to a file.
    *
    * @param outFile Reference to the output file stream to write data to.
    */

    void saveToFile(ofstream& outFile) const;

    /**
    * @brief Grants access to the Staff_Room based on the CardHolder's role and current time.
    *
    * This method provides specific access rules for Staff_Room.
    *
    * @param cardHolder Reference to the CardHolder attempting to access the room.
    * @return true if access is granted, false otherwise.
    */

    bool grantAccess(const CardHolder& cardHolder) const;
    
    /**
    * @brief Loads additional data from a file for Staff_Room.
    *
    * @param inFile Reference to the input file to read data from.
    */

    void loadFromFile(ifstream& inFile) {
        Room::loadFromFile(inFile); //call the base class loadFromFile
        //will write room data from file
    }
};
