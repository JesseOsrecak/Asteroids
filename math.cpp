#include "math.h"
#include <iostream>
using namespace std;

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

double pythagorean_theorem_find_hypotenuse(double a, double b)
{
    return sqrt(pow(a,2) + pow(b,2));
}

double to_radians(double angle)
{
    return angle/180 * PI;
}

double to_degrees(double angle)
{
    return angle/PI * 180;
}

double get_angle_from_2_positions(Position & origin, Position & destination)
{
    // Translate to 0,0
    Position translated_destination = Position(destination.get_x() - origin.get_x(), destination.get_y() - origin.get_y());
    double x = translated_destination.get_x();
    double y = translated_destination.get_y();
    int quadrant = 0;
    if(x <= 0 and y > 0)
    {
        quadrant = 1;
    }
    else if(x <=0 and y <= 0)
    {
        quadrant = 2;
    }
    else if (x > 0 and y < 0 )
    {
        quadrant = 3;
    }
    else if (x >=0 and y >=0)
    {
        quadrant = 4;
    }

    double angle = atan(abs(x/y))*180/PI;
    if (quadrant == 2)
    {
        angle = angle + 90;
    }
    else if(quadrant == 3)
    {
        angle += 180;
    }
    else if(quadrant == 4)
    {
        angle += 270;
    }

    return angle;


}
// Position apply_scale(Position * origin, Position * point, double scale)
// {

//     // cout << "Unit" <<endl;
//     double translated_x = point->get_x() - origin->get_x();
//     double translated_y = point->get_y() - origin->get_y();
//     double unit = pythagorean_theorem_find_hypotenuse(translated_x, translated_y);

//     // cout << "Angle" <<endl;
//     double angle = atan(abs(translated_y)/ abs(translated_x));

//     double n_scale = abs(scale - unit);

//     double adjacent = n_scale * cos(angle);
//     double opposite = n_scale * sin(angle);

//     if (translated_x < 0)
//     {
//         adjacent = adjacent * -1;
//     }

//     if (translated_y < 0)
//     {
//         opposite = opposite * -1;
//     }

//     double x = adjacent + origin->get_x();
//     double y = opposite + origin->get_y();

//     Position new_position = Position(x,y);
//     cout << "Original: "<<point->toString() <<
//     "| Translated: " <<new_position.toString() <<
//      "| (x,y): " << "(" << to_string(x) << ", " << to_string(y) <<
//       ") | (adj,opp): (" << to_string(adjacent) << ", " << to_string(opposite) << 
//       ") | Angle: " << to_string(angle)<<
//       " | Unit:  " << to_string(unit) << 
//       " | Scale: " << to_string(scale) <<
//       " | Origin: " << origin->toString() << 
//       " | Translated_x: " << to_string(translated_x) <<  
//       " | Translated_y: " << to_string(translated_y) << endl;
//     return new_position;
// }

