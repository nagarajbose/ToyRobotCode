#include "Robot.h"

#include <iostream>

const std::map<Robot::Direction, Robot::Direction> Robot::rightDirections{
    {Robot::Direction::North, Robot::Direction::East},
    {Robot::Direction::East, Robot::Direction::South},
    {Robot::Direction::South, Robot::Direction::West},
    {Robot::Direction::West, Robot::Direction::North}
};

const std::map<Robot::Direction, Robot::Direction> Robot::leftDirections{
    {Robot::Direction::North, Robot::Direction::West},
    {Robot::Direction::West, Robot::Direction::South},
    {Robot::Direction::South, Robot::Direction::East},
    {Robot::Direction::East, Robot::Direction::North}
};

const std::map<Robot::Direction, std::string> Robot::directionString{
    {Robot::Direction::North, "NORTH"},
    {Robot::Direction::East, "EAST"},
    {Robot::Direction::South, "SOUTH"},
    {Robot::Direction::West, "WEST"}
};

Robot::Robot() {
    isPlaced = false;
    pos_x = ROBOT_POS_INVALID;
    pos_y = ROBOT_POS_INVALID;
    direction = Robot::Direction::North;
}

void Robot::place(int x, int y, Robot::Direction facing) {
    pos_x = x;
    pos_y = y;
    direction = facing;
    isPlaced = true;
}

void Robot::move(void) {
    if (!isPlaced) {
        std::cout << "ROBOT NOT PLACED INSIDE THE TABLLETOP YET, SO IGNORING THE COMMAND" << std::endl;
        return;
    }

    switch (direction) {
    case Robot::Direction::North:
        if (pos_y < (TABLETOP_YPOS_MAX - 1)) {
            pos_y++;
        }
        else
        {
            std::cout << "CAN NOT MOVE FURTHER TOWARDS NORTH, SO IGNORING THE COMMAND" << std::endl;
        }
        break;
    case Robot::Direction::South:
        if (pos_y > TABLETOP_YPOS_MIN) {
            pos_y--;
        }
        else
        {
            std::cout << "CAN NOT MOVE FURTHER TOWARDS SOUTH, SO IGNORING THE COMMAND" << std::endl;
        }
        break;
    case Robot::Direction::East:
        if (pos_x < (TABLETOP_XPOS_MAX - 1)) {
            pos_x++;
        }
        else
        {
            std::cout << "CAN NOT MOVE FURTHER TOWARDS EAST, SO IGNORING THE COMMAND" << std::endl;
        }
        break;
    case Robot::Direction::West:
        if (pos_x > TABLETOP_XPOS_MIN) {
            pos_x--;
        }
        else
        {
            std::cout << "CAN NOT MOVE FURTHER TOWARDS WEST, SO IGNORING THE COMMAND" << std::endl;
        }
        break;
    }
}

#include <map>

void Robot::turnLeft(void) {
    if (!isPlaced) {
        std::cout << "ROBOT NOT PLACED INSIDE THE TABLETOP YET, SO IGNORING THE COMMAND" << std::endl;
        return;
    }

    direction = leftDirections.at(direction);
}

void Robot::turnRight(void) {
    if (!isPlaced) {
        std::cout << "ROBOT NOT PLACED INSIDE THE TABLETOP YET, SO IGNORING THE COMMAND" << std::endl;
        return;
    }

    direction = rightDirections.at(direction);
}


std::string Robot::report(void) {
    if (!isPlaced) {
        return "ROBOT NOT PLACED INSIDE THE TABLLETOP YET, NOTHING TO REPORT";
    }

    return std::to_string(pos_x) + "," + std::to_string(pos_y) + "," + directionString.at(direction);
}


int Robot::getX(void) {
    return pos_x;
}

int Robot::getY(void) {
    return pos_y;
}

Robot::Direction Robot::getDirection(void) {
    return direction;
}
