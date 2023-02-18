#include "CommandParser.h"

CommandParser::CommandParser(Robot& robot) : robot(robot) {}

std::vector<std::string> CommandParser::parse(const std::string& input) {
    std::vector<std::string> cmdInputs;

    size_t pos = 0;
    while (pos < input.size()) {
        // Skip leading whitespaces
        while (pos < input.size() && isspace(input[pos])) {
            ++pos;
        }

        if (pos == input.size()) {
            // End of string
            break;
        }

        // Find the end of the next cmdInput
        size_t end_pos = input.find_first_of(" \t", pos);

        // Extract the cmdInput
        std::string cmdInput = input.substr(pos, end_pos - pos);
        cmdInputs.push_back(cmdInput);

        // Move the position to the end of the cmdInput
        pos = end_pos;
    }

    return cmdInputs;
}
