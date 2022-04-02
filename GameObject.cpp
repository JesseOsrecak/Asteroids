#include "GameObject.h"

GameObject::GameObject(double x, double y)
{
    this->x = x;
    this->y = y;
    this->scale = 10;
    this->degrees_per_second = 0;
    this->pixels_per_second = 0;
}

GameObject::GameObject(double x, double y, double scale, double degrees_per_second, double pixels_per_second)
{
    this->x = x;
    this->y = y;
    this->scale = scale;
    this->degrees_per_second = degrees_per_second;
    this->pixels_per_second = pixels_per_second;
}

GameObject::GameObject(GameObject &copy)
{
    this->x = copy.get_x();
    this->y = copy.get_y();
    this->scale = copy.get_scale();
}




string GameObject::toString()
{
    string location = "(" + to_string(x) + ", " + to_string(y) + ")";

    string object = location;

    return object;

}

void GameObject::draw()
{
    glTranslatef(get_x(), get_y(), 0);
    glScalef(get_scale(), get_scale(), 0.0);
    glRotatef(get_facing(), 0 ,0 ,0.0);
    // glBegin(GL_POINTS);
    // glVertex2f(x, y);
    // glEnd();
}

double GameObject::get_x()
{
    return x;
}

double GameObject::get_y()
{
    return y;
}

double GameObject::get_scale()
{
    return scale;
}

double GameObject:: get_facing()
{
    return facing;
}


double GameObject::get_pixels_per_second()
{
    return pixels_per_second;
}


double GameObject::get_degrees_per_second()
{
    return degrees_per_second;
}

float GameObject::get_last_update()
{
    return last_update;
}


void GameObject::set_scale(double scale)
{
    this->scale = scale;
}

void GameObject::set_facing(double facing)
{
    this->facing = facing;
}

void GameObject::set_degrees_per_second(double degrees)
{
    this->degrees_per_second = degrees;
}

void GameObject::set_pixels_per_second(double pixels)
{
    this-> pixels_per_second = pixels;
}

void GameObject::moveForward(float time_elappsed)
{


    double pixels_to_move = pixels_per_second * time_elappsed;

    // TODO Calculate new X and Y Based on Previous X & Y, facing and pixels_to_move

    
}

void GameObject::rotate(float time_elappsed)
{
    double ammout_to_rotate = degrees_per_second * time_elappsed;
    facing = (int)(facing + ammout_to_rotate) % 360;
    
}

void GameObject::updatePosition()
{
    // Current Time In Seconds
    float current_time = glutGet(GLUT_ELAPSED_TIME)/1000;
    float time_elappsed = current_time - last_update;
    last_update = current_time;

}