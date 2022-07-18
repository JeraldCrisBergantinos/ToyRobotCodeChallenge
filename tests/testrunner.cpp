#include "testrunner.h"
#include "commandertest.h"

#include "leftcommandtest.h"
#include "movecommandtest.h"
#include "placecommandtest.h"
#include "rightcommandtest.h"

#include "positiontest.h"
#include "robottest.h"
#include "tabletest.h"

#include <iostream>

void TestRunner::ExecuteTests()
{
    LeftCommandTest leftcommandTest;
    leftcommandTest.ExecuteTests();

    std::cout << "\n";
    MoveCommandTest moveCommandTest;
    moveCommandTest.ExecuteTests();

    std::cout << "\n";
    PlaceCommandTest placeCommandTest;
    placeCommandTest.ExecuteTests();

    std::cout << "\n";
    RightCommandTest rightCommandTest;
    rightCommandTest.ExecuteTests();

    std::cout << "\n";
    CommanderTest commanderTest;
    commanderTest.ExecuteTests();

    std::cout << "\n";
    PositionTest positionTest;
    positionTest.ExecuteTests();

    std::cout << "\n";
    RobotTest robotTest;
    robotTest.ExecuteTests();

    std::cout << "\n";
    TableTest tableTest;
    tableTest.ExecuteTests();
}
