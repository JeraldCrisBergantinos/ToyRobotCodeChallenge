#include "rightcommandtest.h"

#include "../src/command.h"
#include "../src/position.h"
#include "../src/robot.h"
#include "../src/table.h"

#include <cassert>
#include <iostream>

RightCommandTest::RightCommandTest()
: pRobot(new Robot)
, pTable(new Table(5, 5))
, pRightCommand(new RightCommand(pRobot))
{
    //ctor
}

RightCommandTest::~RightCommandTest()
{
    //dtor
    delete pRightCommand;
    delete pTable;
    delete pRobot;
}

void RightCommandTest::ExecuteTests()
{
    std::cout << "Executing RIGHT command tests..." << std::endl;
    TestFacingNorth();
    TestFacingEast();
    TestFacingSouth();
    TestFacingWest();
}

void RightCommandTest::TestFacingNorth()
{
    Position* pPosition = new Position(1, 1, Position::NORTH);
    PlaceCommand(pRobot, pTable, pPosition).Execute();
    pRightCommand->Execute();
    std::cout << "When facing NORTH turns EAST" << std::endl;
    assert(pRobot->GetReport() == "1,1,EAST");
}

void RightCommandTest::TestFacingEast()
{
    Position* pPosition = new Position(1, 1, Position::EAST);
    PlaceCommand(pRobot, pTable, pPosition).Execute();
    pRightCommand->Execute();
    std::cout << "When facing EAST turns SOUTH" << std::endl;
    assert(pRobot->GetReport() == "1,1,SOUTH");
}

void RightCommandTest::TestFacingSouth()
{
    Position* pPosition = new Position(1, 1, Position::SOUTH);
    PlaceCommand(pRobot, pTable, pPosition).Execute();
    pRightCommand->Execute();
    std::cout << "When facing SOUTH turns WEST" << std::endl;
    assert(pRobot->GetReport() == "1,1,WEST");
}

void RightCommandTest::TestFacingWest()
{
    Position* pPosition = new Position(1, 1, Position::WEST);
    PlaceCommand(pRobot, pTable, pPosition).Execute();
    pRightCommand->Execute();
    std::cout << "When facing WEST turns NORTH" << std::endl;
    assert(pRobot->GetReport() == "1,1,NORTH");
}
