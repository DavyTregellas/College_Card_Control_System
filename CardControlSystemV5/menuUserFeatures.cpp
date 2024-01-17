/**
 * @file   menuUserFeatures.cpp
 * @brief  Implementation file for MenuUserFeatures class.
 * 
 * This file is the user management file.
 * 
 * This file contains five functions: 'addUser', 'deleteUser', 'viewUsers', 'saveUsersToFile' and 'loadUsersFromFile'.
 * The functions are responsible for user-related operations. The design to have all user-related functions together is for easy maintenance.
 * A vector named 'cardHolders' is used for temporary storage and data manipulation of user data in each function, and file manipulation is used for data storage.
 * This file manipulation can be easily adapted to store data in a database, which is a recommended approach this size and type of program.
 *
 */

#include "menuUserFeatures.h"
#include <fstream>
#include <algorithm>

MenuUserFeatures userFeatures1;

using namespace std;

/**
 * @brief Adds a new cardholder to the system.
 *
 * Allows users to add cardholders to the system. User input includes Swipe Card ID, Name, and User Role.
 * The function creates a new CardHolder object based on the user input and adds it to the vector 'cardHolders'.
 * The updated vector is then saved to the 'users.txt' file.
 *
 * @param cardHolders Reference to the vector containing CardHolder objects.
 *                   Enables flexible storage and manipulation of cardholder data.
 */

//add user function passing the vector, I am using & cardHolders because I want the original vector to be changed not copied.
void MenuUserFeatures::addUser(vector<CardHolder>& cardHolders) {

    int swipeCardID;/**< Variable to store swipCardID. */
    string name;/**< Variable to store name. */
    int roleChoice;/**< Variable to store roleChoice choice. */

    //above varibles and below asking user for input 
    cout << "Enter Swipe Card ID: ";
    cin >> swipeCardID;
    cout << "Enter Name: ";
    //this stops the nweline character being read as a empty string. 
    cin.ignore();
    //now retieve the string name from here
    getline(cin, name);
    cout << "\nSelect User Role: \n\t1 for Staff \n\t2 for Students \n\t3 for Visitor/Guest \n\t4 for Cleaner/Contractor \n\t5 for Manager \n\t6 for Security\n\t7 for Emergency Responder\n";
    cin >> roleChoice;
    //gives user a choice of what role the new user is
    CollegeRole role;
    switch (roleChoice) {
    case 1:
        role = STAFF;
        break;
    case 2:
        role = STUDENT;
        break;
    case 3:
        role = VISITOR;
        break;
    case 4:
        role = CLEANER;
        break;
    case 5:
        role = MANAGER;
        break;
    case 6:
        role = SECURITY;
    case 7:
        role = EMERGENCY_RESPONDER;
        break;
    default:
        cout << "Invalid role. Person not added." << endl;
        return;
    }

    //create a new person object based on the user input
    CardHolder newPerson(swipeCardID, name, role);

    //add the new person to the vector using .pushback
    cardHolders.push_back(newPerson);

    //save the updated vector to the file using the save file function below
    saveUsersToFile(cardHolders);

    cout << "Person added successfully." << endl;

    //print vector after adding the person for test purposes
    viewUsers(cardHolders);
}

/**
 * @brief Deletes a cardholder from the system.
 *
 * Allows users to delete cardholders from the system. User input includes Swipe Card ID for confirming the cardholder to be removed.
 * The function searches for the specified cardholder, removes it from the vector 'cardHolders', and saves the updated vector to the 'users.txt' file.
 * This is different from the room deletion function because I don't need to make an instance of an object.
 *
 * @param cardHolders Reference to the vector containing CardHolder objects.
 *                   Enables flexible storage and manipulation of cardholder data.
 */

