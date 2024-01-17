/**
 * @file   teachingRoom.h
 * @brief  Header file for the Teaching_Room class.
 *
 * The Teaching_room class is a derived class from the base Room class.
 * It includes methods for saving Teaching_Room data to a file and granting access based on the CardHolder's role and current time.
 */

#pragma once

#include <iostream>
#include "room.h"
#include "cardHolder.h"

using namespace std;

/**
* @class Teaching_Room
* @brief Represents a lecture hall in the Card Control System.
* @details Inherits from the base Room class.
*/

class Teaching_Room : public Room {
public:
    /**
    * @brief Constructor to initialize a Teaching_Room object with building code, floor, and room number.
    *
    * @param buildingCode The building code of the Teaching_Room.
    * @param floor The floor of the Teaching_Room.
    * @param roomNumber The room number of the Teaching_Room.
    */
    Teaching_Room(string buildingCode, int floor, int roomNumber)
        : Room(buildingCode, floor, roomNumber, TEACHING_ROOM) {}

    /**
    * @brief Saves the Teaching_Room object to a file.
    *
    * @param outFile Reference to the output file stream to write data to.
    */

    void saveToFile(ofstream& outFile) const;

    /**
    * @brief Grants access to the Teaching_Room based on the CardHolder's role and current time.
    *
    * This method provides specific access rules for Teaching_Room.
    *
    * @param cardHolder Reference to the CardHolder attempting to access the room.
    * @return true if access is granted, false otherwise.
     */

    bool grantAccess(const CardHolder& cardHolder) const;

    /**
    * @brief Loads additional data from a file for Teaching_Room.
    *
    * @param inFile Reference to the input file to read data from.
    */

    void loadFromFile(ifstream& inFile) {
        Room::loadFromFile(inFile); //call the base class loadFromFile
        //will write room data from file
    }
};