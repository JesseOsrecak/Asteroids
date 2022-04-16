#ifndef SPACESHIP_H
#define SPACESHIP_H
#include "GameObject.h"
#include "CollissionBox.h"
#include "Gun.h"


class Spaceship: public GameObject
{
    public:
        Spaceship();
        Spaceship(double x, double y);
        Spaceship(double x, double y, double scale, double degrees_per_second, double pixels_per_second);
        Spaceship(Spaceship &copy);
        

        CollissionBox * get_collission_box();
        Gun * get_gun();
        double get_north_bounds();
        double get_east_bounds();
        double get_west_bounds();
        double get_south_bounds();
        bool get_trigger_down();

        void set_trigger_down(bool trigger);
        void set_facing(double facing);
        void set_scale(double scale);


        void debug_draw_hitbox();
        void draw();
        void updatePosition();
        void shoot();
    private:
        double north_bounds;
        double south_bounds;
        double east_bounds;
        double west_bounds;
        CollissionBox * collissionBox;
        Gun * gun;
        bool trigger_down;
};


#endif //SPACESHIP_H