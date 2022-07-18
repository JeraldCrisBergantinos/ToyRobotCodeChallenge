#include "leftcommandtest.h"

#include "../src/command.h"
#include "../src/position.h"
#include "../src/robot.h"
#include "../src/table.h"

#include <cassert>
#include <iostream>

LeftCommandTest::LeftCommandTest()
: pRobot(new Robot)
, pTable(new Table(5, 5))
, pLeftCommand(new LeftCommand(pRobot))
{
    //ctor
}

LeftCommandTest::~LeftCommandTest()
{
    //dtor
    delete pLeftCommand;
    delete pTable;
    delete pRobot;
}

void LeftCommandTest::ExecuteTests()
{
    std::cout << "Executing LEFT command tests..." << std::endl;
    TestFacingNorth();
    TestFacingWest();
    TestFacingSouth();
    TestFacingEast();
}

void LeftCommandTest::TestFacingNorth()
{
    Position* pPosition = new Position(1, 1, Position::NORTH);
    PlaceCommand(pRobot, pTable, pPosition).Execute();
    pLeftCommand->Execute();
    std::cout << "When facing NORTH turns WEST" << std::endl;
    assert(pRobot->GetReport() == "1,1,WEST");
}

void LeftCommandTest::TestFacingWest()
{
    Position* pPosition = new Position(1, 1, Position::WEST);
    PlaceCommand(pRobot, pTable, pPosition).Execute();
    pLeftCommand->Execute();
    std::cout << "When facing WEST turns SOUTH" << std::endl;
    assert(pRobot->GetReport() == "1,1,SOUTH");
}

void LeftCommandTest::TestFacingSouth()
{
    Position* pPosition = new Position(1, 1, Position::SOUTH);
    PlaceCommand(pRobot, pTable, pPosition).Execute();
    pLeftCommand->Execute();
    std::cout << "When facing SOUTH turns EAST" << std::endl;
    assert(pRobot->GetReport() == "1,1,EAST");
}

void LeftCommandTest::TestFacingEast()
{
    Position* pPosition = new Position(1, 1, Position::EAST);
    PlaceCommand(pRobot, pTable, pPosition).Execute();
    pLeftCommand->Execute();
    std::cout << "When facing EAST turns NORTH" << std::endl;
    assert(pRobot->GetReport() == "1,1,NORTH");
}
