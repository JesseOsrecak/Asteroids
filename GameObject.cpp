#include "GameObject.h"

GameObject::GameObject(double x, double y)
{
    this->x = x;
    this->y = y;
}

GameObject::GameObject(GameObject &copy)
{
    this->x = copy.get_x();
    this->y = copy.get_y();
}



double GameObject::get_x()
{
    return x;
}

double GameObject::get_y()
{
    return y;
}

string GameObject::toString()
{
    string location = "(" + to_string(x) + ", " + to_string(y) + ")";

    string object = location;

    return object;

}