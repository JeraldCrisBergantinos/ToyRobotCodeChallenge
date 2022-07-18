#pragma once

#include <string>

// X is the robot's HORIZONTAL position.
// Y is the robot's VERTICAL position.
// See the chart below:
// Y cooordinate
//       ^
//       |
//       |
//       |
//       +-------> X coordinate

class Position
{
    public:
        // These are the four main cardinal directions: North, East, South and West.
        // See the chart below:
        //      N
        //      |
        //      |
        // W----+-----E
        //      |
        //      |
        //      S
        enum Direction {
            INVALID_DIRECTION = -1,
            NORTH,
            EAST,
            SOUTH,
            WEST,
            DIRECTION_COUNT
        };

        Position(int iXCoord, int iYCoord, Direction direction);

        // Getter functions for X, Y, and direction.
        int GetXCoordinate() const;
        int GetYCoordinate() const;
        Direction GetDirection() const;

        // Used for generating new direction.
        Position* Goto(Direction direction);

        // Overloaded equality operator.
        bool operator==(const Position& position) const;

        // These helper methods return THE NEXT cardinal direction of a given position,
        // to the LEFT and to the RIGHT, respectively
        Direction GetDirectionLeft() const;
        Direction GetDirectionRight() const;

        // Helper function for converting direction.
        static Direction ConvertDirectionFromString(const std::string& strDirection);
        static std::string ConvertDirectionToString(Direction direction);

    private:
        int iXCoord;
        int iYCoord;
        Direction direction;

        Position* GoNorth();
        Position* GoSouth();
        Position* GoWest();
        Position* GoEast();
};
