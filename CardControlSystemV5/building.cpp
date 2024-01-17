/**
 * @file   building.cpp
 * @brief  Implementation file for the Building class.
 *
 * This file holds all the emergency access functions. 
 * The brief states that if one of its rooms goes into emergency mode, the entire building must follow suit.
 * As a result of this, I have desinded the system to handel all emergency access permissions within the Building class.
 */

#include "building.h"
#include "cardholder.h"

 /**
  * @brief Sets a specific room to emergency mode and adjusts building access accordingly.
  *
  * This function allows the user to set a room in an emergency. 
  * The function specifically uses that building code given by the user.
  * With the building code it uses the setEmergencyModeForBuilding function to put the building into an emergency.
  * This will alter the access permissions for every room within that building.
  * The function also informs the user that the changes have been made.
  */

void Building::setRoomToEmergency(Building& building) {
    //create instances of buildings the college has
    Building KS("KS", false);
    Building DT("DT", false);

    string buildingCode;
    int floor, roomNumber;
    //get building code from user
    cout << "Enter building code: ";
    cin >> buildingCode;

    int choice;

    //check the building exists
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
    //get further infromation from the user about the specific room going into an emergency
    cout << "Enter floor: ";
    cin >> floor;
    cout << "Enter room number: ";
    cin >> roomNumber;

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

    //bool varible to hold the users choice
    bool emergencyMode;
    //now the user can turn the emergency mode on or off
    cout << "Enter 1 to turn Emergency Mode on, 0 to turn it off for " << building.getBuildingCode() << ": ";
    cin >> emergencyMode;

    if (emergencyMode == true) {
        //set emergency
        building.setEmergencyMode(emergencyMode);
        //print out the details of the room that is in an emergency
        cout << "\nRoom Number " << roomNumber << " on Floor " << floor << " emergency mode has been set."
        << "\nThis has also changed the access for the entire " << buildingCode << " building!\n";
    }
    else if (emergencyMode == false) {
        //set emergency
        building.setEmergencyMode(emergencyMode);
        //print out the details of the room that has had the emergency mode turned off
        cout << "\nRoom Number " << roomNumber << " on Floor " << floor << " emergency mode has turned off."
        << "\nThis has also changed the access for the entire " << buildingCode << " building!\n";
    }
    else {
     cout << "Invalid choice. Please enter 0 or 1." << endl;
     // handle the error or ask the user to enter a valid choice
     return;
    }
}


/**
 * @brief Grants emergency access based on the role of a CardHolder.
 *
 * This function determines whether a CardHolder should be granted emergency access based on their role.
 * Certain roles (e.g., SECURITY, EMERGENCY_RESPONDER) are granted access, while others are denied.
 *
 * @param cardHolder The CardHolder for whom to check emergency access
 * 
 * @return True if emergency access is granted, false otherwise.
 */

//grantemergency access, will deny access to all roles apart from emergency responder and security
bool Building::grantEmergencyAccess(const CardHolder& cardHolder){
    //checks what role has been passed then returns a bool value
    if (cardHolder.getRole() == STUDENT) {
        return false;
    }
    else if (cardHolder.getRole() == STAFF) {
        return false;
    }
    else if (cardHolder.getRole() == VISITOR) {
        return false;;
    }
    else if (cardHolder.getRole() == CLEANER) {
        return false;
    }
    else if (cardHolder.getRole() == MANAGER) {
        return false;        
    }
    else if (cardHolder.getRole() == SECURITY) {
        return true;        
    }
    else if (cardHolder.getRole() == EMERGENCY_RESPONDER) {
        return true;  
    }
}
