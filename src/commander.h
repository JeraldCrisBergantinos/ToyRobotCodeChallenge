#pragma once

#include <string>

class BaseCommand;
class Robot;
class Table;

// Class for parsing string commands.
// Outputs command based on the string command.
class Commander
{
    public:
        Commander(Robot& robot, Table& table);

        // Parses string command and outputs the appropriate command.
        BaseCommand* Parse(std::string strCommand);

    private:
        Robot& robot;
        Table& table;
};

