#ifndef SPACESHIP_H
#define SPACESHIP_H
#include "GameObject.h"


class Spaceship: public GameObject
{
    public:
        Spaceship();
        Spaceship(double x, double y);
        Spaceship(Spaceship &copy);

        void draw();
    private:

};


#endif //SPACESHIP_H