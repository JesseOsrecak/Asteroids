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
        CollissionBox(double x, double y,  double width, double height);
        CollissionBox(double x, double y,  double width, double height, double scale, double facing);
        CollissionBox(CollissionBox &copy);
        
        ~CollissionBox();

        // Getters
        double get_height();
        double get_width();
        double get_north();
        double get_east();
        double get_south();
        double get_west();

        Position * get_north_east();
        Position * get_north_west();
        Position * get_south_east();
        Position * get_south_west();

        // Setters
        void set_height(double height);
        void set_width(double width);
        void set_dimensions( double width, double height);
        // Other Methods
        void draw();
        bool in_box(CollissionBox &other);
        void update_position();
    private:
        double width;
        double height;
        Position * north_east;
        Position * north_west;
        Position * south_east;
        Position * south_west;
};
#endif //COLLISSION_BOX_H