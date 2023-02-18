#ifndef ROBOT_H
#define ROBOT_H

#include <memory>
#include <string>
#include <map>

#define TABLETOP_XPOS_MIN      (0)
#define TABLETOP_YPOS_MIN      (0)
#define TABLETOP_XPOS_MAX      (5)
#define TABLETOP_YPOS_MAX      (5)
#define ROBOT_POS_INVALID      (-1)


class Robot {
public:
    // Enumeration for robot's direction
    enum class Direction {
        North,
        East,
        South,
        West
    };

    // Constructor
    Robot();

    // Place the robot at the given x, y coordinates facing the given direction
    void place(int x, int y, Direction facing);

    // Move the robot one unit in the direction it is facing
    void move(void);

    // Turn the robot 90 degrees to the left
    void turnLeft(void);

    // Turn the robot 90 degrees to the right
    void turnRight(void);

    // Report the current position and direction of the robot
    std::string report(void);

    // Get the current x position of the robot
    int getX(void);

    // Get the current y position of the robot
    int getY(void);

    // Get the current direction the robot is facing
    Direction getDirection(void);

private:
    // The x position of the robot
    int pos_x;

    // The y position of the robot
    int pos_y;

    // The direction the robot is facing
    Direction direction;

    // Boolean flag indicating if the robot has been placed on the tabletop
    bool isPlaced;

    // Static maps for right and left turns and direction string
    static const std::map<Direction, Direction> rightDirections;
    static const std::map<Direction, Direction> leftDirections;
    static const std::map<Direction, std::string> directionString;
};


#endif // ROBOT_H
