#include "robot.h"
#include "position.h"

Robot::Robot()
: pCurrentPosition(nullptr)
{
    //ctor
}

Robot::~Robot()
{
    //dtor
    if (pCurrentPosition != nullptr) {
        delete pCurrentPosition;
        pCurrentPosition = nullptr;
    }
}

Position* Robot::GetCurrentPosition() const
{
    return pCurrentPosition;
}

void Robot::SetCurrentPosition(Position* pPosition)
{
    if (pCurrentPosition != nullptr) delete pCurrentPosition;
    pCurrentPosition = pPosition;
}

std::string Robot::GetReport() const
{
    if (!IsPlaced()) return "not in place";

    // X,Y,DIRECTION
    std::string str = std::to_string(pCurrentPosition->GetXCoordinate());
    str += ",";
    str += std::to_string(pCurrentPosition->GetYCoordinate());
    str += ",";
    str += Position::ConvertDirectionToString(pCurrentPosition->GetDirection());
    return str;
}

bool Robot::IsPlaced() const
{
    return (pCurrentPosition != nullptr);
}
