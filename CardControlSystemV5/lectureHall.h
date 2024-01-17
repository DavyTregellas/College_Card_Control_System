/**
 * @file   lectureHall.h
 * @brief  Header file for the Lecture_Hall class.
 *
 * The Lecture_Hall class is a derived class from the base Room class.
 * It includes methods for saving Lecture_Hall data to a file and granting access based on the CardHolder's role and current time.
 */

#pragma once

#include <iostream>
#include "room.h"
#include "cardHolder.h"

using namespace std;

/**
 * @class Lecture_Hall
 * @brief Represents a lecture hall in the Card Control System.
 * @details Inherits from the base Room class.
 */

class Lecture_Hall : public Room {
public:
    /**
    * @brief Constructor to initialize a Lecture_Hall object with building code, floor, and room number.
    *
    * @param buildingCode The building code of the Lecture_Hall.
    * @param floor The floor of the Lecture_Hall.
    * @param roomNumber The room number of the Lecture_Hall.
    */
    Lecture_Hall(string buildingCode, int floor, int roomNumber)
        : Room(buildingCode, floor, roomNumber, LECTURE_HALL) {}

    /**
    * @brief Saves the Lecture_Hall object to a file.
    *
     * @param outFile Reference to the output file stream to write data to.
    */
    void saveToFile(ofstream& outFile) const;

    /**
     * @brief Grants access to the Lecture_Hall based on the CardHolder's role and current time.
     *
     * This method provides specific access rules for Lecture_Hall.
     *
     * @param cardHolder Reference to the CardHolder attempting to access the room.
     * @return true if access is granted, false otherwise.
     */
    virtual bool grantAccess(const CardHolder& cardHolder) const;

    /**
     * @brief Loads additional data from a file for Lecture_Hall.
     *
     * @param inFile Reference to the input file to read data from.
     */
    void loadFromFile(ifstream& inFile) {
        Room::loadFromFile(inFile); //call the base class loadFromFile
        //will write room data from file
    }

};