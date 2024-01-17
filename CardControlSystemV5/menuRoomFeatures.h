/**
 * @file   MenuRoomFeatures.h
 * @brief  Header file for the MenuRoomFeatures class.
 *
 * The MenuRoomFeatures class provides functionalities related to room management in the Card Control System.
 * It includes methods for adding a room, deleting a room, and viewing saved rooms.
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
#include "staffRoom.h"
#include "secureRoom.h"

class MenuRoomFeatures {
public:

    /**
     * @brief Adds a new room to the system.
     *
     * This function allows users to add rooms to the system. User input regarding Building Code, Floor, and Room Number is required.
     * Users must also select the type of room they wish to create, as different room types have different access permissions.
     * The function creates a new object for the specified room type and saves it to the 'roomLog' vector.
     *
     * @param roomLog Reference to the vector containing pointers to Room objects.
     */
    static void addRoom(std::vector<Room*>& roomLog);

    /**
     * @brief Deletes a room from the system.
     *
     * Users can delete rooms from the system based on Building Code, Floor, and Room Number.
     * The function searches for the specified room in the 'roomLog' vector, deletes it, and rewrites the file without this room.
     *
     * @param roomLog Reference to the vector containing pointers to Room objects.
     */
    static void deleteRoom(std::vector<Room*>& roomLog);

    /**
     * @brief Views the saved rooms in the system.
     *
     * This function allows users to view all rooms saved in the system ('roomLog' vector).
     * The function loads the file and displays the room information line by line.
     *
     * @param roomLog Reference to the vector containing pointers to Room objects.
     */
    static void viewSavedRooms(std::vector<Room*>& roomLog);
};
