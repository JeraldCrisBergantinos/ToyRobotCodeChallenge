#pragma once

class Position;

class Table
{
    public:
        Table(int iLength, int iWidth);

        // Checks if position is valid.
        // Coordinates x and y can't be negative, and can't be larger than table size.
        bool IsPositionValid(const Position& position) const;

    private:
        int iLength;
        int iWidth;
};
