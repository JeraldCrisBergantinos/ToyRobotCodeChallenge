#include "src/commander.h"
#include "src/command.h"
#include "src/robot.h"
#include "src/table.h"

#include "tests/testrunner.h"

#include <iostream>
#include <regex>

void Run()
{
    // Initializes a new 5x5 table, a new robot, and a new command interpreter.
    Table table(5, 5);
    Robot robot;
    Commander commander(robot, table);

    std::cout << "Toy Robot Code Challenge" << std::endl;
    std::cout << "Input command (EXIT to quit): " << std::endl;

    std::string strInput;

    // Keeps reading commands from stdin until user types EXIT.
    do {
        getline(std::cin, strInput);

        BaseCommand* pCommand = commander.Parse(strInput);
        if (pCommand == nullptr) {
            // Convert string to uppercase and remove spaces.
            // This could be the exit command.
            transform(strInput.begin(), strInput.end(), strInput.begin(), ::toupper);
            strInput.erase(std::remove_if(strInput.begin(), strInput.end(), ::isspace), strInput.end());
            continue;
        }

        pCommand->Execute();    // Actual execution of PLACE, MOVE, LEFT, RIGHT, and REPORT commands.
        delete pCommand;
    } while (strInput.rfind("EXIT", 0) != 0);   // Check if string input starts with EXIT.
}

void Test()
{
    std::cout << "Running tests...\n" << std::endl;
    TestRunner runner;
    runner.ExecuteTests();
    std::cout << "\nFinished tests." << std::endl;
}

int main()
{
    // Show options to the user.
    int iChoice = 0;
    std::cout << "Please select 1 or 2:\n";
    std::cout << "1: Run\n";
    std::cout << "2: Test" << std::endl;
    std::cin >> iChoice;

    // Run or Test depending on the selected option.
    if (iChoice == 1) Run();
    else if (iChoice == 2) Test();
    else std::cout << "Invalid choice" << std::endl;
    return 0;
}
