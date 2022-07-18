#pragma once

class MoveCommand;
class Robot;
class Table;

// Tests on MoveCommand class.
class MoveCommandTest
{
    public:
        MoveCommandTest();
        virtual ~MoveCommandTest();

        // Executes tests in the private section.
        void ExecuteTests();

    private:
        Robot* pRobot;
        Table* pTable;
        MoveCommand* pMoveCommand;

        // Tests
        void TestDecreaseXFacingWest();     // Test MOVE command while facing WEST.
        void TestIncreaseXFacingEast();     // Test MOVE command while facing EAST.
        void TestIncreaseYFacingNorth();    // Test MOVE command while facing NORTH.
        void TestDecreaseYFacingSouth();    // Test MOVE command while facing SOUTH.
        void TestInvalidPosition();         // Test MOVE command when the next position will be invalid.
};
