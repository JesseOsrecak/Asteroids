#include "Bullet.h"

#include <iostream>
using namespace std;
Bullet::Bullet() : GameObject(0,0)
{
    set_last_update(glutGet(GLUT_ELAPSED_TIME)/1000.0);
    set_pixels_per_second(1000);
    north_bounds = 0.125;
    south_bounds = -0.125;
    east_bounds = 0.025;
    west_bounds = -0.025;
    collissionBox = new CollissionBox(get_x(), get_y(), (east_bounds - west_bounds), (north_bounds - south_bounds), get_scale(), get_facing());
}
Bullet::Bullet(double x, double y) : GameObject(x,y)
{
    set_last_update(glutGet(GLUT_ELAPSED_TIME)/1000.0);
    set_pixels_per_second(1000);
    north_bounds = 0.125;
    south_bounds = -0.125;
    east_bounds = 0.025;
    west_bounds = -0.025;
    collissionBox = new CollissionBox(get_x(), get_y(), (east_bounds - west_bounds), (north_bounds - south_bounds), get_scale(), get_facing());
}
Bullet::Bullet(double x, double y, double scale, double facing) : GameObject(x,y,scale,facing)
{
    set_last_update(glutGet(GLUT_ELAPSED_TIME)/1000.0);
    set_pixels_per_second(1000);
    north_bounds = 0.125;
    south_bounds = -0.125;
    east_bounds = 0.025;
    west_bounds = -0.025;
    collissionBox = new CollissionBox(get_x(), get_y(), (east_bounds - west_bounds), (north_bounds - south_bounds), get_scale(), get_facing());
}
Bullet::Bullet(Bullet &copy) : GameObject(copy)
{
    set_pixels_per_second(1000);
    north_bounds = 0.125;
    south_bounds = -0.125;
    east_bounds = 0.025;
    west_bounds = -0.025;
    collissionBox = copy.get_collission_box();
}
Bullet::~Bullet()
{
    delete collissionBox;
}

void Bullet::draw()
{
    

    glPushMatrix();
    GameObject::draw();
    glBegin(GL_POLYGON);
    glColor3f(0,1,0);
    
    glVertex2f(-0.025,-0.125);
    glVertex2f(0.025,-0.125);
    glVertex2f(0.025,0.125);
    glVertex2f(-0.025,0.125);
    
    glEnd();
    glPopMatrix();
}

CollissionBox * Bullet::get_collission_box()
{
    return collissionBox;
}

void Bullet::updatePosition()
{
    // cout<< "UPDATE"<<endl;
    GameObject::updatePosition();
    collissionBox->set_facing(get_facing());
    collissionBox->set_scale(get_scale());
    collissionBox->set_x(get_x());
    collissionBox->set_y(get_y());
    collissionBox->set_width(east_bounds - west_bounds);
    collissionBox->set_height(north_bounds - south_bounds);
    collissionBox->update_position();
}