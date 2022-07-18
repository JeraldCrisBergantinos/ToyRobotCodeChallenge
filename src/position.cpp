#include "position.h"
#include <iostream>

Position::Position(int _iXCoord, int _iYCoord, Direction _direction)
: iXCoord(_iXCoord)
, iYCoord(_iYCoord)
, direction(_direction)
{
    //ctor
}

int Position::GetXCoordinate() const
{
    return iXCoord;
}

int Position::GetYCoordinate() const
{
    return iYCoord;
}

Position::Direction Position::GetDirection() const
{
    return direction;
}

Position* Position::Goto(Direction direction)
{
    switch (direction) {
        case NORTH: return GoNorth();
        case EAST:  return GoEast();
        case SOUTH: return GoSouth();
        case WEST:  return GoWest();
        default: {
            std::cout << "Invalid direction" << std::endl;
            return nullptr;
        }
    }
}

bool Position::operator==(const Position& other) const
{
    return iXCoord == other.iXCoord && iYCoord == other.iYCoord && direction == other.direction;
}

Position::Direction Position::GetDirectionLeft() const
{
    int iDir = static_cast<int>(direction);
    iDir--;     // Move down the enum.
    if (iDir < NORTH) iDir = DIRECTION_COUNT + iDir;    // Move from NORTH to WEST.
    return static_cast<Direction>(iDir);
}

Position::Direction Position::GetDirectionRight() const
{
    int iDir = static_cast<int>(direction);
    iDir++;     // Move up the enum.
    if (iDir > WEST) iDir = DIRECTION_COUNT - iDir;     // Move from WEST to NORTH.
    return static_cast<Direction>(iDir);
}

Position::Direction Position::ConvertDirectionFromString(const std::string& strDirection)
{
    if (strDirection == "NORTH") return NORTH;
    else if (strDirection == "EAST") return EAST;
    else if (strDirection == "SOUTH") return SOUTH;
    else if (strDirection == "WEST") return WEST;
    return INVALID_DIRECTION;
}

std::string Position::ConvertDirectionToString(Direction direction)
{
    switch (direction) {
        case NORTH: return "NORTH";
        case EAST: return "EAST";
        case SOUTH: return "SOUTH";
        case WEST: return "WEST";
        default: {
            std::cout << "Invalid direction" << std::endl;
            return "";
        }
    }
}

Position* Position::GoNorth()
{
    return new Position(iXCoord, iYCoord + 1, direction);
}

Position* Position::GoSouth()
{
    return new Position(iXCoord, iYCoord - 1, direction);
}

Position* Position::GoWest()
{
    return new Position(iXCoord - 1, iYCoord, direction);
}

Position* Position::GoEast()
{
    return new Position(iXCoord + 1, iYCoord, direction);
}
