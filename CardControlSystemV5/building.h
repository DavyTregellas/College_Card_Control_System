#pragma once

#include <iostream>
#include "cardHolder.h"

using namespace std;

/**
 * @file   building.h
 * @brief  Header file for the Building class.
 *
 * The Building class represents a physical building in the Card Control System. It includes methods to manage emergency mode and grant emergency access.
 */

class Building {
private:
    string buildingCode; /**< The unique code identifying the building. */
    bool emergencyMode; /**< Flag indicating whether the building is in emergency mode. */

public:

    /**
    * @brief Constructor to initialize a Building object with a building code and emergency mode status.
    *
    * @param code The unique code identifying the building.
    * @param emergencyMode Flag indicating whether the building is in emergency mode. Default is false.
    */

    Building(const string& code, bool emergencyMode = false) : buildingCode(code), emergencyMode(emergencyMode) {
    }

    /**
    * @brief Default constructor for the Building class.
    */

    Building() = default; //now I am able to create an instance without perameters

    /**
    * @brief Getter method to retrieve the building code.
    *
    * @return A constant reference to the building code.
    */

    const string& getBuildingCode() const {
        return buildingCode;
    }

    /**
     * @brief Getter method to check if the building is in emergency mode.
     *
     * @return true if the building is in emergency mode, false otherwise.
     */

    bool getEmergencyMode() const {
        return emergencyMode;
    }

    /**
    * @brief Setter method to update the emergency mode status of the building.
    *
     * @param newEmergencyMode The new emergency mode status to set.
     */

    void setEmergencyMode(bool newEmergencyMode) {
        emergencyMode = newEmergencyMode;
    }

    /**
    * @brief Grants emergency access based on the card holder's role.
    *
    * This function checks the role of the CardHolder to determine whether emergency access should be granted.
    *
    * @param cardHolder Reference to the CardHolder attempting emergency access.
    * @return true if emergency access is granted, false otherwise.
     */

    bool grantEmergencyAccess(const CardHolder& cardHolder);

    /**
    * @brief Allows users to set rooms in emergency mode.
    *
    * This function is the emergency mode feature. It takes imput from users regarding the room they want to set in an emergency.
    * The function then sets the whole building into an emergency.
    *
    * @param building a reference to the building that will be set to emergency.
    */

    void setRoomToEmergency(Building& building);

};
