#include "GameObject.h"
#include <iostream>
#include "math.h"
GameObject::GameObject(double x, double y)
{
    position = Position(x,y);

    this->scale = 10;
    this->degrees_per_second = 0;
    this->pixels_per_second = 0;
    bool move_forward = false;
    bool turn_right = false;
    bool turn_left = false;
}

GameObject::GameObject(double x, double y, double scale, double degrees_per_second, double pixels_per_second)
{
    // this->x = x;
    // this->y = y;
    position = Position(x,y);
    this->scale = scale;
    this->degrees_per_second = degrees_per_second;
    this->pixels_per_second = pixels_per_second;
    bool move_forward = false;
    bool turn_right = false;
    bool turn_left = false;
}

GameObject::GameObject(GameObject &copy)
{

    position = Position(copy.get_x(),copy.get_y());
    this->scale = copy.get_scale();
    this->degrees_per_second = copy.get_degrees_per_second();
    this->pixels_per_second = copy.get_pixels_per_second();
    bool move_forward = copy.get_move_forward();
    bool turn_right = copy.get_rotate_right();;
    bool turn_left = copy.get_rotate_left();
}




string GameObject::toString()
{
    string location = "(" + to_string(get_x()) + ", " + to_string(get_y()) + ")\n";
    string direction = "Facing: " + to_string(facing) +"(0 = North)\n";
    string object = location + direction;

    return object;

}

void GameObject::draw()
{   
    glTranslatef(get_x(), get_y(), 0);
    glScalef(get_scale(), get_scale(), 0.0);
    glRotatef(get_facing(), 0 ,0 ,1);
}

void GameObject::rotateLeft(double time_elappsed)
{
    double ammout_to_rotate = degrees_per_second * time_elappsed;
    facing = (int)(facing + ammout_to_rotate) % 360;
    
    
}

void GameObject::rotateRight(double time_elappsed)
{
    double ammout_to_rotate = degrees_per_second * time_elappsed;
    
    facing = facing - ammout_to_rotate;
    // facing -= 10;//Test
    while (facing < 0)
    {
        facing = facing + 360;
    }
    
    
}

void GameObject::moveForward(double time_elappsed)
{

    
    double pixels_to_move = pixels_per_second * time_elappsed;
    position = calculate_new_position(get_x(), get_y(),facing,pixels_to_move);

    
}

void GameObject::updatePosition()
{
    // Current Time In Seconds
    double current_time = glutGet(GLUT_ELAPSED_TIME)/1000.0;
    double time_elappsed = current_time - last_update;
    if (move_forward == true)
    {
        moveForward(time_elappsed);

    }
    if (rotate_right == true) 
    {
        rotateRight(time_elappsed);
    }
    if (rotate_left == true)
    {
        rotateLeft(time_elappsed);
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
    return position.get_x();
}

double GameObject::get_y()
{
    return position.get_y();
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

Position GameObject::get_position()
{   
    return position;
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

void GameObject::set_position(Position position)
{
    this->position = position;
}