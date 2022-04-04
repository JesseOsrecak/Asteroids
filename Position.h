#ifndef POSITION_H
#define POSITION_H

class Position
{
    public:
        Position();
        Position(double x, double y);
        Position(Position &copy);

        double get_x();
        double get_y();

        void set_x(double x);
        void set_y(double y);

        void set_new_position(double x, double y);
    private:
        double x;
        double y;
};

#endif // POSITION_H