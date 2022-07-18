#include "commandertest.h"

#include "../src/command.h"
#include "../src/commander.h"
#include "../src/robot.h"
#include "../src/table.h"

#include <cassert>
#include <iostream>

CommanderTest::CommanderTest()
: pRobot(new Robot)
, pTable(new Table(5, 5))
, pCommander(new Commander(*pRobot, *pTable))
{
    //ctor
}

CommanderTest::~CommanderTest()
{
    //dtor
    delete pCommander;
    delete pTable;
    delete pRobot;
}

void CommanderTest::ExecuteTests()
{
    std::cout << "Executing commander tests..." << std::endl;
    TestPlaceCommand();
    TestMoveCommand();
    TestLeftCommand();
    TestRightCommand();
    TestReportCommand();
    TestInvalidCommand();
}

void CommanderTest::TestPlaceCommand()
{
    BaseCommand* pCommand = pCommander->Parse("PLACE 1, 1, NORTH");
    std::cout << "Parsing PLACE command, expecting PlaceCommand pointer" << std::endl;
    assert(pCommand != nullptr);
    assert(pCommand->GetDescription() == "PlaceCommand");
}

void CommanderTest::TestMoveCommand()
{
    BaseCommand* pCommand = pCommander->Parse("MOVE");
    std::cout << "Parsing MOVE command, expecting MoveCommand pointer" << std::endl;
    assert(pCommand != nullptr);
    assert(pCommand->GetDescription() == "MoveCommand");
}

void CommanderTest::TestLeftCommand()
{
    BaseCommand* pCommand = pCommander->Parse("LEFT");
    std::cout << "Parsing LEFT command, expecting LeftCommand pointer" << std::endl;
    assert(pCommand != nullptr);
    assert(pCommand->GetDescription() == "LeftCommand");
}

void CommanderTest::TestRightCommand()
{
    BaseCommand* pCommand = pCommander->Parse("RIGHT");
    std::cout << "Parsing RIGHT command, expecting RightCommand pointer" << std::endl;
    assert(pCommand != nullptr);
    assert(pCommand->GetDescription() == "RightCommand");
}

void CommanderTest::TestReportCommand()
{
    BaseCommand* pCommand = pCommander->Parse("REPORT");
    std::cout << "Parsing REPORT command, expecting ReportCommand pointer" << std::endl;
    assert(pCommand != nullptr);
    assert(pCommand->GetDescription() == "ReportCommand");
}

void CommanderTest::TestInvalidCommand()
{
    BaseCommand* pCommand = pCommander->Parse("asdfg");
    std::cout << "Parsing invalid command, expecting null pointer" << std::endl;
    assert(pCommand == nullptr);
}
