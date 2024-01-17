/**
 * @file   main.cpp
 * @brief  Main entry point for the Card Control System.
 *
 * This program is for a local college, it is a software system for controlling access to rooms on the college site.
 * Features of the program include Adding and Deleting new Users and Room, Simulating access and putting a room and building into an emergency access mode.
 */

#include <conio.h> 
#include <windows.h>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <vector>
#include <fstream>
#include <string>
#include <cctype>

#include "menuRoomFeatures.h"
#include "menuUserFeatures.h"
#include "menuFeatures.h"
#include "room.h"
#include "cardHolder.h"
#include "lectureHall.h"    
#include "teachingRoom.h" 
#include "staffRoom.h"
#include "secureRoom.h"
#include "building.h"
#include "userMenu.h"

using namespace std;

vector<CardHolder> cardHolders; //Vector to store card holders.
vector<Room*> roomLog; //Vector to store rooms.

void clrscr(void);

MenuUserFeatures userFeatures; //Object for user features menu.
MenuRoomFeatures roomFeatures; //Object for room features menu.
MenuFeatures menuFeatures; //Object for general features menu.

Building menuBuilding; //Object representing the building.

/**
 * @brief Main function to run the Card Control System.
 *
 * This function serves as the menu for the Card Control System program. It displays a menu to the user,
 * allowing them to choose various actions such as adding rooms, adding users, viewing rooms and users,
 * simulating access, deleting rooms and users, activating emergency mode, and exiting the program.
 * The menu is displayed in a do-while loop to keep it running until the user chooses to exit.
 *
 * @return 0 on successful execution.
 */

void User_Menu::greetingMessage() {
    //this function from ctime gets the current time and stores it in varible 'timeNow'
    //this is retrieved in seconds since (01/Jan/1970) meaning a conversion will be needed
    time_t timeNow = time(nullptr);
    //tm is a specific data-type in C++ that allows you to store time data
    //varible 'currentTime created
    tm currentTime;
    //localtime_s is a function that converts the time data in 'timeNow' into the year, month, day, hour, minute, seconds.
    //this converted time now user friendly is stored in 'currentTime'
    localtime_s(&currentTime, &timeNow);

    //ostringstream writes data in definded memory (memory buffer) ready for use   
    ostringstream dateAndTime;
    //this deifines how to dislpay the string time, put_time() is a function that formats strings that represent time
    dateAndTime << put_time(&currentTime, "Time: %H:%M:%S \nDate: %Y-%m-%d ");

    // Print the greeting message along with the formatted time and date
    cout << "\t\tWelcome!\n" << dateAndTime.str() << endl;
}
void User_Menu::menu() {

    //variable to store user input
    char key;

    do {
        greetingMessage();//call the greeting message which displays the time and date
        cout << "\n\tCard Control System";
        cout << "\n\tWhat would you like to do...";
        cout << "\n\tPress '1' to Add Room";
        cout << "\n\tPress '2' to Add User";
        cout << "\n\tPress '3' to View Rooms";
        cout << "\n\tPress '4' to View Users";
        cout << "\n\tPress '5' to Delete Room";
        cout << "\n\tPress '6' to Delete User";
        cout << "\n\tPress '7' Simulate User Access";
        cout << "\n\tPress '8' Emergency Mode Feature";
        cout << "\n\tTo Exit press '9'\n\t";

        do {
            cin >> key;
        } while (key != '1' && key != '2' && key != '3' && key != '4' && key != '5' && key != '6' && key != '7' && key != '8' && key != '9');

        cout << "\n\tChoice = " << key << "\n";

        clrscr();
        //using switch statement to allow users to choose features of program
        switch (key) {
        case '1':
            roomFeatures.addRoom(roomLog);
            break;
        case '2':
            userFeatures.addUser(cardHolders);
            break;
        case '3':
            roomFeatures.viewSavedRooms(roomLog);
            break;
        case '4':
            userFeatures.viewUsers(cardHolders);
            break;
        case '5':
            roomFeatures.deleteRoom(roomLog);
            break;
        case '6':
            userFeatures.deleteUser(cardHolders);
            break;
        case '7':
            menuFeatures.simulateAccess(cardHolders, roomLog);
            break;
        case '8':
            menuBuilding.setRoomToEmergency(menuBuilding);
            break;
        case '9':
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (key != '9');
}

/**
 * @brief Moves the cursor to the specified coordinates on the console window.
 * @param x The x-coordinate.
 * @param y The y-coordinate.
 */
void gotoxy(int x, int y) {
    static HANDLE hStdout = NULL;
    COORD coord;

    coord.X = x;
    coord.Y = y;
    if (!hStdout) { hStdout = GetStdHandle(STD_OUTPUT_HANDLE); }
    SetConsoleCursorPosition(hStdout, coord);
}

/**
 * @brief Clears the console screen.
 */
void clrscr(void) {
    static HANDLE hStdout = NULL;
    static CONSOLE_SCREEN_BUFFER_INFO csbi;
    const COORD startCoords = { 0, 0 };
    DWORD dummy;

    if (!hStdout) {
        hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
        GetConsoleScreenBufferInfo(hStdout, &csbi);
    }
    FillConsoleOutputCharacter(hStdout, ' ', csbi.dwSize.X * csbi.dwSize.Y, startCoords, &dummy);
    gotoxy(0, 0);
}