#ifndef COLLISSION_BOX_H
#define COLLISSION_BOX_H
#include "GameObject.h"
#include "Position.h"


class CollissionBox: public GameObject
{
    public:
        // Constructors
        CollissionBox();
        CollissionBox(double x, double y);
        CollissionBox(double x, double y, double scale);
        CollissionBox(double x, double y, double height, double width, double scale);
        CollissionBox(CollissionBox &copy);

        // Getters
        double get_height();
        double get_width();
        double get_north();
        double get_east();
        double get_south();
        double get_west();
        // Setters
        void set_height(double height);
        void set_width(double width);
        void set_dimensions( double width, double height);
        // Other Methods
        void draw();
        bool in_box(CollissionBox &other);
    private:
        double width;
        double height;
};
#endif //COLLISSION_BOX_H