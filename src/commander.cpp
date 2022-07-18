#include "commander.h"
#include "command.h"
#include "position.h"
#include "robot.h"
#include "table.h"

#include <iostream>
#include <regex>
#include <sstream>

Commander::Commander(Robot& _robot, Table& _table)
: robot(_robot)
, table(_table)
{
    //ctor
}

BaseCommand* Commander::Parse(std::string strCommand)
{
    // Convert string command to uppercase.
    // Remove spaces.
    transform(strCommand.begin(), strCommand.end(), strCommand.begin(), ::toupper);
    strCommand.erase(std::remove_if(strCommand.begin(), strCommand.end(), ::isspace), strCommand.end());

    if (strCommand.rfind("PLACE", 0) == 0) {
        // Remove 'PLACE' from the string.
        strCommand.erase(0, 5);

        // Parse PLACE values.
        std::stringstream ss(strCommand);
        std::string temp;
        int iCnt = 0;           // Position of value
        int iX = 0;             // X coordinate
        int iY = 0;             // Y coordinate
        std::string strDir;     // Direction in string
        while (std::getline(ss, temp, ',')) {
            if (iCnt == 0) iX = stoi(temp);
            else if (iCnt == 1) iY = stoi(temp);
            else if (iCnt == 2) {
                strDir = temp;
                break;
            }
            iCnt++;
        }

        // Check if direction is valid.
        Position::Direction direction = Position::ConvertDirectionFromString(strDir);
        if (direction == Position::INVALID_DIRECTION) return nullptr;

        // Will place the robot in table.
        return new PlaceCommand(&robot, &table, new Position(iX, iY, direction));
    }
    else if (strCommand.rfind("MOVE", 0) == 0) return new MoveCommand(&robot, &table);  // Will move the robot forward.
    else if (strCommand.rfind("LEFT", 0) == 0) return new LeftCommand(&robot);          // Will turn the robot left.
    else if (strCommand.rfind("RIGHT", 0) == 0) return new RightCommand(&robot);        // Will turn the robot right.
    else if (strCommand.rfind("REPORT", 0) == 0) return new ReportCommand(&robot);      // Will output report about the rebot.

    // Invalid command. Ignore.
    return nullptr;
}
