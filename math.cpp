#include "math.h"


Position calculate_new_position(double x, double y, double angle, double distance)
{
    int quadrant = angle / 90;
    Position new_position = Position(x,y);
    if (quadrant == 0)
    {
        // Quadrant 0 Math
        double radians = angle * PI / 180;
        double new_x = distance * sin(radians);
        double new_y = distance * cos(radians);
        new_position.set_new_position(x - new_x, y + new_y);
        
    }
    else if (quadrant == 1)
    {
        // Quadrant 1 Math
        angle = angle - 90;
        double radians = angle * PI / 180;
        double new_x = distance * cos(radians);
        double new_y = distance * sin (radians);
        new_position.set_new_position(x - new_x, y - new_y);

    }
    else if (quadrant == 2)
    {
        // Quadrant 2 Math
        angle = angle - 180;
        double radians = angle * PI / 180;
        double new_x = distance * sin(radians);
        double new_y = distance * cos(radians);
        new_position.set_new_position(x + new_x, y - new_y);
        
    }
    else if (quadrant == 3)
    {
        // Quadrant 3 Math
        angle = angle - 270;
        double radians = angle * PI / 180;
        double new_x = distance * cos(radians);
        double new_y = distance * sin (radians);
        new_position.set_new_position(x + new_x, y + new_y);
    }

    return new_position;
}