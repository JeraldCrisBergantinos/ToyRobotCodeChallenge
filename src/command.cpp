#include "command.h"
#include "position.h"
#include "robot.h"
#include "table.h"

#include <iostream>

BaseCommand::BaseCommand(Robot* _pRobot, Table* _pTable, Position* _pPosition)
: pRobot(_pRobot)
, pTable(_pTable)
, pPosition(_pPosition)
{
    //ctor
}

std::string BaseCommand::GetDescription() const
{
    return "BaseCommand";
}

LeftCommand::LeftCommand(Robot* pRobot)
: BaseCommand(pRobot)
{
}

void LeftCommand::Execute()
{
    if (pRobot == nullptr) return;
    if (!pRobot->IsPlaced()) return;

    Position* pCurrentPosition = pRobot->GetCurrentPosition();
    pRobot->SetCurrentPosition(new Position(pCurrentPosition->GetXCoordinate(),
                                            pCurrentPosition->GetYCoordinate(),
                                            pCurrentPosition->GetDirectionLeft()));
}

std::string LeftCommand::GetDescription() const
{
    return "LeftCommand";
}

MoveCommand::MoveCommand(Robot* pRobot, Table* pTable)
: BaseCommand(pRobot, pTable)
{
}

void MoveCommand::Execute()
{
    if (pRobot == nullptr) return;
    if (!pRobot->IsPlaced()) return;

    Position* pCurrentPosition = pRobot->GetCurrentPosition();
    Position* pNewPosition = pCurrentPosition->Goto(pCurrentPosition->GetDirection());

    if (pTable == nullptr) return;
    if (pTable->IsPositionValid(*pNewPosition)) pRobot->SetCurrentPosition(pNewPosition);
}

std::string MoveCommand::GetDescription() const
{
    return "MoveCommand";
}

PlaceCommand::PlaceCommand(Robot* pRobot, Table* pTable, Position* pPosition)
: BaseCommand(pRobot, pTable, pPosition)
{
}

void PlaceCommand::Execute()
{
    if (pTable == nullptr) return;
    if (pPosition == nullptr) return;
    if (!pTable->IsPositionValid(*pPosition)) return;
    if (pRobot == nullptr) return;

    pRobot->SetCurrentPosition(pPosition);
}

std::string PlaceCommand::GetDescription() const
{
    return "PlaceCommand";
}

ReportCommand::ReportCommand(Robot* pRobot)
: BaseCommand(pRobot)
{
}

void ReportCommand::Execute()
{
    if (pRobot == nullptr);

    std::cout << pRobot->GetReport() << std::endl;
}

std::string ReportCommand::GetDescription() const
{
    return "ReportCommand";
}

RightCommand::RightCommand(Robot* pRobot)
: BaseCommand(pRobot)
{
}

void RightCommand::Execute()
{
    if (pRobot == nullptr) return;
    if (!pRobot->IsPlaced()) return;

    Position* pCurrentPosition = pRobot->GetCurrentPosition();
    pRobot->SetCurrentPosition(new Position(pCurrentPosition->GetXCoordinate(),
                                            pCurrentPosition->GetYCoordinate(),
                                            pCurrentPosition->GetDirectionRight()));
}

std::string RightCommand::GetDescription() const
{
    return "RightCommand";
}
