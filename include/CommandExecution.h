#ifndef COMMANDEXECUTION_H
#define COMMANDEXECUTION_H

#include <vector>
#include "Robot.h"

class CommandExecution {
public:
    CommandExecution(Robot& robot);

    // Execute the command specified in the given vector of strings
    void executeCommand(const std::vector<std::string>& commandData);

private:
    Robot& robot;

    // Execute the PLACE command using the given vector of strings
    void executePlaceCommand(const std::vector<std::string>& commandData);

    // Execute the MOVE command
    void executeMoveCommand(void);

    // Execute the LEFT command
    void executeLeftCommand(void);

    // Execute the RIGHT command
    void executeRightCommand(void);

    // Execute the REPORT command
    void executeReportCommand(void);
};

#endif // COMMANDEXECUTION_H