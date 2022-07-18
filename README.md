# Toy Robot Code Challenge

## Description and requirements:

The application is a simulation of a toy robot moving on a square table top, of dimensions 5 units x 5 units. There are no other obstructions on the table surface. The robot is free to roam around the surface of the table, but must be prevented from falling to destruction. Any movement that would result in the robot falling from the table must be prevented, however further valid movement commands must still be allowed.

Create a console application that can read in commands of the following form -

PLACE X,Y,F

MOVE

LEFT

RIGHT

REPORT

PLACE will put the toy robot on the table in position X,Y and facing NORTH, SOUTH, EAST or WEST. The origin (0,0) can be considered to be the SOUTH WEST most corner. It is required that the first command to the robot is a PLACE command, after that, any sequence of commands may be issued, in any order, including another PLACE command. The application should discard all commands in the sequence until a valid PLACE command has been executed.
MOVE will move the toy robot one unit forward in the direction it is currently facing.
LEFT and RIGHT will rotate the robot 90 degrees in the specified direction without changing the position of the robot. REPORT will announce the X,Y and F of the robot. This can be in any form, but standard output is sufficient.
A robot that is not on the table can choose to ignore the MOVE, LEFT, RIGHT and REPORT commands.
Input can be from a file, or from standard input, as the developer chooses.
Provide test data to exercise the application.
It is not required to provide any graphical output showing the movement of the toy robot.
The application should handle error states appropriately and be robust to user input.

## Constraints:
The toy robot must not fall off the table during movement. This also includes the initial placement of the toy robot. Any move that would cause the robot to fall must be ignored.

## Example Input and Output:

a)----------------

PLACE 0,0,NORTH

MOVE

REPORT

Output: 0,1,NORTH


b)----------------

PLACE 0,0,NORTH

LEFT

REPORT

Output: 0,0,WEST


c)----------------

PLACE 1,2,EAST

MOVE

MOVE

LEFT

MOVE

REPORT

Output: 3,3,NORTH

## Setup:
This project is developed in Windows 8.1 using:
1. Code::Blocks 20.03
2. GNU GCC Compiler

Refer to the following Youtube video on how to install Code::Blocks with GNU GCC Compiler in Windows:
How to Install CodeBlocks (IDE 20.03) with MinGW for C and C++ Programming on Windows 11
https://www.youtube.com/watch?v=Thf1NkwpICY

## Building the Project
1. Clone this repository. You should have the ToyRobotCodeChallenge folder with the source code after this.
2. Open Code::Blocks.
3. Click 'Open Existing Project' in the 'Start here' section. Alternatively, go to File -> Open, or press Ctrl+O. Navigate to the ToyRobotCodeChallenge folder. Select ToyRobotCodeChallenge.cbp. Click Open. The ToyRobotCodeChallenge project will be loaded into Code::Blocks.
4. Go to Build -> Build and Run. Or press F9. The app should be running after this. The executable file will be inside the bin/Release folder.

## Running the Application
1. Open Code::Blocks.
2. Build ToyRobotCodeChallenge project. Refer to the 'Building the Project' section above on how to.
3. Go to Build -> Run. Or press Ctrl+F10. A command prompt should appear. The application is now running.
4. You will be asked to enter 1 or 2.
1 to issue PLACE, MOVE, LEFT, RIGHT, and REPORT commands. Upon selecting this option, you can enter any number of commands. Refer to the test_data.txt for sample commands. To exit, type 'EXIT' and press ENTER.
2 to run the tests. The application will exit once all the tests are finished executing.
