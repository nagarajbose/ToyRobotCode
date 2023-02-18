#include <iostream>
#include <vector>
#include <cassert>

#include "Robot.h"
#include "CommandParser.h"
#include "CommandExecution.h"

// Test case for Robot::place() function
void test_robot_place() {
    Robot robot;
    robot.place(3, 1, Robot::Direction::North);
    assert(robot.getX() == 3);
    assert(robot.getY() == 1);
    assert(robot.getDirection() == Robot::Direction::North);
    std::cout << "test_robot_place() fn passed!" << std::endl;
}

// Test case for Robot::move() function
void test_robot_move() {
    Robot robot;
    robot.place(0, 0, Robot::Direction::North);
    robot.move();
    assert(robot.getX() == 0);
    assert(robot.getY() == 1);
    assert(robot.getDirection() == Robot::Direction::North);
    std::cout << "test_robot_move() fn passed!" << std::endl;
}

int main() {
    test_robot_place();
    test_robot_move();

    std::cout << "All tests passed!" << std::endl;

    return 0;
}
