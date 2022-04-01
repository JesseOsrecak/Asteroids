#include "GameObject.h"

GameObject::GameObject(double x, double y)
{
    this->x = x;
    this->y = y;
    this->scale = 10;
}

GameObject::GameObject(GameObject &copy)
{
    this->x = copy.get_x();
    this->y = copy.get_y();
    this->scale = copy.get_scale();
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

void GameObject::draw()
{
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
}

double GameObject::get_scale()
{
    return scale;
}

void GameObject::set_scale(double scale)
{
    this->scale = scale;
}