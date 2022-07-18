#include "table.h"
#include "position.h"

Table::Table(int _iLength, int _iWidth)
: iLength(_iLength)
, iWidth(_iWidth)
{
    //ctor
}

bool Table::IsPositionValid(const Position& position) const
{
    // Check table boundaries.
    return (position.GetXCoordinate() < iLength &&
            position.GetYCoordinate() < iWidth &&
            position.GetXCoordinate() >= 0 &&
            position.GetYCoordinate() >= 0);
}
