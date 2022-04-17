#ifndef ASTEROID_H
#define ASTEROID_H
#include "GameObject.h"
#include "CollissionBox.h"

class Asteroid : public GameObject
{
    public:

        Asteroid();
        Asteroid(double x, double y);
        Asteroid(double x,double y, double scale, double facing);
        Asteroid(double x,double y, double scale, double facing, double radius);
        Asteroid(Asteroid &other);
        ~Asteroid();

        void draw();
        bool test_collission(CollissionBox * other);
        double get_radius();
        void set_radius(double radius);
    private:
        double radius;
};

#endif //ASTEROID_H