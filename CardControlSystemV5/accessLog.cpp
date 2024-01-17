/**
 * @file   accessLog.cpp
 * @brief  Implementation file for the AccessLog class.
 *
 * This file contians the functions logging the any access attempt made bya a card holder. 
 * The function will recorder card holder, room and access data which is then stored in the daily access log.
 * The feature is currently storing this data however it is not fully functional as the user can't view the daily access log from the user interface.
 */


#include "accessLog.h"

using namespace std;

void AccessLog::logAccess(const CardHolder& cardHolder, const Room& room, bool accessGranted) {
    //call function to open the file
    openLogFile();
    //check the file has been opened correctly with no errors
    if (!logFile.is_open()) {
        openLogFile();
    }

    //this function from ctime gets the current time and stores it in varible 'timeNow'
    //this is retrieved in seconds since (01/Jan/1970) meaning a conversion will be needed
    time_t now = time(nullptr);
    //tm is a specific data-type in C++ that allows you to store time data
    //varible 'currentTime created
    tm currentTime;
    //localtime_s is a function that converts the time data in 'timeNow' into the year, month, day, hour, minute, seconds.
    //this converted time now user friendly is stored in 'currentTime'
    localtime_s(&currentTime, &now);

    //ostringstream writes data in definded memory (memory buffer) ready for use   
    ostringstream dateAndTime;
    //this deifines how to dislpay the string time, put_time() is a function that formats strings that represent time
    dateAndTime << put_time(&currentTime, "%Y-%m-%d %H:%M:%S");
    //writes the data to this file, writing datenadtime using string str() fromatting function  
    logFile << "Date and Time: " << dateAndTime.str() << endl;
    logFile << "User Name: " << cardHolder.getName() << endl;
    logFile << "Swipe Card ID: " << cardHolder.getSwipeCardID() << endl;
    logFile << "Building Code: " << room.getBuildingCode() << endl;
    logFile << "Room: " << room.getBuildingCode() << room.getFloor() << room.getRoomNumber() << endl;
    //special bool parameter used to allow for yes or no to be written
    logFile << "Access Granted: " << (accessGranted ? "Yes" : "No") << endl;
    logFile << endl;

    if (logFile.is_open()) {
        logFile.close();
    }
}


void AccessLog::openLogFile() {
    //getting the time the same way as above and storing it in memory buffer 'logFileName'
    ostringstream logFileName;
    
    time_t now = time(nullptr);
    tm currentTime;
    localtime_s(&currentTime, &now);
    //how room_access_log will save with the date
    logFileName << "room_access_log_" << put_time(&currentTime, "%Y-%m-%d") << ".txt";
    //opening the file in append mode, this means you can write and add to file
    logFile.open(logFileName.str(), ios::app);
    //check that file was correctly opened
    if (!logFile.is_open()) {
        cerr << "Error: Could not open log file." << endl;
    }
}
