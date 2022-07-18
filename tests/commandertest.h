#pragma once

class Commander;
class Robot;
class Table;

// Tests on Commander class.
class CommanderTest
{
    public:
        CommanderTest();
        virtual ~CommanderTest();

        // Executes tests in the private section.
        void ExecuteTests();

    private:
        Robot* pRobot;
        Table* pTable;
        Commander* pCommander;

        // Tests
        void TestPlaceCommand();    // Test output class after giving PLACE command.
        void TestMoveCommand();     // Test output class after giving MOVE command.
        void TestLeftCommand();     // Test output class after giving LEFT command.
        void TestRightCommand();    // Test output class after giving RIGHT command.
        void TestReportCommand();   // Test output class after giving REPORT command.
        void TestInvalidCommand();  // Test output class after giving invalid command.
};
