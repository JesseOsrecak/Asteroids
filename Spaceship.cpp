#include "Spaceship.h"

Spaceship::Spaceship() : GameObject(0,0)
{
    
}

Spaceship::Spaceship(double x, double y) : GameObject(x,y)
{

}
Spaceship::Spaceship(Spaceship &copy) : GameObject(copy)
{

}

void Spaceship::draw()
{
    glTranslatef(get_x(), get_y(), 0);
    glScalef(get_scale(), get_scale(), 0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(0.5, -0.5);
    glVertex2f(-0.5, -0.5);
    glVertex2f(0, 1);
    glEnd();
}