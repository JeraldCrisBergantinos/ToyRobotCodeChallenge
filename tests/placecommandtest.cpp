#include "placecommandtest.h"

#include "../src/command.h"
#include "../src/position.h"
#include "../src/robot.h"
#include "../src/table.h"

#include <cassert>
#include <iostream>

PlaceCommandTest::PlaceCommandTest()
: pTable(new Table(5, 5))
{
    //ctor
}

PlaceCommandTest::~PlaceCommandTest()
{
    //dtor
    delete pTable;
}

void PlaceCommandTest::ExecuteTests()
{
    std::cout << "Executing PLACE command tests..." << std::endl;
    TestValidPosition();
    TestInvalidPosition();
}

void PlaceCommandTest::TestValidPosition()
{
    Robot robot;
    Position* pPosition = new Position(1, 1, Position::NORTH);
    PlaceCommand(&robot, pTable, pPosition).Execute();
    std::cout << "With valid position" << std::endl;
    assert(robot.GetReport() == "1,1,NORTH");
}

void PlaceCommandTest::TestInvalidPosition()
{
    Robot robot;
    Position* pPosition = new Position(-1, 1, Position::NORTH);
    PlaceCommand(&robot, pTable, pPosition).Execute();
    std::cout << "With invalid position" << std::endl;
    assert(robot.GetReport() == "not in place");
}
