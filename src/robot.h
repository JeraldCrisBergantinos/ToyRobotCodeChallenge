#pragma once

#include <string>

class Position;

class Robot
{
    public:
        Robot();
        virtual ~Robot();

        Position* GetCurrentPosition() const;
        void SetCurrentPosition(Position* pPosition);

        // Returns current x coordinate, y coordinate and direction in readable format:
        // X,Y,DIRECTION
        std::string GetReport() const;

        // Returns true if PLACE command with valid values was given.
        // Otherwise, false.
        bool IsPlaced() const;

    protected:

    private:
        Position* pCurrentPosition;
};
