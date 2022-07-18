#pragma once

class Robot;
class Table;

// Tests on Robot class.
class RobotTest
{
    public:
        RobotTest();
        virtual ~RobotTest();

        // Executes tests in the private section.
        void ExecuteTests();

    private:
        Table* pTable;

        // Tests
        void TestPlaceValidPosition();          // Test when position for PLACE command is valid.
        void TestPlaceInvalidPosition();        // Test when position for PLACE command is invalid.
        void TestReportBeforeAndAfterPlace();   // Test report output before and after PLACE command.
        void TestReportShort();                 // Test report output after PLACE command (shorter test).
        void TestPlaceAndTurnLeft();            // Test after giving PLACE and LEFT commands.
        void TestPlaceAndTurnRight();           // Test after giving PLACE and RIGHT commands.
        void TestPlaceAndMoveNorth();           // Test after giving PLACE and MOVE commands facing NORTH.
        void TestPlaceAndMoveSouth();           // Test after giving PLACE and MOVE commands facing SOUTH.
        void TestPlaceAndMoveEast();            // Test after giving PLACE and MOVE commands facing EAST.
        void TestPlaceAndMoveWest();            // Test after giving PLACE and MOVE commands facing WEST.
        void TestReportBeforePlace();           // Test report output ignoring commands before PLACE command.
        void TestIsPlaced();                    // Test IsPlaced() function before and after PLACE command.
};
