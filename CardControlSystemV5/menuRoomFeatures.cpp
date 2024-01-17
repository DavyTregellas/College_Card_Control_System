/**
 * @file   menuRoomFeatures.cpp
 * @brief  Implementation file for MenuRoomFeatures class.
 * 
 * This file is the room management file.
 *
 * This file contains three functions: 'addRoom', 'deleteRoom', and 'viewRoom'.
 * The functions are responsible for room-related operations. The design to have all room-related functions together is for easy maintenance.
 * A vector named 'roomLog' is used for temporary storage and data manipulation of room data in each function, and file manipulation is used for data storage.
 * This file manipulation can be easily adapted to store data in a database, which is a recommended approach this size and type of program.
 */
#include <iostream>
#include "menuRoomFeatures.h"


using namespace std;

MenuRoomFeatures roomFeatures1;

/**
 * @brief Adds a new room to the system.
 *
 * Allows users to add rooms to the system as per the system brief requirement.
 * User input includes Building Code, Floor, and Room Number.
 * The user selects the room type, this is vital because different rooms have different access permissions.
 * The function creates a new room object based on the type selected, which is then saved to the 'roomLog' file.
 *
 * @param roomLog Reference to the vector containing pointers to Room objects.
 *                Allows flexible storage and manipulation of instances of different room types.
 */
//add room funtion passes vector roomLog because I want to change the original vector not make a copy
void MenuRoomFeatures::addRoom(vector<Room*>& roomLog) {

    string buildingCode; /**< Variable to store building code. */
    int floor, roomNumber; /**< Variables to store floor and room number. */
    int roomTypeChoice; /**< Variable to store room type choice. */

    //above the varibles needed to add a room below asking user for input
    cout << "Enter building code: ";
    cin >> buildingCode;
    cout << "Enter floor number: ";
    cin >> floor;
    cout << "Enter room number: ";
    cin >> roomNumber;

    //user has to select the room type this will determain what sub class room object an instance  is created
    cout << "\nSelect Room Type: \n\t1 for Lecture Hall \n\t2 for Teaching Room \n\t3 for Staff Room \n\t4 for Secure Room\n";
    cin >> roomTypeChoice;

    //I have used a pointer to the super class Room, this points at the memory address newRoom where I can store a type room object or one of its sub class objects
    //this allows me to create a instance of the one of the sub calss objests from the selection the user makes  
    //intial assignment points to null, this is a constant in C++ which is bacically the same as having a empty Room varible
    Room* newRoom = nullptr;

    //using switch statement this allows me to run one of a few options of code
    switch (roomTypeChoice) {
    //each case holds one of the sub classes of room, the user has chosen the room type above and it is stored in rooTypeChoice
    case 1:
        //each case creates an object of that specific room from the data the user has entered above
        newRoom = new Lecture_Hall(buildingCode, floor, roomNumber);
        break;
    case 2:
        newRoom = new Teaching_Room(buildingCode, floor, roomNumber);
        break;
    case 3:
        newRoom = new Staff_Room(buildingCode, floor, roomNumber);
        break;
    case 4:
        newRoom = new Secure_Room(buildingCode, floor, roomNumber);
        break;
    default:
        cout << "Invalid Room." << endl;
        return;
    }

    //push_back is a function allows for adding element to the end of a vector#
    //newRoom holds new instance of a Room sub-class object, this is added to the roomLog vector
    roomLog.push_back(newRoom);

    //save the room details to a file using the specific class's method
    //open the file in append mode this allows for writing to a file with data already in it and will create a file if one can't be found
    ofstream outFile("roomLog.txt", ios::app);
    //check file got opened
    if (outFile.is_open()) {
        //using the subclass that has been selected call the saveToFile method from that subclass
        //each subclass has a simple saveToFile method derived from super-class
        newRoom->saveToFile(outFile);
        //close file after use
        outFile.close();
        cout << "Room added successfully." << endl;
    }
    else {
        cout << "Failed to open file for saving." << endl;
    }
}

/**
 * @brief Deletes a room from the system.
 *
 * Allows users to delete rooms from the system. User input Building Code, Floor, and Room Number is taken, this confirms the correct room to be deleted.
 * The function loads the 'roomLog' file, searches for the specified room, and creates a temporary file to write to. 
 * The index of the room that needs to be deleted is stored, so that room at that index is skipped when writing to the new file.
 * The original file is then replaced with the temporary file, effectively removing the specified room.
 * This is different to the user delete function because I need to make a room object.
 *
 * @param roomLog Reference to the vector containing pointers to Room objects.
 *                Allows flexible storage and manipulation of instances of different room types.
 */
