ToyRobotCode
This project is a command line application that simulates a toy robot moving on a square tabletop, with a command interpreter that reads user input and executes commands on the robot.

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
    └── Unit_Test/
	   └── Unit_Test.vcxproj
	

Build Instructions
The project is built using Visual Studio Community Edition 2022. Open ToyRobotCode.sln in Visual Studio and build the project.

Usage
After building the project, run ToyRobotCode.exe from the build directory. The application reads commands from standard input and executes them on the robot.

Tests
The project includes an example unit test framework with few testcases. To run the tests and to see the results, run the Unit_Test.exe from the test directory in the command prompt.

Note
Please note that this project has been designed to be compiled with the G++ compiler on a Linux system or with the Mingw environment on Windows. However, it has only been tested on the Windows platform using the Visual Studio Community Edition 2022. This project does not use any third-party libraries or frameworks.