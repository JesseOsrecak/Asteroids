#include "GameObject.h"
#include <iostream>
GameObject::GameObject(double x, double y)
{
    this->x = x;
    this->y = y;
    this->scale = 10;
    this->degrees_per_second = 0;
    this->pixels_per_second = 0;
    bool move_forward = false;
    bool turn_right = false;
    bool turn_left = false;
}

GameObject::GameObject(double x, double y, double scale, double degrees_per_second, double pixels_per_second)
{
    this->x = x;
    this->y = y;
    this->scale = scale;
    this->degrees_per_second = degrees_per_second;
    this->pixels_per_second = pixels_per_second;
    bool move_forward = false;
    bool turn_right = false;
    bool turn_left = false;
}

GameObject::GameObject(GameObject &copy)
{
    this->x = copy.get_x();
    this->y = copy.get_y();
    this->scale = copy.get_scale();
    this->degrees_per_second = copy.get_degrees_per_second();
    this->pixels_per_second = copy.get_pixels_per_second();
    bool move_forward = copy.get_move_forward();
    bool turn_right = copy.get_rotate_right();;
    bool turn_left = copy.get_rotate_left();
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

void GameObject::rotateLeft(float time_elappsed)
{
    double ammout_to_rotate = degrees_per_second * time_elappsed;
    facing = (int)(facing + ammout_to_rotate) % 360;
    
}

void GameObject::rotateRight(float time_elappsed)
{
    double ammout_to_rotate = degrees_per_second * time_elappsed;
    facing = facing - ammout_to_rotate;
    if (facing < 0)
    {
        facing = facing + 360;
    }
    
}

void GameObject::moveForward(float time_elappsed)
{


    double pixels_to_move = pixels_per_second * time_elappsed;

    // TODO Calculate new X and Y Based on Previous X & Y, facing and pixels_to_move

    
}

void GameObject::updatePosition()
{
    // Current Time In Seconds
    float current_time = glutGet(GLUT_ELAPSED_TIME)/1000;
    float time_elappsed = current_time - last_update;
    cout<< "Current Time: " << to_string(current_time) <<endl;
    if (move_forward)
    {
        moveForward(time_elappsed);
        cout << "PLayer 1:  Forward" << endl;
    }
    if (rotate_right)
    {
        rotateRight(time_elappsed);
        cout << "PLayer 1:  Right" << endl;
    }
    if (rotate_left)
    {
        rotateLeft(time_elappsed);
        cout << "PLayer 1:  Left" << endl;
    }


    last_update = current_time;

}

void GameObject::resetMovement()
{
    move_forward = false;
    rotate_left = false;
    rotate_right = false;
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

bool GameObject::get_rotate_left()
{
    return rotate_left;
}

bool GameObject::get_rotate_right()
{
    return rotate_right;
}

bool GameObject::get_move_forward()
{
    return move_forward;
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


void GameObject::set_move_forward(bool move)
{
    this->move_forward = move;
}

void GameObject::set_rotate_left(bool rotate)
{
    this->rotate_left = rotate;
}

void GameObject::set_rotate_right(bool rotate)
{
    this->rotate_right = rotate;
}

