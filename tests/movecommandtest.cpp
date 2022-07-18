#include "movecommandtest.h"

#include "../src/command.h"
#include "../src/position.h"
#include "../src/robot.h"
#include "../src/table.h"

#include <cassert>
#include <iostream>

MoveCommandTest::MoveCommandTest()
: pRobot(new Robot)
, pTable(new Table(5, 5))
, pMoveCommand(new MoveCommand(pRobot, pTable))
{
    //ctor
}

MoveCommandTest::~MoveCommandTest()
{
    //dtor
    delete pMoveCommand;
    delete pTable;
    delete pRobot;
}

void MoveCommandTest::ExecuteTests()
{
    std::cout << "Executing MOVE command tests..." << std::endl;
    TestDecreaseXFacingWest();
    TestIncreaseXFacingEast();
    TestIncreaseYFacingNorth();
    TestDecreaseYFacingSouth();
    TestInvalidPosition();
}

void MoveCommandTest::TestDecreaseXFacingWest()
{
    Position* pPosition = new Position(1, 1, Position::WEST);
    PlaceCommand(pRobot, pTable, pPosition).Execute();
    pMoveCommand->Execute();
    std::cout << "Decreases X when robot is facing WEST" << std::endl;
    assert(pRobot->GetReport() == "0,1,WEST");
}

void MoveCommandTest::TestIncreaseXFacingEast()
{
    Position* pPosition = new Position(1, 1, Position::EAST);
    PlaceCommand(pRobot, pTable, pPosition).Execute();
    pMoveCommand->Execute();
    std::cout << "Increases X when robot is facing EAST" << std::endl;
    assert(pRobot->GetReport() == "2,1,EAST");
}

void MoveCommandTest::TestIncreaseYFacingNorth()
{
    Position* pPosition = new Position(1, 1, Position::NORTH);
    PlaceCommand(pRobot, pTable, pPosition).Execute();
    pMoveCommand->Execute();
    std::cout << "Increases Y when robot is facing NORTH" << std::endl;
    assert(pRobot->GetReport() == "1,2,NORTH");
}

void MoveCommandTest::TestDecreaseYFacingSouth()
{
    Position* pPosition = new Position(1, 1, Position::SOUTH);
    PlaceCommand(pRobot, pTable, pPosition).Execute();
    pMoveCommand->Execute();
    std::cout << "Decreases Y when robot is facing SOUTH" << std::endl;
    assert(pRobot->GetReport() == "1,0,SOUTH");
}

void MoveCommandTest::TestInvalidPosition()
{
    Position* pPosition = new Position(4, 4, Position::NORTH);
    PlaceCommand(pRobot, pTable, pPosition).Execute();
    pMoveCommand->Execute();
    std::cout << "Does nothing when position is invalid" << std::endl;
    assert(pRobot->GetReport() == "4,4,NORTH");
}
