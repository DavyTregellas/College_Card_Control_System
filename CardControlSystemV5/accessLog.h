/**
 * @file   accessLog.h
 * @brief  Header file for AccessLog Class
 *
 * This file represents a daily access log and what the daily access log should contain.
 */

#pragma once

#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <sstream>
#include "cardHolder.h"
#include "room.h"

class AccessLog {
private:
    std::ofstream logFile;

public:

    void logAccess(const CardHolder& cardHolder, const Room& room, bool accessGranted);

private:
    void openLogFile();

};