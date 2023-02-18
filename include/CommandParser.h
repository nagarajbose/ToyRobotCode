#ifndef COMMANDPARSER_H
#define COMMANDPARSER_H

#include "Robot.h"
#include <vector>
#include <string>

class CommandParser {
public:
    // Constructor that takes a reference to a Robot object
    CommandParser(Robot& robot);

    // Function that takes a string input and returns a vector of parsed command strings
    std::vector<std::string> parse(const std::string& input);

private:
    // Reference to the Robot object that this parser will control
    Robot& robot;
};

#endif // COMMANDPARSER_H