//delete room funtion passes vector roomLog because I want to change the original vector not make a copy
void MenuRoomFeatures::deleteRoom(vector<Room*>& roomLog) {

    //call viewRoom function so user can see the rooms that are on the system
    roomFeatures1.viewSavedRooms(roomLog);

    string buildingCode; /**< Variable to store building code. */
    int floor, roomNumber; /**< Variables to store floor and room number. */

    //above the varibles needed to get room details below asking user for those details
    cout << "Enter building code: ";
    cin >> buildingCode;
    cout << "Enter floor number: ";
    cin >> floor;
    cout << "Enter room number: ";
    cin >> roomNumber;

    //find the room specified by user
    //using find_if this allows me to search for elements within a vector header <algorithm> needed
    //.begin and .end definds the range od data it will search
    //auto key word used with find_if so compiler can infer the datatype found  
    auto searchIterator = find_if(roomLog.begin(), roomLog.end(),
        //[] defines what is being searched for the, in this case the id entered above
        //() in here is where we will search
        [buildingCode, floor, roomNumber](const Room* room) {
            //comparing the buildingCode, Foor and RoomNumber to get the correct room
            return room->getBuildingCode() == buildingCode &&
                room->getFloor() == floor &&
                room->getRoomNumber() == roomNumber;
        });

    //if searchiterator isn't at the end of the vector range it means an id match 
    if (searchIterator != roomLog.end()) {
        //cout << "Room found at index: " << distance(roomLog.begin(), searchIterator) << endl;

        cout << "Room " << buildingCode << floor << roomNumber << " has been sucessfully removed." << endl;

        //the element in the vector that is a match is in searchiterator so we can use .erase to delete it
        roomLog.erase(searchIterator);
        //create temporary vector to hold the room data
        vector<Room*> updatedRoomLog;

        for (Room* room : roomLog) {
            if (!(room->getBuildingCode() == buildingCode &&
                room->getFloor() == floor &&
                room->getRoomNumber() == roomNumber)) {
                updatedRoomLog.push_back(room);
            }
        }
        //save updated tempoary vector back to file
        ofstream outFile("roomLog.txt");
        if (outFile.is_open()) {
            // Save the updatedRoomLog to the file
            for (const Room* room : updatedRoomLog) {
                room->saveToFile(outFile);
            }
            // Close the file
            outFile.close();
        }
        else {
            cout << "Failed to open file for writing." << endl;
        }

        //This (below) is the original way I was doing it, having a tempoary file
        // I would then write the updated room log to the tempoary file and delete the original file
        // this how ever gave me a lot of problems and didn't always work correctly
        // as I became more used to using vectors I decided to change this code.
        
        ////saving the updated vector to a tempoary file
        ////ofstream opens in write mode  
        //ofstream tempFile("tempRoomLog.txt");
        //if (tempFile.is_open()) {
        //    //for loop ensures all elements of vector are saved to file
        //    for (const Room* room : roomLog) {
        //        room->saveToFile(tempFile);
        //    }
        //    //close file 
        //    tempFile.close();

        //    //now I need have two files, the original must be deleted and the updated must be renamed
        //    //remove()==0 is a function that deletes a file if successfull it returns 0
        //    //rename()==0 is a function that renames a file if successfull it returns 0
        //    if (remove("roomLog.txt") == 0 && rename("tempRoomLog.txt", "roomLog.txt") == 0){
        //        //cout << "Room removed" << endl; Test purposes
        //    }
        //    else {
        //        //error handeling
        //        cout << "Failed to update file." << endl;
        //    }
        //}
        //else {
        //    //error handeling
        //    cout << "Failed to open temporary file." << endl;
        //}
    }
    else {
        //error handeling
        cout << "Room not found." << endl;
    }
}

/**
 * @brief Views the saved rooms in the system.
 *
 * Allows users to view all rooms saved in the system (stored in the 'roomLog' file).
 * The function loads the file in read mode and populates the 'roomLog' vector with room instances.
 * A for loop is then used to display room details on the screen.
 *
 * @param roomLog Reference to the vector containing pointers to Room objects.
 *                Allows flexible storage and manipulation of instances of different room types.
 */
//view room funtion passes vector roomLog because I want to change the original vector not make a copy
void MenuRoomFeatures::viewSavedRooms(vector<Room*>& roomLog) {

    //opens "roomLog.txt" in read mode 
    ifstream inFile("roomLog.txt");
    if (inFile.is_open()) {
        cout << "\nSaved Rooms:\n";
        string roomType;
        //while loop ensures all the lines in the file are loaded
        while (inFile >> roomType) {

            //I have used a pointer to the super class Room, this points at the memory address newRoom where I can store a type room object or one of its sub class objects
            //this allows me to create a instance of the one of the sub calss objests the if statements will use the room type to determine what instance is created 
            //intial assignment points to null, this is a constant in C++ which is bacically the same as having a empty Room varible
            Room* newRoom = nullptr;

            //if statements will use the room type to determine what instance is created 
            if (roomType == "Lecture_Hall") {
                //empty valuse that can be filled with data from file 
                newRoom = new Lecture_Hall("", 0, 0);
            }
            else if (roomType == "Teaching_Room") {
                newRoom = new Teaching_Room("", 0, 0);
            }
            else if (roomType == "Staff_Room") {
                newRoom = new Staff_Room("", 0, 0);
            }
            else if (roomType == "Secure_Room") {
                newRoom = new Secure_Room("", 0, 0);
            }
            else {
                cout << "Unknown room type in file." << endl;
                break;
            }

            //using .loadFromFile method to read and copy file data into vector
            //each sub-class has a loadFromFile which calls the super-class room loadFromFile
            //I am using ifstream in the room class where I can directly access the room variables  
            newRoom->loadFromFile(inFile);
            //keep adding rooms to the vector using .push_back while there is data in the file
            roomLog.push_back(newRoom);
            //displays the rooms to screen
            cout << "Room Type: " << roomType << " | Building Code: " << newRoom->getBuildingCode() << " | Floor Number: " << newRoom->getFloor() 
                << " | Room Number: " << newRoom->getRoomNumber() << endl;
        }
        inFile.close();
    }
    else {
        cout << "Failed to open file for reading." << endl;
    }
}


