#pragma once

// Tests on Position class.
class PositionTest
{
    public:
        PositionTest();
        virtual ~PositionTest();

        // Executes tests in the private section.
        void ExecuteTests();

    private:
        // Tests
        void TestGotoNorth();               // Test when changing direction to NORTH.
        void TestGotoSouth();               // Test when changing direction to SOUTH.
        void TestGotoEast();                // Test when changing direction to EAST.
        void TestGotoWest();                // Test when changing direction to WEST.
        void TestEquality();                // Test equality of 2 Position instances.

        void TestTurnLeftFacingNorth();     // Test new direction while facing NORTH and turning left.
        void TestTurnLeftFacingWest();      // Test new direction while facing WEST and turning left.
        void TestTurnLeftFacingSouth();     // Test new direction while facing SOUTH and turning left.
        void TestTurnLeftFacingEast();      // Test new direction while facing EAST and turning left.

        void TestTurnRightFacingNorth();    // Test new direction while facing NORTH and turning right.
        void TestTurnRightFacingEast();     // Test new direction while facing EAST and turning right.
        void TestTurnRightFacingSouth();    // Test new direction while facing SOUTH and turning right.
        void TestTurnRightFacingWest();     // Test new direction while facing WEST and turning right.
};
