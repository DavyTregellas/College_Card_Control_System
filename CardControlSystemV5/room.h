/**
 * @file   Room.h
 * @brief  Header file for the Room class.
 *
 * The Room class is an abstract base class that represents different types of rooms in a building.
 * It includes common attributes such as building code, floor, room number, and room type.
 * Derived classes (e.g., Lecture_Hall, TeachingRoom, StaffRoom, SecureRoom) implement specific functionalities.
 */

#pragma once

#include <iostream>
#include "cardHolder.h" 

using namespace std;

/**
 * @enum CollegeRooms
 * @brief Enumerated type representing the types of college rooms.
 */
enum CollegeRooms {
    LECTURE_HALL,   /**< Lecture Hall room type. */
    TEACHING_ROOM,  /**< Teaching Room room type. */
    STAFF_ROOM,     /**< Staff Room room type. */
    SECURE_ROOM     /**< Secure Room room type. */
};

/**
 * @class Room
 * @brief Abstract base class representing different types of rooms in a building.
 */

class Room {
private:
    string buildingCode;    /**< Code identifying the building. */
    int floor;              /**< Floor where the room is located. */
    int roomNumber;         /**< Unique number assigned to the room. */
    CollegeRooms roomType;  /**< Type of the room (enumerated). */

public:
    /**
    * @brief Constructor for the Room class.
    * @param buildingCode Code identifying the building.
    * @param floor Floor where the room is located.
    * @param roomNumber Number assigned to the room.
    * @param roomType Type of the room (enumerated).
    */
    Room(string buildingCode, int floor, int roomNumber, CollegeRooms roomType)
        : buildingCode(buildingCode), floor(floor), roomNumber(roomNumber), roomType(roomType) {}

    /**
    * @brief Gets the type of the room.
    * @return Enumerated type representing the room type.
    */
    CollegeRooms getRoomType() const {
        return roomType;
    }

    /**
    * @brief Gets the room number.
     * @return Number assigned to the room.
    */

    int getRoomNumber() const {
        return roomNumber;
    }

    /**
    * @brief Gets the floor where the room is located.
    * @return Floor where the room is located.
    */

    int getFloor() const {
        return floor;
    }

    /**
    * @brief Gets the building code.
    * @return Code identifying the building.
    */

    string getBuildingCode() const {
        return buildingCode;
    }

    /**
    * @brief Function for saving room data to a file.
    * @param outFile Reference to the output file stream.
    */

    virtual void saveToFile(ofstream& outFile) const = 0;

    /**
    * @brief Function for loading room data from a file.
    * @param inFile Reference to the input file stream.
    */
    //loads room variables directly being the base class it has access
    //variables are written to file
    void loadFromFile(ifstream& inFile) {
        inFile >> buildingCode >> floor >> roomNumber;
    }
    /**
     * @brief Virtual destructor for the Room class.
     * Ensures proper destruction of derived class objects.
     */
    virtual ~Room() {}
    //this allows for tempoary objects to be created using a pointer to room
    //then that object is destroyed because one of the sub classes is chosen and that object is created.
    //this is where 'Room* newRoom = nullptr;' comes in. 

};

