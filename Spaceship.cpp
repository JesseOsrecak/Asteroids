#include "Spaceship.h"


Spaceship::Spaceship() : GameObject(0,0)
{
    

}

Spaceship::Spaceship(double x, double y) : GameObject(x,y)
{
    north_bounds = 1.0;
    south_bounds = -0.135;
    east_bounds = 0.25;
    west_bounds = -0.25;
}

Spaceship::Spaceship(double x, double y, double scale, double degrees_per_second, double pixels_per_second) : GameObject( x,  y,  scale,  degrees_per_second,  pixels_per_second)
{
    north_bounds = 1.0;
    south_bounds = -0.135;
    east_bounds = 0.25;
    west_bounds = -0.25;
}
Spaceship::Spaceship(Spaceship &copy) : GameObject(copy)
{
    this->north_bounds = copy.get_north_bounds();
    this->south_bounds = copy.get_south_bounds();
    this->east_bounds = copy.get_east_bounds();
    this->west_bounds = copy.get_west_bounds();
}

void Spaceship::debug_draw_hitbox()
{
    glBegin(GL_LINE_LOOP);
    glColor3f(1, 1, 1);
    glVertex2f(east_bounds, north_bounds);
    glVertex2f(west_bounds, north_bounds);
    glVertex2f(west_bounds, south_bounds);
    glVertex2f(east_bounds, south_bounds);
    glEnd();
}

void Spaceship::draw()
{
    GameObject::draw(); //Applies Translate, Rotate, Scale

    if(get_debug_mode() == true)
    {
        // Draw Bounding Box
        debug_draw_hitbox();
    }
    // Draw Cockpit
    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.1, 0);
    glVertex2f(0.25, +0.125);
    glVertex2f(-0.25, +0.125);
    glVertex2f(-0.125, +0.-0.125);
    glVertex2f(0.125, +0.-0.125);
    glEnd();

    // Draw Right Wing125
    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.1, 0);
    glVertex2f(0, +0.125);
    glVertex2f(0.25, +0.125);
    glVertex2f(0.25, 1);
    glEnd();



    // Draw left Wing
    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.1, 0);
    glVertex2f(-0.25, +0.125);
    glVertex2f(0, +0.125);
    glVertex2f(-0.25, 1);
    glEnd();

    // Draw Outline
    glBegin(GL_LINE_LOOP);
    glColor3f(1, 0, 0);
    glVertex2f(0.01, +0.135);
    glVertex2f(-0.24, 1.01);
    glVertex2f(-0.26, 1.01);
    glVertex2f(-0.26, 0.115);
    glVertex2f(-0.135, -0.135);
    glVertex2f(0.135, -0.135);
    glVertex2f(0.26, 0.115);
    glVertex2f(0.26, 1.01);
    glVertex2f(0.24, 1.01);
    glVertex2f(-0.01, +0.135);
    glEnd();

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