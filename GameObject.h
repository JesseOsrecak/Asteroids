#include <string>
using namespace std;


class GameObject
{
    public:

        GameObject(double x, double y);
        GameObject(GameObject &copy);
        
        double get_x();
        double get_y();

        string toString();


    private:
        double x;
        double y;
};