#ifndef GUN_H
#define GUN_H

#include "GameObject.h"
#include "Bullet.h"
#include <vector>

class Gun: public GameObject
{
    public:
        // Constructors
        Gun();
        Gun(double x, double y );
        Gun(double x, double y, double scale, double facing);
        Gun(GameObject &copy);
        ~Gun();
        

        // Methods
        void draw();
        void shoot();
        void update();

        // Getters
        double get_north_bounds();
        double get_south_bounds();
        double get_east_bounds();
        double get_west_bounds();
        Position get_head();
        bool get_trigger_down();

        // Setters
        void set_north_bounds(double north_bounds);
        void set_south_bounds(double south_bounds);
        void set_east_bounds(double east_bounds);
        void set_west_bounds(double west_bounds);
        void set_trigger_down(bool trigger);

    private:
        double north_bounds;
        double south_bounds;
        double east_bounds;
        double west_bounds;
        double rate_of_fire;
        bool trigger_down;
        float last_shot;
        vector<Bullet * > * bullets;
        int num_of_active;

};

#endif //GUN_H