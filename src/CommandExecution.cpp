#include "CommandExecution.h"

#include <iostream>

CommandExecution::CommandExecution(Robot& robot) : robot(robot) {}

void CommandExecution::executeCommand(const std::vector<std::string>& commandData) {
	if (commandData.empty()) {
		return;
	}

	const std::string& command = commandData[0];
	if (command == "PLACE" && commandData.size() == 2) {
		executePlaceCommand(commandData);
	}
	else if (command == "MOVE" && commandData.size() == 1) {
		executeMoveCommand();
	}
	else if (command == "LEFT" && commandData.size() == 1) {
		executeLeftCommand();
	}
	else if (command == "RIGHT" && commandData.size() == 1) {
		executeRightCommand();
	}
	else if (command == "REPORT" && commandData.size() == 1) {
		executeReportCommand();
	}
	else
	{
		std::cout << "INVALID COMMAND, VALID COMMANDS EX: PLACE 0,0,NORTH MOVE LEFT RIGHT REPORT" << std::endl;
	}
}

void CommandExecution::executePlaceCommand(const std::vector<std::string>& commandData) {

	const std::string& placeCommandArguments = commandData[1];

	// Find the first comma separator in the arguments string
	const size_t commaPos1 = placeCommandArguments.find(",");
	if (commaPos1 == std::string::npos) {
		std::cout << "INVALID PLACE COMMAND FORMAT EX: PLACE 0,0,NORTH" << std::endl;
		return;
	}

	// Extract the x value from the arguments string
	const std::string xStr = placeCommandArguments.substr(0, commaPos1);
	int x = 0;
	try {
		x = std::stoi(xStr);
	}
	catch (const std::exception&) {
		// Invalid input for x, ignore the command
		std::cout << "INVALID x VALUE, COMMAND IGNORED" << std::endl;
		return;
	}

	// Find the second comma separator in the arguments string
	const size_t commaPos2 = placeCommandArguments.find(",", commaPos1 + 1);
	if (commaPos2 == std::string::npos) {
		// Invalid format, ignore the command
		std::cout << "INVALID PLACE COMMAND FORMAT EX: PLACE 0,0,NORTH" << std::endl;
		return;
	}

	// Extract the y value from the arguments string
	const std::string yStr = placeCommandArguments.substr(commaPos1 + 1, commaPos2 - commaPos1 - 1);
	int y = 0;
	try {
		y = std::stoi(yStr);
	}
	catch (const std::exception&) {
		// Invalid input for y, ignore the command
		std::cout << "INVALID y VALUE, COMMAND IGNORED" << std::endl;
		return;
	}

	// Extract the facing value from the arguments string
	const std::string facingStr = placeCommandArguments.substr(commaPos2 + 1);

	if ((x >= TABLETOP_XPOS_MIN) && (x < TABLETOP_XPOS_MAX) && (y >= TABLETOP_YPOS_MIN) && (y < TABLETOP_YPOS_MAX)) {
		Robot::Direction facing;

		if (facingStr == "NORTH") {
			facing = Robot::Direction::North;
		}
		else if (facingStr == "EAST") {
			facing = Robot::Direction::East;
		}
		else if (facingStr == "SOUTH") {
			facing = Robot::Direction::South;
		}
		else if (facingStr == "WEST") {
			facing = Robot::Direction::West;
		}
		else {
			// Invalid facing direction, ignore the command
			std::cout << "INVALID FACING DIRECTION, COMMAND IGNORED" << std::endl;
			return;
		}
		robot.place(x, y, facing);
	}
	else
	{
		std::cout << "INVALID x, y VALUES, VALID VALUES ARE 0 to 4 " << std::endl;
	}

}

void CommandExecution::executeMoveCommand(void) {
	robot.move();
}

void CommandExecution::executeLeftCommand(void) {
	robot.turnLeft();
}

void CommandExecution::executeRightCommand(void) {
	robot.turnRight();
}

void CommandExecution::executeReportCommand(void) {
	std::cout << robot.report() << std::endl;
}
