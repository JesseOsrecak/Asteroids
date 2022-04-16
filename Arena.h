#ifndef ARENA_H
#define ARENA_H
#include "GameObject.h"
#include "CollissionBox.h"


class Arena: public GameObject
{
    public:
        Arena();
        Arena(double x, double y, double width, double height);
        Arena(Arena &copy);

        double get_width();
        double get_height();

        void draw();
        void debug_draw();
        void draw_north();
        void draw_south();
        void draw_east();
        void draw_west();

        bool in_collission_box(CollissionBox * object);
        void isClose(CollissionBox * object);

    private:
        double width;
        double height;
        bool close_north;
        bool close_east;
        bool close_south;
        bool close_west;

};


#endif //ARENA_H