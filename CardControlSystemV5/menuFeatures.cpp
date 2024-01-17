/**
 * @file menuFeatures.cpp
 * @brief Implementation file for MenuFeatures class.
 */

#include "menuFeatures.h"
#include "accessLog.h"

using namespace std;

MenuUserFeatures userFeatures2; /**< Global instance of MenuUserFeatures class. */
MenuRoomFeatures roomFeatures2; /**< Global instance of MenuRoomFeatures class. */

/**

 * @brief Simulates access for a specific cardholder in a given room.
 *
 * The simulateAccess function accurately simulates a user attempting to access any type of room.
 * It takes user input regarding the cardholder, room, and checks if the room's emergency mode is activated.
 * If a rooms emergency mode is turned on it automatically puts all rooms in that bulding into an emergency as per stated in the brief.
 * Different access permissions are required during emergency mode.
 * This function uses an if statement to determine whether to use the grantEmergencyAccess function or the specific room type's grantAccess function is needed.
 * 
 * @param cardHolders Vector of cardholders.
 *                    Allows flexible storage and manipulation of users.
 * 
 * @param roomLog Vector of Room pointers.
 *                Allows flexible storage and manipulation of instances of different room types.
 * 
 */
void MenuFeatures::simulateAccess(vector<CardHolder>& cardHolders, vector<Room*> roomLog) {

    Building KS("KS", false); /**< Building instance for KS building. */
    Building DT("DT", false); /**< Building instance for DT building. */

    bool emergencyMode; /**< Variable to store emergency mode status. */

    //calling viewUsers to give user some idea of what user they can be
    //this can easily be removed when many rooms are added
    userFeatures2.viewUsers(cardHolders); /**< Displays the list of cardholders. */

    string buildingCode; /**< Variable to store building code. */
    int floor, roomNumber; /**< Variables to store floor and room number. */
    int swipeCardID; /**< Variable to store swipe card ID. */
    int roomTypeChoice; /**< Variable to store room type choice. */

    //unique user ID is all that is needed to fid the card 
    cout << "Enter Swipe Card ID of the person you would like to simulate: ";
    cin >> swipeCardID;

    // Find the person with the specified Swipe Card ID
    //using find_if this allows me to search for elements within a vector header <algorithm> needed
    //.begin and .end definds the range od data it will search
    //auto key word used with find_if so compiler can infer the datatype found  
    auto searchiterator = find_if(cardHolders.begin(), cardHolders.end(),
        //[] defines what is being searched for the, in this case the id entered above
        //() in here is where we will search
        [swipeCardID](const CardHolder& person) {
            //using person.getSwipeCardID to compare until a match is found 
            return person.getSwipeCardID() == swipeCardID;
        });
    //if searchiterator isn't at the end of the vector range it means an id match
    if (searchiterator != cardHolders.end()) {
        //assign to simlultedUser in cardHolder Vector for grant access and logging use
        CardHolder& simulatedUser = *searchiterator;


        //calling view rooms to give user some idea of room they can simulate
        //this can easily be removed when many rooms are added
        roomFeatures2.viewSavedRooms(roomLog); /**< Displays the list of saved rooms. */

       //get user input for room they wish to 'enter'
        cout << "Enter building code: ";
        cin >> buildingCode;

        int choice;

        //first we need to determine which biulding the room is in to check the emergency status
        if (buildingCode == "KS") {
            choice = 1;
        }
        else if (buildingCode == "DT") {
            choice = 2;
        }
        else {
            cout << "\nBuilding does not exist!" << endl;
            return;
        }

        cout << "Enter floor: ";
        cin >> floor;
        cout << "Enter room number: ";
        cin >> roomNumber;

        //this will determine which subclass room is created below 
        cout << "\nSelect room type \n\t1 for Lecture Hall \n\t2 for Teaching Room \n\t3 for Staff Room \n\t4 for Secure Room\n";
        cin >> roomTypeChoice;

        //I have used a pointer to the Building Class, this points at the memory address selectedBuilding where I can store which building is being used 
        //intial assignment points to null, this is a constant in C++ which is bacically the same as having a empty building varible
        Building* selectedBuilding = nullptr;

        //using '&KS' '&DT' because I want to use the exsiting instnces of this object creted above 
        switch (choice) {
        case 1:
            selectedBuilding = &KS;
            break;
        case 2:
            selectedBuilding = &DT;
            break;
        default:
            return;
        }

        //using bool varible to determine if the user wants emergency mode on
        cout << "Enter 1 to turn Emergency Mode on, 0 to turn it off.\n";
        cin >> emergencyMode;

        //setEmergency sets the builkding ito emergency
        selectedBuilding->setEmergencyMode(emergencyMode);

        //if the emergency mode is set then the grantEmergencyAccess conditions will be used
        if (selectedBuilding->getEmergencyMode() == true) {
            if (selectedBuilding->grantEmergencyAccess(simulatedUser) == true) {
                cout << "\n\tEmergency Access has been Granted!\n";
            }
            else {
                cout << "\n\tBuilding in Emergency Mode Access Denied!\n";
            }
        }
        else {
            //I have used a pointer to the super class Room, this points at the memory address newRoom where I can store a type room object or one of its sub class objects
            //this allows me to create a instance of the one of the sub calss objests from the selection the user makes  
            //intial assignment points to null, this is a constant in C++ which is bacically the same as having a empty Room varible
            Room* simulatedRoom = nullptr;

            switch (roomTypeChoice) {
            case 1:
                simulatedRoom = new Lecture_Hall(buildingCode, floor, roomNumber);
                break;
            case 2:
                simulatedRoom = new Teaching_Room(buildingCode, floor, roomNumber);
                break;
            case 3:
                simulatedRoom = new Staff_Room(buildingCode, floor, roomNumber);
                break;
            case 4:
                simulatedRoom = new Secure_Room(buildingCode, floor, roomNumber);
                break;
            default:
                cout << "\nInvalid Room." << endl;
                return;
            }
            //setting up a bool variable here for the acces loggers information
            bool accessLog1 = false;

            //now dedending on which room was chosen the grantAccess function will be executed for specific room type
            switch (roomTypeChoice) {
            case 1: {
                Lecture_Hall newRoom("", 0, 0);  // You need to provide appropriate values

                //grantAccess for each room will take the simulatedUser to determine the access
                if (newRoom.grantAccess(simulatedUser)) {
                    cout << "\n\tAccess granted." << endl;
                    accessLog1 = true;

                }
                else {
                    cout << "\n\tAccess denied." << endl;
                }
                break;
            }
            case 2: {
                Teaching_Room newRoom("", 0, 0);
                if (newRoom.grantAccess(simulatedUser)) {
                    cout << "\n\tAccess granted." << endl;
                    accessLog1 = true;
                }
                else {
                    cout << "\n\tAccess denied." << endl;
                }
                break;
            }
            case 3: {
                Staff_Room newRoom("", 0, 0); 
                if (newRoom.grantAccess(simulatedUser)) {
                    cout << "\n\tAccess granted." << endl;
                    accessLog1 = true;
                }
                else {
                    cout << "\n\tAccess denied." << endl;
                }
                break;
            }
            case 4: {
                Secure_Room newRoom("", 0, 0);
                if (newRoom.grantAccess(simulatedUser)) {
                    cout << "\n\tAccess granted." << endl;
                    accessLog1 = true;
                }
                else {
                    cout << "\n\tAccess denied." << endl;
                }
                break;
            }
            default:
                cout << "\nInvalid Room." << endl;
                return;
            }

            //creat an instance of the Access Log class ready for logging
            AccessLog accessLog;

            //calling the log access function to record the attempted entry
            //passing user detials, room details and the access outcome
            accessLog.logAccess(simulatedUser, *simulatedRoom, accessLog1);

        }

    }
    else {
        cout << "User not found." << endl;
    }
}





