#include "AsteroidLaunchArea.h"
#include <iostream>
#include "math.h"
#include <random>
using namespace std;


AsteroidLaunchArea::AsteroidLaunchArea() : GameObject(0,0)
{
    radius = 20;
}

AsteroidLaunchArea::AsteroidLaunchArea(double radius) : GameObject(0,0)
{
    this->radius = radius;
}

AsteroidLaunchArea::AsteroidLaunchArea(double radius, double scale) : GameObject(0,0,scale, 0)
{
    this->radius = radius;
}

AsteroidLaunchArea::AsteroidLaunchArea(AsteroidLaunchArea &other) : GameObject(other)
{
    this->radius = other.get_radius();
}

double AsteroidLaunchArea::get_radius()
{
    return radius;
}

void AsteroidLaunchArea::set_radius(double radius)
{
    this->radius = radius;
}

Position AsteroidLaunchArea:: get_location()
{
    // We use 10 as a base Value as get_scale() is kept consistent with Arena Get_Scale() and a 16/9 furthest distance from centre to corner is 9. This allows a maxium asteroid size of 1
    int min_radius = 10*get_scale();
    double max_radius = radius * get_scale();
    double distance_from_origin = rand()%min_radius + min_radius;
    double angle = rand()%360;

    return calculate_new_position(0,0,angle,distance_from_origin);

    
}

bool AsteroidLaunchArea::out_of_bounds(Position * position)
{
    bool out_of_bounds = false;

    if(pythagorean_theorem_find_hypotenuse(position->get_x(), position->get_y()) > radius * get_scale())
    {
        out_of_bounds = true;
    }

    return out_of_bounds;
}