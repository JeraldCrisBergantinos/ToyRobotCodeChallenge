#include "positiontest.h"

#include "../src/position.h"

#include <cassert>
#include <iostream>

PositionTest::PositionTest()
{
    //ctor
}

PositionTest::~PositionTest()
{
    //dtor
}

void PositionTest::ExecuteTests()
{
    std::cout << "Executing position tests..." << std::endl;
    TestGotoNorth();
    TestGotoSouth();
    TestGotoEast();
    TestGotoWest();
    TestEquality();

    TestTurnLeftFacingNorth();
    TestTurnLeftFacingWest();
    TestTurnLeftFacingSouth();
    TestTurnLeftFacingEast();

    TestTurnRightFacingNorth();
    TestTurnRightFacingEast();
    TestTurnRightFacingSouth();
    TestTurnRightFacingWest();
}

void PositionTest::TestGotoNorth()
{
    Position position(1, 1, Position::NORTH);
    Position newPosition(1, 2, Position::NORTH);
    std::cout << "Go to NORTH" << std::endl;
    assert(*position.Goto(Position::NORTH) == newPosition);
}

void PositionTest::TestGotoSouth()
{
    Position position(1, 1, Position::SOUTH);
    Position newPosition(1, 0, Position::SOUTH);
    std::cout << "Go to SOUTH" << std::endl;
    assert(*position.Goto(Position::SOUTH) == newPosition);
}

void PositionTest::TestGotoEast()
{
    Position position(1, 1, Position::EAST);
    Position newPosition(2, 1, Position::EAST);
    std::cout << "Go to EAST" << std::endl;
    assert(*position.Goto(Position::EAST) == newPosition);
}

void PositionTest::TestGotoWest()
{
    Position position(1, 1, Position::WEST);
    Position newPosition(0, 1, Position::WEST);
    std::cout << "Go to WEST" << std::endl;
    assert(*position.Goto(Position::WEST) == newPosition);
}

void PositionTest::TestEquality()
{
    Position position1(1, 1, Position::NORTH);
    Position position2(1, 1, Position::NORTH);
    std::cout << "Returns true when coordinates are the same in both positions" << std::endl;
    assert(position1 == position2);
}

void PositionTest::TestTurnLeftFacingNorth()
{
    Position position(1, 2, Position::NORTH);
    std::cout << "When facing NORTH, turning left is WEST" << std::endl;
    assert(position.GetDirectionLeft() == Position::WEST);
}

void PositionTest::TestTurnLeftFacingWest()
{
    Position position(1, 2, Position::WEST);
    std::cout << "When facing WEST, turning left is SOUTH" << std::endl;
    assert(position.GetDirectionLeft() == Position::SOUTH);
}

void PositionTest::TestTurnLeftFacingSouth()
{
    Position position(1, 2, Position::SOUTH);
    std::cout << "When facing SOUTH, turning left is EAST" << std::endl;
    assert(position.GetDirectionLeft() == Position::EAST);
}

void PositionTest::TestTurnLeftFacingEast()
{
    Position position(1, 2, Position::EAST);
    std::cout << "When facing EAST, turning left is NORTH" << std::endl;
    assert(position.GetDirectionLeft() == Position::NORTH);
}

void PositionTest::TestTurnRightFacingNorth()
{
    Position position(1, 2, Position::NORTH);
    std::cout << "When facing NORTH, turning right is EAST" << std::endl;
    assert(position.GetDirectionRight() == Position::EAST);
}

void PositionTest::TestTurnRightFacingEast()
{
    Position position(1, 2, Position::EAST);
    std::cout << "When facing EAST, turning right is SOUTH" << std::endl;
    assert(position.GetDirectionRight() == Position::SOUTH);
}

void PositionTest::TestTurnRightFacingSouth()
{
    Position position(1, 2, Position::SOUTH);
    std::cout << "When facing SOUTH, turning right is WEST" << std::endl;
    assert(position.GetDirectionRight() == Position::WEST);
}

void PositionTest::TestTurnRightFacingWest()
{
    Position position(1, 2, Position::WEST);
    std::cout << "When facing WEST, turning right is NORTH" << std::endl;
    assert(position.GetDirectionRight() == Position::NORTH);
}
