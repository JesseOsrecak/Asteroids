#ifndef BULLET_H
#define BULLET_H
#include "GameObject.h"
#include "CollissionBox.h"

class Bullet: public GameObject
{
    public:
        // Constructors
        Bullet();
        Bullet(double x, double y);
        Bullet(double x, double y, double scale, double facing);
        Bullet(Bullet &copy);
        ~Bullet();

        void draw();
        void updatePosition();


        // Getters
        CollissionBox * get_collission_box();

    private:
        CollissionBox * collissionBox;
        double north_bounds;
        double south_bounds;
        double east_bounds;
        double west_bounds;
};

#endif //BULLET_H