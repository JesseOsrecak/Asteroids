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
    GameObject::draw(); //Applies Translate, Rotate, Scale

    // Draw Exhaust
    // glBegin(GL_POLYGON);
    // glColor3f(1, 0.3, 0.3);
    // glVertex2f(0.0625, +0.125);
    // glVertex2f(-0.0625, +0.125);
    // glVertex2f(0, -0.125);
    // glEnd();

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
    glVertex2f(-0.135, +0.-0.135);
    glVertex2f(0.135, +0.-0.135);
    glVertex2f(0.26, 0.115);
    glVertex2f(0.26, 1.01);
    glVertex2f(0.24, 1.01);
    glVertex2f(-0.01, +0.135);
    glEnd();
}