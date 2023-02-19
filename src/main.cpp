#include <iostream>
#include <memory>
#include <string>

#include "Robot.h"
#include "CommandParser.h"
#include "CommandExecution.h"

// This function is the entry point of the ToyRobot Code Challenge program.
int main() {
    // Smart pointers ensure that their memory is properly managed, to avoid memory leaks
    // Create a smart pointer to a Robot object using std::make_unique
    std::unique_ptr<Robot> robot = std::make_unique<Robot>();

    // Create a smart pointer to a CommandParser object using std::make_unique
    // and pass the Robot object as a reference
    std::unique_ptr<CommandParser> parser = std::make_unique<CommandParser>(*robot);

    // Create a smart pointer to a CommandExecution object using std::make_unique
    // and pass the Robot object as a reference
    std::unique_ptr<CommandExecution> execution = std::make_unique<CommandExecution>(*robot);

    std::cout << "Valid Commands : PLACE X,Y,F / MOVE / LEFT / RIGHT / REPORT" << std::endl;
    std::cout << "Valid values   : X(0 to 4), Y(0 to 4), F(NORTH, SOUTH, EAST, WEST)" << std::endl;
    std::cout << "Please enter the commands..." << std::endl;
  
    std::string line;
    while (std::getline(std::cin, line)) {
        try {
            // Call the parse function on the CommandParser object and pass the input string
            std::vector<std::string> commandData = parser->parse(line);

            // Call the executeCommand function on the CommandExecution object and pass the commandData
            execution->executeCommand(commandData);
        }
        catch (const std::exception& e) {
            // Catch any exceptions thrown by the parse or executeCommand functions
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    return 0;
}
