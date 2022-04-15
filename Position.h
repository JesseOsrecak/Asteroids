#ifndef POSITION_H
#define POSITION_H
#include <string>
using namespace std;
class Position
{
    public:
        Position();
        Position(double x, double y);
        Position(Position &copy);

        double get_x();
        double get_y();

        double get_scaled_x(double scale);
        double get_scaled_y(double scale);

        void set_x(double x);
        void set_y(double y);

        void set_new_position(double x, double y);

        string toString();
    private:
        double x;
        double y;
};

#endif // POSITION_H