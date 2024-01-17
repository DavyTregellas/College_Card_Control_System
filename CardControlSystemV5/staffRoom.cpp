/**
 * @file   staffRoom.cpp
 * @brief  Implementation file for the Staff_Room class.
 *
 * This file contains the grantAccess method, which is specific
 * to accessing a Staff Room. Each room type has different permissions based on the
 * time and role of the CardHolder attempting to access them. Modifications to the
 * grantAccess method will directly impact access to Staff Room.
 *
 * Additionally, the file includes the implementation of the saveToFile method,
 * responsible for saving Staff_Room data. This functionality is accessed by
 * the menu room features.
 */

#include "staffRoom.h"
#include "cardHolder.h"
#include <ctime>

/**
 * @brief Determines whether access is granted to the Staff_Room based on the CardHolder's role and current time.
 *
 * This method checks the role of the CardHolder and the current time.
 * I have used getRole() and time functions from ctime library to get this data.
 * Specific access permissions are defined using if and else-if statements.
 *
 * @param cardHolder Reference to the CardHolder attempting to access the room.
 * @return true if access is granted, false otherwise.
 */

bool Staff_Room::grantAccess(const CardHolder& cardHolder) const {

    bool emergencyMode = false;

    //check if the card holder is a student if card holder is then execute code in if statement
    if (cardHolder.getRole() == STUDENT) {

        return false;

    }

    else if (cardHolder.getRole() == STAFF) {

        //this function from ctime gets the current time and stores it in varible 'timeNow'
        //this is retrieved in seconds since (01/Jan/1970) meaning a conversion will be needed
        time_t timeNow = time(nullptr);
        //tm is a specific data-type in C++ that allows you to store time data
        //varible 'currentTime created
        tm currentTime;
        //localtime_s is a function that converts the time data in 'timeNow' into the year, month, day, hour, minute, seconds.
        //this converted time now user friendly is stored in 'currentTime'
        localtime_s(&currentTime, &timeNow);

        //now the time is stored corectly in a tm data-type I can access the hours and minutes to make my if condition 
        int currentHour = currentTime.tm_hour;
        int currentMinute = currentTime.tm_min;

        //if statement checks if the time aligns with the specific time for this role to access this room, found in assignment brief  
        if ((currentHour == 8 && currentMinute >= 30) || (currentHour > 8 && currentHour < 22) || (currentHour == 22)) {
            //returning true to grant access
            return true;
        }
        else {
            //returning false to deny access
            return false;
        }
    }
    //all following code in this function is using the same features and logic as the commented code above 

    else if (cardHolder.getRole() == CLEANER) {

        time_t timeNow = time(nullptr);
        tm currentTime;
        localtime_s(&currentTime, &timeNow);


        int currentHour = currentTime.tm_hour;
        int currentMinute = currentTime.tm_min;

        if ((currentHour == 5 && currentMinute >= 30) || (currentHour > 5 && currentHour < 10)) {

            return true;
        }
        else if ((currentHour == 17 && currentMinute >= 30) || (currentHour > 17 && currentHour <= 22) || (currentHour == 22 && currentMinute <= 30)) {

            return true;
        }
        else {

            return false;
        }
    }
    else if (cardHolder.getRole() == MANAGER) {
        if (emergencyMode == false) {
            return true;
        }
        else {

            return false;
        }
    }
    else if (cardHolder.getRole() == SECURITY) {
        return true;
    }
}

/**
 * @brief  Save Staff_Room data to a file.
 *
 * This method writes the specific data members of the Staff_Room object, including its type,
 * building code, floor, and room number, to the given output file.
 * Each room has this function allowing each type of room to be saved.
 *
 * @param outFile Reference to the output file stream where data will be saved.
 */

void Staff_Room::saveToFile(ofstream& outFile) const {
    //implement the saving logic specific to Staff_Room
    //write the data members of Staff_Room to the file
    outFile << "Staff_Room " << getBuildingCode() << " " << getFloor() << " " << getRoomNumber() << "\n";
}