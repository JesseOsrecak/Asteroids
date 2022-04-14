#ifndef SPACESHIP_H
#define SPACESHIP_H
#include "GameObject.h"
#include "CollissionBox.h"


class Spaceship: public GameObject
{
    public:
        Spaceship();
        Spaceship(double x, double y);
        Spaceship(double x, double y, double scale, double degrees_per_second, double pixels_per_second);
        Spaceship(Spaceship &copy);
        

        CollissionBox get_collission_box();
        double get_north_bounds();
        double get_east_bounds();
        double get_west_bounds();
        double get_south_bounds();
        void debug_draw_hitbox();
        void draw();
    private:
        double north_bounds;
        double south_bounds;
        double east_bounds;
        double west_bounds;
        

};


#endif //SPACESHIP_H