#pragma once

class RightCommand;
class Robot;
class Table;

// Tests on RightCommand class.
class RightCommandTest
{
    public:
        RightCommandTest();
        virtual ~RightCommandTest();

        // Executes tests in the private section.
        void ExecuteTests();

    private:
        Robot* pRobot;
        Table* pTable;
        RightCommand* pRightCommand;

        // Tests
        void TestFacingNorth();     // Test when facing NORTH.
        void TestFacingEast();      // Test when facing EAST.
        void TestFacingSouth();     // Test when facing SOUTH.
        void TestFacingWest();      // Test when facing WEST.
};
