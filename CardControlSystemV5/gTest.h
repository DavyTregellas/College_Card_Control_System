/**
 * @file   gTest.h
 * @brief Header file for gTest Class
 *
 * This file contains the rooms, and card holder that will be tested.
 *
 */

#pragma once

#include "menuFeatures.h"
#include "gtest/gtest.h"

//define a fixture class for your tests
class MenuFeaturesTest : public ::testing::Test {
protected:
    //create a CardHolder, I can easily change the role for different tests 
    CardHolder createCollegeRole() {
        return CardHolder(21, "MrTest", SECURITY);
    }
    //I have created and instance of each room-type this way I can 
    // test entry to multiple rooms at one time 
    Lecture_Hall createLectureHall() {
        return Lecture_Hall("DT", 2, 21);
    }
    Teaching_Room createTeachingRoom() {
        return Teaching_Room("KS", 3, 22);
    }
    Staff_Room createStaffRoom() {
        return Staff_Room("KS", 2, 23);
    }
    Secure_Room createSecureRoom() {
        return Secure_Room("DT", 3, 24);
    }
};