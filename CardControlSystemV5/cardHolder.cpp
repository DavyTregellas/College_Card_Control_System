/**
 * @file   cardHolder.cpp
 * @brief  Implementation file for the CardHolder class.
 *
 * This file implements two methods, saveToFile and loadFromFile, for the CardHolder class.
 * These methods are called during interactions with the user menu features when needing to save or load from external file.
 */

#include "cardHolder.h"

/**
 * @brief Loads data from a text file into a CardHolder object.
 *
 * This function reads the building code, name, and role data from the specified
 * input file and updates the CardHolder object accordingly. The college role is also reassigned correctly to its data-type.
 *
 * @param userLogLoad The input file stream from which the data will be read.
 * @return True if the data was successfully loaded; false otherwise.
 */

//load method for the saved file above
//the fuction has ifstream& userLog parameters, this is the read version
//using bool so it can return if the file was successfully loaded 
bool CardHolder::loadFromFile(ifstream& userLogLoad) {
    // >> reads the values of swipecardId and name in file
    if (userLogLoad >> swipeCardID >> name) {
        //swipeCardID and name was read successfully then procced to read role
        //create a varible to store role in roleValue
        int roleValue;
        //if successfully read data into roleValue 
        if (userLogLoad >> roleValue) {
            //now use staic_cast to convert roleValue back to enum datatype
            //I needed to be able to access the 'role' directly so took some of the loaduserfunction
            //and loaded users directly from within the class rather then using getters like for the save function   
            role = static_cast<CollegeRole>(roleValue);
            return true; //successfully read all values
        }
    }

    return false; //failed to read one or more values
}
