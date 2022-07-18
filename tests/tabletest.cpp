#include "tabletest.h"
#include "../src/position.h"
#include "../src/table.h"

#include <cassert>
#include <iostream>

TableTest::TableTest()
: pTable(new Table(5, 5))
{
    //ctor
}

TableTest::~TableTest()
{
    //dtor
    delete pTable;
}

void TableTest::ExecuteTests()
{
    std::cout << "Executing table tests..." << std::endl;
    TestXYValid();
    TestXTooBig();
    TestYTooBig();
    TestXYTooBig();
    TestXNegative();
    TestYNegative();
    TestXYNegative();
}

void TableTest::TestXYValid()
{
    Position position(2, 3, Position::NORTH);

    std::cout << "Returns true when x and y are valid" << std::endl;
    assert(pTable->IsPositionValid(position));
}

void TableTest::TestXTooBig()
{
    Position position(8, 2, Position::NORTH);

    std::cout << "Returns false when X is too big" << std::endl;
    assert(!pTable->IsPositionValid(position));
}

void TableTest::TestYTooBig()
{
    Position position(2, 8, Position::NORTH);

    std::cout << "Returns false when Y is too big" << std::endl;
    assert(!pTable->IsPositionValid(position));
}

void TableTest::TestXYTooBig()
{
    Position position(8, 8, Position::NORTH);

    std::cout << "Returns false when X and Y are too big" << std::endl;
    assert(!pTable->IsPositionValid(position));
}

void TableTest::TestXNegative()
{
    Position position(-1, 2, Position::NORTH);

    std::cout << "Returns false when X is negative" << std::endl;
    assert(!pTable->IsPositionValid(position));
}

void TableTest::TestYNegative()
{
    Position position(2, -1, Position::NORTH);

    std::cout << "Returns false when Y is negative" << std::endl;
    assert(!pTable->IsPositionValid(position));
}

void TableTest::TestXYNegative()
{
    Position position(-1, -1, Position::NORTH);

    std::cout << "Returns false when X and Y are too big" << std::endl;
    assert(!pTable->IsPositionValid(position));
}
