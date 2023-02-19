#include <iostream>
#include <sstream>
#include <cassert>
#include "Robot.h"
#include "CommandParser.h"
#include "CommandExecution.h"

void testCase1() {
    Robot robot;
    CommandParser parser(robot);
    CommandExecution executor(robot);

    std::string input = "PLACE 0,0,NORTH\n"
        "MOVE\n"
        "REPORT\n";
    std::stringstream inputStream(input);
    std::streambuf* prev = std::cin.rdbuf(inputStream.rdbuf());

    std::vector<std::string> commands;
    std::string command;
    while (std::getline(inputStream, command)) {
        commands.push_back(command);
    }

    for (const std::string& cmd : commands) {
        executor.executeCommand(parser.parse(cmd));
    }

    std::string expectedOutput = "0,1,NORTH\n";
    assert(std::cout.rdbuf()->str() == expectedOutput);

    std::cin.rdbuf(prev);
}

void testCase2() {
    Robot robot;
    CommandParser parser(robot);
    CommandExecution executor(robot);

    std::string input = "PLACE 0,0,NORTH\n"
        "LEFT\n"
        "REPORT\n";
    std::stringstream inputStream(input);
    std::streambuf* prev = std::cin.rdbuf(inputStream.rdbuf());

    std::vector<std::string> commands;
    std::string command;
    while (std::getline(inputStream, command)) {
        commands.push_back(command);
    }

    for (const std::string& cmd : commands) {
        executor.executeCommand(parser.parse(cmd));
    }

    std::string expectedOutput = "0,0,WEST\n";
    assert(std::cout.rdbuf()->str() == expectedOutput);

    std::cin.rdbuf(prev);
}

int main() {
    testCase1();
    testCase2();
    // More testcases can be added

    std::cout << "All test cases passed!\n";

    return 0;
}
