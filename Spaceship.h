#ifndef SPACESHIP_H
#define SPACESHIP_H
#include "GameObject.h"


class Spaceship: public GameObject
{
    public:
        Spaceship();
        Spaceship(double x, double y);
        Spaceship(double x, double y, double scale, double degrees_per_second, double pixels_per_second);
        Spaceship(Spaceship &copy);

        void draw();
    private:

};


#endif //SPACESHIP_H