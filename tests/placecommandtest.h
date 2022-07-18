#pragma once

class Table;

// Tests on PlaceCommand class.
class PlaceCommandTest
{
    public:
        PlaceCommandTest();
        virtual ~PlaceCommandTest();

        // Executes tests in the private section.
        void ExecuteTests();

    private:
        Table* pTable;

        // Tests
        void TestValidPosition();       // Test when position in PLACE command is valid.
        void TestInvalidPosition();     // Test when position in PLACE command is invalid.
};
