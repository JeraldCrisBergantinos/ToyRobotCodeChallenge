#pragma once

class Table;

// Tests on Table class.
class TableTest
{
    public:
        TableTest();
        virtual ~TableTest();

        // Executes tests in the private section.
        void ExecuteTests();

    private:
        Table* pTable;

        // Tests
        void TestXYValid();     // Test when X and X are valid.
        void TestXTooBig();     // Test when X is too big.
        void TestYTooBig();     // Test when Y is too big.
        void TestXYTooBig();    // Test when both X and Y are too big.
        void TestXNegative();   // Test when X is negative.
        void TestYNegative();   // Test when Y is negative.
        void TestXYNegative();  // Test when both X and Y are negative.
};
