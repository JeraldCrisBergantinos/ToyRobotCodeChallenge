#include "robottest.h"

#include "../src/command.h"
#include "../src/position.h"
#include "../src/robot.h"
#include "../src/table.h"

#include <cassert>
#include <iostream>

RobotTest::RobotTest()
: pTable(new Table(5, 7))
{
    //ctor
}

RobotTest::~RobotTest()
{
    //dtor
    delete pTable;
}

void RobotTest::ExecuteTests()
{
    std::cout << "Executing robot tests..." << std::endl;
    TestPlaceValidPosition();
    TestPlaceInvalidPosition();
    TestReportBeforeAndAfterPlace();
    TestReportShort();
    TestPlaceAndTurnLeft();
    TestPlaceAndTurnRight();
    TestPlaceAndMoveNorth();
    TestPlaceAndMoveSouth();
    TestPlaceAndMoveEast();
    TestPlaceAndMoveWest();
    TestReportBeforePlace();
    TestIsPlaced();
}

void RobotTest::TestPlaceValidPosition()
{
    Robot robot;
    Position* pPosition = new Position(2, 3, Position::NORTH);
    PlaceCommand(&robot, pTable, pPosition).Execute();
    std::cout << "With valid position, places robot in the correct position" << std::endl;
    assert(*robot.GetCurrentPosition() == *pPosition);
}

void RobotTest::TestPlaceInvalidPosition()
{
    Robot robot;
    Position* pPosition = new Position(9, 9, Position::NORTH);
    PlaceCommand(&robot, pTable, pPosition).Execute();
    std::cout << "With invalid position, will not place robot" << std::endl;
    assert(robot.GetCurrentPosition() == nullptr);
}

void RobotTest::TestReportBeforeAndAfterPlace()
{
    Robot robot;
    Position* pPosition = new Position(2, 3, Position::NORTH);

    std::cout << "Before initial placement of the robot, reports error message" << std::endl;
    assert(robot.GetReport() == "not in place");

    PlaceCommand(&robot, pTable, pPosition).Execute();
    std::cout << "After initial placement of the robot, reports current position correctly" << std::endl;
    assert(robot.GetReport() == "2,3,NORTH");
}

void RobotTest::TestReportShort()
{
    Robot robot;
    Position* pPosition = new Position(1, 1, Position::NORTH);
    PlaceCommand(&robot, pTable, pPosition).Execute();
    std::cout << "Returns a short report" << std::endl;
    assert(robot.GetReport() == "1,1,NORTH");
}

void RobotTest::TestPlaceAndTurnLeft()
{
    Robot robot;
    Position* pPosition = new Position(1, 1, Position::NORTH);
    PlaceCommand(&robot, pTable, pPosition).Execute();
    LeftCommand(&robot).Execute();
    std::cout << "When placed correctly, correctly turns to the left" << std::endl;
    assert(robot.GetReport() == "1,1,WEST");
}

void RobotTest::TestPlaceAndTurnRight()
{
    Robot robot;
    Position* pPosition = new Position(1, 1, Position::NORTH);
    PlaceCommand(&robot, pTable, pPosition).Execute();
    RightCommand(&robot).Execute();
    std::cout << "When placed correctly, correctly turns to the right" << std::endl;
    assert(robot.GetReport() == "1,1,EAST");
}

void RobotTest::TestPlaceAndMoveNorth()
{
    Robot robot;
    Position* pPosition = new Position(1, 1, Position::NORTH);
    PlaceCommand(&robot, pTable, pPosition).Execute();
    MoveCommand(&robot, pTable).Execute();
    std::cout << "When placed correctly, correctly moves NORTH" << std::endl;
    assert(robot.GetReport() == "1,2,NORTH");
}

void RobotTest::TestPlaceAndMoveSouth()
{
    Robot robot;
    Position* pPosition = new Position(1, 1, Position::SOUTH);
    PlaceCommand(&robot, pTable, pPosition).Execute();
    MoveCommand(&robot, pTable).Execute();
    std::cout << "When placed correctly, correctly moves SOUTH" << std::endl;
    assert(robot.GetReport() == "1,0,SOUTH");
}

void RobotTest::TestPlaceAndMoveEast()
{
    Robot robot;
    Position* pPosition = new Position(1, 1, Position::EAST);
    PlaceCommand(&robot, pTable, pPosition).Execute();
    MoveCommand(&robot, pTable).Execute();
    std::cout << "When placed correctly, correctly moves EAST" << std::endl;
    assert(robot.GetReport() == "2,1,EAST");
}

void RobotTest::TestPlaceAndMoveWest()
{
    Robot robot;
    Position* pPosition = new Position(1, 1, Position::WEST);
    PlaceCommand(&robot, pTable, pPosition).Execute();
    MoveCommand(&robot, pTable).Execute();
    std::cout << "When placed correctly, correctly moves WEST" << std::endl;
    assert(robot.GetReport() == "0,1,WEST");
}

void RobotTest::TestReportBeforePlace()
{
    Robot robot;
    MoveCommand(&robot, pTable).Execute();
    LeftCommand(&robot).Execute();
    RightCommand(&robot).Execute();
    std::cout << "Before being placed in a table, ignores other commands" << std::endl;
    assert(robot.GetReport() == "not in place");
}

void RobotTest::TestIsPlaced()
{
    Robot robot;
    std::cout << "Before robot is placed, IsPlaced returns false" << std::endl;
    assert(robot.IsPlaced() == false);

    Position* pPosition = new Position(1, 2, Position::EAST);
    PlaceCommand(&robot, pTable, pPosition).Execute();
    std::cout << "After robot is placed, IsPlaced returns true" << std::endl;
    assert(robot.IsPlaced() == true);
}
