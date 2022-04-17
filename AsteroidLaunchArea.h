#ifndef ASTEROID_LAUNCH_AREA_H
#define ASTEROID_LAUNCH_AREA_H
#include "GameObject.h"

class AsteroidLaunchArea: public GameObject
{
    public:
        AsteroidLaunchArea();
        AsteroidLaunchArea(double radius);
        AsteroidLaunchArea(double radius, double scale);
        AsteroidLaunchArea(AsteroidLaunchArea &other);
        ~AsteroidLaunchArea();

        double get_radius();
        Position get_location();
        void set_radius(double radius);
        bool out_of_bounds(Position * position);



    private:

        double radius;
};



#endif //ASTEROID_LAUNCH_AREA_H