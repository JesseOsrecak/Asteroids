#ifndef ARENA_H
#define ARENA_H
#include "GameObject.h"


class Arena: public GameObject
{
    public:
        Arena();
        Arena(double x, double y, double width, double height);
        Arena(Arena &copy);

        double get_width();
        double get_height();
        void draw();

        void draw_north();
        void draw_south();
        void draw_east();
        void draw_west();

    private:
        double width;
        double height;

};


#endif //ARENA_H