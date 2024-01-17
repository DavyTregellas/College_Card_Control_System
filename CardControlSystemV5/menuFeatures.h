/**
 * @file   MenuFeatures.h
 * @brief  Header file for the MenuFeatures class.
 *
 * The MenuFeatures class provides functionalities for simulating access in the Card Control System.
 * It includes a method, simulateAccess, which simulates a cardholder attempting to access various rooms.
 */

#pragma once

#include "menuRoomFeatures.h"
#include "menuUserFeatures.h"
#include "lectureHall.h" 
#include "teachingRoom.h" 
#include "staffRoom.h"
#include "secureRoom.h"
#include "building.h"

using namespace std;

class MenuFeatures {
public:

    /**
     * @brief Simulates access for a specific cardholder in various rooms.
     *
     * The simulateAccess function simulates a cardholder attempting to access various rooms.
     * It takes user input regarding the cardholder, room, and whether the room's emergency mode is turned on.
     * If a room's emergency mode is turned on, it automatically puts all rooms in that building into an emergency mode.
     * The function uses an if statement to either use the grantEmergencyAccess function or the specific room type's grantAccess function.
     *
     * @param people Reference to the vector containing CardHolder objects representing system users.
     * @param roomLog Reference to the vector containing pointers to Room objects, storing information about different types of rooms.
     */
    static void simulateAccess(vector<CardHolder>& people, vector<Room*> roomLog);
};


