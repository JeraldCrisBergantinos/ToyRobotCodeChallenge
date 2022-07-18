#pragma once

#include <string>

class Robot;
class Table;
class Position;

class BaseCommand
{
    public:
        BaseCommand(Robot* pRobot = nullptr, Table* pTable = nullptr, Position* pPosition = nullptr);
        virtual void Execute() = 0;
        virtual ~BaseCommand() {}

        // Used to retrieve description about the class.
        // Used for checking command type.
        virtual std::string GetDescription() const;

    protected:
        Robot* pRobot;
        Table* pTable;
        Position* pPosition;
};

// Rotates the robot to the left.
// Coordinates stay the same, direction changes to the next cardinal direction to the left.
class LeftCommand : public BaseCommand
{
    public:
        explicit LeftCommand(Robot* pRobot);
        virtual void Execute() override;
        virtual std::string GetDescription() const override;
};

// Attempts to move the robot 1 unit forward. If the new position is valid,
// Updates the robot's position. If it's invalid, nothing happens.
class MoveCommand : public BaseCommand
{
    public:
        MoveCommand(Robot* pRobot, Table* pTable);
        virtual void Execute() override;
        virtual std::string GetDescription() const override;
};

// Puts the robot at the given position, if position is valid.
// If the position is not valid, nothing happens
class PlaceCommand : public BaseCommand
{
    public:
        PlaceCommand(Robot* pRobot = nullptr, Table* pTable = nullptr, Position* pPosition = nullptr);
        virtual void Execute() override;
        virtual std::string GetDescription() const override;
};

// Prints the robot's current position to the standard output, in readable format
class ReportCommand : public BaseCommand
{
    public:
        explicit ReportCommand(Robot* pRobot);
        virtual void Execute() override;
        virtual std::string GetDescription() const override;
};

// Rotates the robot to the right.
// Coordinates stay the same, direction changes to the next cardinal direction to the right
class RightCommand : public BaseCommand
{
    public:
        explicit RightCommand(Robot* pRobot);
        virtual void Execute() override;
        virtual std::string GetDescription() const override;
};
