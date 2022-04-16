#include "Gun.h"
#include "math.h"

#include <iostream>
using namespace std;
Gun::Gun() : GameObject(0,0)
{
    north_bounds =  0.25;
    south_bounds = -0.25;
    east_bounds  =  0.05;
    west_bounds  = -0.05;
    rate_of_fire = 1.0;
    last_shot = 0;
    trigger_down = false;
}

Gun::Gun(double x, double y ) : GameObject(x,y)
{
    north_bounds =  0.25;
    south_bounds = -0.25;
    east_bounds  =  0.05;
    west_bounds  = -0.05;
    rate_of_fire = 1.0;
    last_shot = 0;
    trigger_down = false;
}

Gun::Gun(double x, double y, double scale, double facing) : GameObject(x,y,scale,facing)
{
    north_bounds =  0.25;
    south_bounds = -0.25;
    east_bounds  =  0.05;
    west_bounds  = -0.05;
    rate_of_fire = 1.0;
    last_shot = 0;
    trigger_down = false;
}


Gun::Gun(GameObject &copy) : GameObject(copy)
{
    north_bounds =  0.25;
    south_bounds = -0.25;
    east_bounds  =  0.05;
    west_bounds  = -0.05;
    rate_of_fire = 1.0;
    last_shot = 0;
    trigger_down = false;
}

Gun::~Gun()
{
    // for(int i = 0; i < bullets->size(); ++i)
    // {
    //     delete bullets[i];
    // }

    bullets->clear();
    delete bullets;
}

void Gun::draw()
{
    glBegin(GL_POLYGON);
    glColor3f(0.1,0.1,0.1);
    glVertex2f(west_bounds, south_bounds);
    glVertex2f(east_bounds, south_bounds);
    glVertex2f(east_bounds, north_bounds);
    glVertex2f(west_bounds, north_bounds);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(1,0,0);
    glVertex2f(west_bounds, south_bounds);
    glVertex2f(east_bounds, south_bounds);
    glVertex2f(east_bounds, north_bounds);
    glVertex2f(west_bounds, north_bounds);
    glEnd();
}

void Gun::update()
{
    double current_time = glutGet(GLUT_ELAPSED_TIME)/1000.0;

    // Update Position on all bullets

    // for(Bullet * bullet : *bullets)
    // {
    //     bullet->updatePosition();
    // }

    if (current_time - last_shot >= rate_of_fire and trigger_down == true) 
    {
        shoot();
        last_shot = current_time;
    }

}    

// TODO
void Gun::shoot()
{
    // SPAWN in bullet and fire shot
    cout<<"SHOT"<<endl;
    Position location = get_head();
    bullets->push_back(new Bullet(location.get_x(), location.get_y(),get_scale(), get_facing()));
    cout << "POST"<<endl;
}

double Gun::get_north_bounds()
{
    return north_bounds;
}

double Gun::get_south_bounds()
{
    return south_bounds;
}

double Gun::get_east_bounds()
{
    return east_bounds;
}

double Gun::get_west_bounds()
{
    return west_bounds;
}

void Gun::set_north_bounds(double north_bounds)
{
    this->north_bounds = north_bounds;
}

void Gun::set_south_bounds(double south_bounds)
{
    this->south_bounds = south_bounds;
}

void Gun::set_east_bounds(double east_bounds)
{
    this->east_bounds = east_bounds;
}

void Gun::set_west_bounds(double west_bounds)
{
    this->west_bounds = west_bounds;
}

Position Gun::get_head()
{
    return calculate_new_position(get_x(),get_y(), get_facing(), north_bounds );
}

bool Gun::get_trigger_down()
{
    return trigger_down;
}

void Gun::set_trigger_down(bool trigger)
{
    this->trigger_down = trigger;
}