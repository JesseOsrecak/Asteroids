#include "Spaceship.h"
#include <iostream>
using namespace std;

Spaceship::Spaceship() : GameObject(0,0)
{
    north_bounds = 0.5675;
    south_bounds = -0.5675;
    east_bounds = 0.25;
    west_bounds = -0.25;
    collissionBox = new CollissionBox(get_x(),get_y(), (east_bounds - west_bounds), (north_bounds - south_bounds), get_scale(), get_facing());
    gun = new Gun();
}

Spaceship::Spaceship(double x, double y) : GameObject(x,y)
{
    north_bounds = 0.5675;
    south_bounds = -0.5675;
    east_bounds = 0.25;
    west_bounds = -0.25;

    collissionBox = new CollissionBox(x,y, (east_bounds - west_bounds), (north_bounds - south_bounds), get_scale(), get_facing());
    gun = new Gun(x,y);
}

Spaceship::Spaceship(double x, double y, double scale, double degrees_per_second, double pixels_per_second) : GameObject( x,  y,  scale,  degrees_per_second,  pixels_per_second)
{
    north_bounds = 0.5675;
    south_bounds = -0.5675;
    east_bounds = 0.25;
    west_bounds = -0.25;
    collissionBox = new CollissionBox(x,y, (east_bounds - west_bounds), (north_bounds - south_bounds), get_scale(), get_facing());
    gun = new Gun(x,y,scale,get_facing());
}

Spaceship::Spaceship(Spaceship &copy) : GameObject(copy)
{
    this->north_bounds = copy.get_north_bounds();
    this->south_bounds = copy.get_south_bounds();
    this->east_bounds = copy.get_east_bounds();
    this->west_bounds = copy.get_west_bounds();
    collissionBox = get_collission_box();
    this->gun = new Gun(*copy.get_gun());
}

void Spaceship::debug_draw_hitbox()
{
    // glBegin(GL_LINE_LOOP);
    // glColor3f(1, 1, 1);
    // glVertex2f(east_bounds, north_bounds);
    // glVertex2f(west_bounds, north_bounds);
    // glVertex2f(west_bounds, south_bounds);
    // glVertex2f(east_bounds, south_bounds);
    // glEnd();
}

void Spaceship::draw()
{
    GameObject::draw(); //Applies Translate, Rotate, Scale

    if(get_debug_mode() == true)
    {
        // Draw Bounding Box
        // debug_draw_hitbox();
        // get_collission_box().draw();
    }
    gun->draw();

    // Draw Cockpit
    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.1, 0);
    glVertex2f(0.25, -0.3075);
    glVertex2f(-0.25, -0.3075);
    glVertex2f(-0.125, -0.5675);
    glVertex2f(0.125, -0.5675);
    glEnd();

    // Draw Right Wing125
    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.1, 0);
    glVertex2f(0, -0.3075);
    glVertex2f(0.25, -0.3075);
    glVertex2f(0.25, 0.5675);
    glEnd();

    // Draw left Wing
    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.1, 0);
    glVertex2f(-0.25, -0.3075);
    glVertex2f(0, -0.3075);
    glVertex2f(-0.25, 0.5675);
    glEnd();

        // Draw Outline
    glBegin(GL_LINE_LOOP);
    glColor3f(1, 0, 0);
    glVertex2f(0.01, -0.2975);
    glVertex2f(-0.24, 0.5775);
    glVertex2f(-0.26, 0.5775);
    glVertex2f(-0.26, -0.3175);
    glVertex2f(-0.135, -0.5675);
    glVertex2f(0.135, -0.5675);
    glVertex2f(0.26, -0.3175);
    glVertex2f(0.26, 0.5775);
    glVertex2f(0.24, 0.5775);
    glVertex2f(-0.01, -0.2975);
    glEnd();

    

}

void Spaceship::updatePosition()
{
    GameObject::updatePosition();

    collissionBox->set_facing(get_facing());
    collissionBox->set_scale(get_scale());
    collissionBox->set_x(get_x());
    collissionBox->set_y(get_y());
    collissionBox->set_width(east_bounds - west_bounds);
    collissionBox->set_height(north_bounds - south_bounds);
    
    gun->set_facing(get_facing());
    gun->set_scale(get_scale());
    gun->set_x(get_x());
    gun->set_y(get_y());

    gun->update();

    collissionBox->update_position();
}
double Spaceship::get_north_bounds()
{
    return north_bounds;
}
double Spaceship::get_east_bounds()
{
    return east_bounds;
}
double Spaceship::get_west_bounds()
{
    return west_bounds;
}
double Spaceship::get_south_bounds()
{
    return south_bounds;
}

CollissionBox * Spaceship::get_collission_box()
{
    return collissionBox;
}

Gun *  Spaceship::get_gun()
{
    return gun;
}

bool Spaceship::get_trigger_down()
{
    return gun->get_trigger_down();
}

void Spaceship::set_trigger_down(bool trigger)
{
    gun->set_trigger_down(trigger);
}

void Spaceship::set_facing(double facing)
{
    GameObject::set_facing(facing);
    gun->set_facing(facing);
}

void Spaceship::set_scale(double scale)
{
    GameObject::set_scale(scale);
    gun->set_scale(scale);
}

vector<Bullet * > Spaceship::get_bullets()
{
    return gun->get_bullets();
}

void Spaceship::draw_bullets()
{
    gun->draw_bullets();
}

void Spaceship::delete_bullets(vector<int> delete_list)
{
    gun->delete_bullets(delete_list);
}