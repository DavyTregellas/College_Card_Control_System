College Card Control System

Please find the full User Manual for this program inside the College_Card_Control_System folder (USER_MANUAL.txt). 

You can download this program as a zip file and run it on Visual studios 2022, you will need to have the googletest libraries to runs the tests.
This can be found and downloaded from github https://github.com/google/googletest. Alternatively please comment out gTest.cpp and gTest.h and the gTest calling code in main.cpp.
The code will run with this commented out on a pc  without gTest libraries.

Purpose of the Program

The card control system has been developed to grant or deny access to college rooms depending on specific criteria. 
The college has four different types of rooms; Lecture Hall, Teaching Room, Secure Room, Staff Room. 
Card holders are assigned the role they have at college, college roles; Staff, Student, Visitor / Guest, Contract Cleaner, Manager, Security. 
The program also allows for states of emergency where access can be granted to Emergency Responders.  

Program Overview

This object oriented program defines cardholders and rooms as objects, 
instances of these objects can be created and used within the features of the program. 
The program has a user interface, which allows the user to access a number of features, 
that will be described below.  