//delete user function passing the vector, I am using & cardHolders because I want the original vector to be changed not copied.
void MenuUserFeatures::deleteUser(vector<CardHolder>& cardHolders) {
    userFeatures1.viewUsers(cardHolders);
    int swipeCardID;
    cout << "Enter Swipe Card ID of the person to remove: ";
    cin >> swipeCardID;

    // Find the person with the specified Swipe Card ID
    //using find_if this allows me to search for elements within a vector header <algorithm> needed
    //.begin and .end definds the range od data it will search
    //auto key word used with find_if so compiler can infer the datatype found  
    auto searchiterator = find_if(cardHolders.begin(), cardHolders.end(),
        //[] defines what is being searched for the, in this case the id entered above
        //() in here is where we will search
        [swipeCardID](const CardHolder& user) {
            //using person.getSwipeCardID to compare until a match is found 
            return user.getSwipeCardID() == swipeCardID;
        });
    //if searchiterator isn't at the end of the vector range it means an id match 
    if (searchiterator != cardHolders.end()) {
        //the element in the vector that is a match is in searchiterator so we can use .erase to delete it
        cardHolders.erase(searchiterator);

        //save the updated vector to the file
        saveUsersToFile(cardHolders);

        cout << "Person removed successfully." << endl;
    }
    else {
        cout << "Person not found. No person removed." << endl;
    }
}

/**
 * @brief Views the list of saved cardholders in the system.
 *
 * Loads cardholder data from the 'users.txt' file, adds to the 'cardHolders' vector, and displays the list of cardholders on the screen.
 *
 * @param cardHolders Reference to the vector containing CardHolder objects.
 *                   Facilitates flexible storage and manipulation of cardholder data.
 */

//view the list of saved users function passing the vector, I am using & cardHolders because I want the original vector to be changed not copied.
void MenuUserFeatures::viewUsers(const vector<CardHolder>& cardHolders) {

    //calling load user function so vector is populated with saved users 
    loadUsersFromFile(const_cast<vector<CardHolder>&>(cardHolders));

    //check if vector is empty
    if (cardHolders.empty()) {
        cout << "No users to display." << endl;
        return;
    }
    //if vector is not empty use for loop to display users.
    cout << "List of Users:" << endl;
    //iterates over each element in cardholders vector, savedUsers represents each element in vector
    for (const CardHolder& savedUser : cardHolders) {
        cout << "Swipe Card ID: " << savedUser.getSwipeCardID() << " | Name: " << savedUser.getName()
            << " | Role: " << savedUser.getRoleAsString() << endl;
    }
}

/**
 * @brief Saves cardholders to a file.
 *
 * Opens the 'users.txt' file in write mode and writes cardholder data from the 'cardHolders' vector to the file.
 *
 * @param cardHolders Reference to the vector containing CardHolder objects.
 *                   Enables flexible storage and manipulation of cardholder data.
 */

//save users to a file function passing the vector, I am using & cardHolders because I want the original vector to be changed not copied.
void MenuUserFeatures::saveUsersToFile(const vector<CardHolder>& cardHolders) {
    //ofstream used to open file in write mode 
    ofstream userLog("users.txt");
    //check file was opened/created ok
    if (userLog) {
        //write all users data to file 
        for (const CardHolder& user : cardHolders) {
            //using getters from cardHolder class, I have also used static cast to convert role into int for saving 
            userLog << user.getSwipeCardID() << " " << user.getName() << " " << static_cast<int>(user.getRole()) << "\n";
        }
        //very important to close file once finished
        userLog.close();
    }
    //error handleing if there is a problem creating file
    else {
        cout << "Error opening file for writing users.\n";
    }
}

/**
 * @brief Loads cardholders from a file.
 *
 * Clears existing data from the 'cardHolders' vector, opens the 'users.txt' file in read mode,
 * and reads cardholder data from the file, adding the 'cardHolders' vector.
 *
 * @param cardHolders Reference to the vector containing CardHolder objects.
 *                   Enables flexible storage and manipulation of cardholder data.
 */

//load users from a file passing the vector, I am using & cardHolders because I want the original vector to be changed not copied.
void MenuUserFeatures::loadUsersFromFile(vector<CardHolder>& cardHolders) {
    //clear data from vector, this is to stop any unwanted duplicates 
    cardHolders.clear();

    //ifstream used to open file in read mode
    ifstream userLogLoad("users.txt");
    //check file was opened ok
    if (userLogLoad) {

        //using default constuctor that doesn't require any arguments
        //creating an empty cardHolder object 'user' as a temporay holder for the data before it is pushed 'push_back' into the vector
        CardHolder user;

        //read user data from the file using the loadFromFile method
        //keep adding users to the vector while there is data in the file
        //using .loadFromFile method to read and copy file data into vector
        while (user.loadFromFile(userLogLoad)) {
            cardHolders.push_back(user);
        }
        //very important to close file once finished
        userLogLoad.close();
    }
    else {
        cout << "Error opening file for reading users.\n";
    }
}


