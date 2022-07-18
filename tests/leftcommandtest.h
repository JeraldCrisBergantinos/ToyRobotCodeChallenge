#pragma once

class LeftCommand;
class Robot;
class Table;

// Tests on LeftCommand class.
class LeftCommandTest
{
    public:
        LeftCommandTest();
        virtual ~LeftCommandTest();

        // Executes tests in the private section.
        void ExecuteTests();

    private:
        Robot* pRobot;
        Table* pTable;
        LeftCommand* pLeftCommand;

        // Tests
        void TestFacingNorth();     // Test after LEFT command while facing NORTH.
        void TestFacingWest();      // Test after LEFT command while facing WEST.
        void TestFacingSouth();     // Test after LEFT command while facing SOUTH.
        void TestFacingEast();      // Test after LEFT command while facing EAST.
};
