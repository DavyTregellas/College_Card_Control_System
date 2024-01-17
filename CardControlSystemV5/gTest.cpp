/**
 * @file   gTest.cpp
 * @brief  Implementation file for the gTest.
 *
 * This file contains unit testing and regression testing for the grant access functions.
 * Granting correct access to user is the fundamental functionality of this program, so testing it with dedicated testing tools is essential for the integrity of the program.
 * 
 */

#pragma once

#include "gTest.h"

// Use TEST_F to define the test
TEST_F(MenuFeaturesTest, SimulateSecurityGuardAccessInAllRoomsTest) {
    // Arrange
    CardHolder collegePerson = createCollegeRole();
    Lecture_Hall lectureHall = createLectureHall();
    Teaching_Room teachingRoom = createTeachingRoom();
    Staff_Room staffRoom = createStaffRoom();
    Secure_Room secureRoom = createSecureRoom();

    // Act
    bool accessGrantedInLectureHall = lectureHall.grantAccess(collegePerson);
    bool accessGrantedInTeachingRoom = teachingRoom.grantAccess(collegePerson);
    bool accessGrantedInStaffRoom = staffRoom.grantAccess(collegePerson);
    bool accessGrantedInSecureRoom = secureRoom.grantAccess(collegePerson);

    // Assert
    ASSERT_TRUE(accessGrantedInLectureHall);
    ASSERT_TRUE(accessGrantedInTeachingRoom);
    ASSERT_TRUE(accessGrantedInStaffRoom);
    ASSERT_TRUE(accessGrantedInSecureRoom);
}

 //Use TEST_F to define the test
TEST_F(MenuFeaturesTest, RegressionTestGrantAccess) {
    // Arrange
    CardHolder collegePerson = createCollegeRole();
    Lecture_Hall lectureHall = createLectureHall();

    // Act
    bool accessGranted = lectureHall.grantAccess(collegePerson);

    // Assert
    ASSERT_TRUE(accessGranted);
}