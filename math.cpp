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

