## ToyRobot Code Challenge

This ToyRobot code challenge project is a command line application that simulates a toy robot moving on a square tabletop, with a command interpreter that reads user input and executes commands on the robot.

```codetype
Directory Structure
├── ToyRobotCode.sln
├── ToyRobotCode.vcxproj
├── build/
│   └── ToyRobotCode.exe
├── include/
│   ├── CommandExecution.h
│   ├── CommandParser.h
│   └── Robot.h
├── src/
│   ├── CommandExecution.cpp
│   ├── CommandParser.cpp
│   ├── main.cpp
│   └── Robot.cpp
└── test/
    ├── Unit_Test.exe
    ├── unit_test.cpp
    ├── Integration_Test.exe
    └── Integration_Test.cpp

```	

**Build Instructions**<br>
The project is built using Visual Studio Community Edition 2022. Open ToyRobotCode.sln in Visual Studio and build the project.

**Usage**<br>
Run **ToyRobotCode.exe** from the build directory. The application reads commands from standard input, executes them and prints the report on standard output.

**Tests**<br>
The project includes an example unit test and integration test framework with few testcases. To run the tests and to see the results, run the **Unit_Test.exe/Integration_Test.exe** from the test directory in the command prompt.

**Note**<br>
Please note that this project has been designed to be compiled with the G++ compiler on a Linux system or with the Mingw environment on Windows. However, it has only been tested on the Windows platform using the Visual Studio Community Edition 2022. This project does not use any third-party libraries or frameworks.
