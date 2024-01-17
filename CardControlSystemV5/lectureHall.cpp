/**
 * @file   lectureHall.cpp
 * @brief  Implementation file for the Lecture_Hall class.
 *
 * This file contains the grantAccess method, which is specific
 * to accessing a Lecture Hall. Each room type has different permissions based on the
 * time and role of the CardHolder attempting to access them. Modifications to the
 * grantAccess method will directly impact access to Lecture Halls.
 *
 * Additionally, the file includes the implementation of the saveToFile method,
 * responsible for saving Lecture_Hall data. This functionality is accessed by
 * the menu room features.
 */

#include "lectureHall.h"
#include "cardHolder.h"
#include <ctime>

  /**
   * @brief Determines whether access is granted to the Lecture_Hall based on the CardHolder's role and current time.
   *
   * This method checks the role of the CardHolder and the current time.
   * I have used getRole() and time functions from ctime library to get this data.
   * Specific access permissions are defined using if and else-if statements.
   *
   * @param cardHolder Reference to the CardHolder attempting to access the room.
   * @return true if access is granted, false otherwise.
   */


bool Lecture_Hall::grantAccess(const CardHolder& cardHolder) const {

    //check if the card holder is a student if card holder is then execute code in if statement
    if (cardHolder.getRole() == STUDENT) {

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
    else if (cardHolder.getRole() == STAFF) {

        time_t timeNow = time(nullptr);
        tm currentTime;
        localtime_s(&currentTime, &timeNow);

        int currentHour = currentTime.tm_hour;
        int currentMinute = currentTime.tm_min;


        if ((currentHour == 5 && currentMinute >= 30) || (currentHour > 5 && currentHour < 23) || (currentHour == 23 && currentMinute <= 59)) {
            
            return true;
        }
        else {

            return false;
        }
    }
    else if (cardHolder.getRole() == VISITOR) {

        time_t timeNow = time(nullptr);
        tm currentTime;
        localtime_s(&currentTime, &timeNow);

        int currentHour = currentTime.tm_hour;
        int currentMinute = currentTime.tm_min;

        if ((currentHour == 8 && currentMinute >= 30) || (currentHour > 8 && currentHour < 22) || (currentHour == 22)) {

            return true;
        }
        else {

            return false;
        }
    }
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
            return true;
    }
    else if (cardHolder.getRole() == SECURITY) {
        return true;
    }
}

/**
 * @brief  Save Lecture_Hall data to a file.
 *
 * This method writes the specific data members of the Lecture_Hall object, including its type,
 * building code, floor, and room number, to the given output file.
 * Each room has this function allowing each type of room to be saved.
 *
 * @param outFile Reference to the output file stream where data will be saved.
 */


void Lecture_Hall::saveToFile(ofstream& outFile) const {
    //implement the saving logic specific to Lecture_Hall
    //write the data members of Lecture_Hall to the file
    outFile << "Lecture_Hall " << getBuildingCode() << " " << getFloor() << " " << getRoomNumber() << "\n";
}

