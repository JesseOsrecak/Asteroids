#include "Position.h"
#include <cmath>
Position::Position()
{
    this->x = 0;
    this->y = 0;
}

Position::Position(double x, double y)
{
    set_new_position(x,y);
}

Position::Position(Position &copy)
{
    this->x = copy.get_x();
    this->y = copy.get_y();
}

double Position::get_x()
{
    return x;
}

double Position::get_y()
{
    return y;
}

double Position::get_scaled_x(double scale)
{
    return x * sqrt(scale);
    // if (x > 0)
    //     return x + sqrt(scale);
    // else if(x < 0)
    //     return x - sqrt(scale);
    // return x;
}

double Position::get_scaled_y(double scale)
{
    return y * sqrt(scale);
    // return y;
}
void Position::set_x(double x)
{
    this->x = x;
}

void Position::set_y(double y)
{
    this->y = y;
}

void Position::set_new_position(double x, double y)
{
    this->x = x;
    this->y = y;
}

string Position::toString()
{
    return  "(" + to_string(x) + ", " +to_string(y) + ")";
}