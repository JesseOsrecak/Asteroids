#include "Asteroid.h"
#include <random>
#include "math.h"
#include <iostream>
using namespace std;

Asteroid::Asteroid():GameObject(0,0)
{
    radius = (double)rand()/RAND_MAX /2 + 0.5;
    set_pixels_per_second(rand()%100 + 100);
    set_move_forward(true);
    set_last_update(glutGet(GLUT_ELAPSED_TIME)/1000.0);
}
Asteroid::Asteroid(double x, double y):GameObject(0,0)
{
    radius = (double)rand()/RAND_MAX /2 + 0.5;
    set_pixels_per_second(rand()%100 + 100);
    set_move_forward(true);
    set_last_update(glutGet(GLUT_ELAPSED_TIME)/1000.0);
}
Asteroid::Asteroid(double x,double y, double scale, double facing):GameObject(x,y,scale, facing)
{
    radius = (double)rand()/RAND_MAX /2 + 0.5;
    set_pixels_per_second(rand()%100 + 100);
    set_move_forward(true);
    set_last_update(glutGet(GLUT_ELAPSED_TIME)/1000.0);
}

Asteroid::Asteroid(double x,double y, double scale, double facing, double radius):GameObject(x,y,scale, facing)
{
    this->radius = radius;
    set_pixels_per_second(rand()%100 + 100);
    set_move_forward(true);
    set_last_update(glutGet(GLUT_ELAPSED_TIME)/1000.0);
}

Asteroid::Asteroid(Asteroid &other) : GameObject(other)
{
    this->radius = other.get_radius();
}   

Asteroid::~Asteroid()
{

}


double Asteroid::get_radius()
{
    return radius;
}
void Asteroid::set_radius(double radius)
{
    this->radius = radius;
}

void Asteroid::draw()
{
    glPushMatrix();
    GameObject::draw();
    int n = 50;
	float x, y;
	float theta;

    // Radius in this example is adjusted by Scale no need to do it here
    double r = radius;

	glColor3f(0,0,1);

    glLineWidth(2.0);
    glBegin(GL_POLYGON);

	for (int i = 0; i < n; i++)
	{
		theta = i / (float)n * 2.0 * M_PI;
		x = r * cosf(theta);
		y = r * sinf(theta);
		glVertex2f(x, y);
	}
	glEnd();
    glPopMatrix();

}

bool Asteroid::test_collission(CollissionBox * other)
{
    bool collission = false;
    Position * north_east = other->get_north_east();
    Position * north_west = other->get_north_west();
    Position * south_east = other->get_south_east();
    Position * south_west = other->get_south_west();

    if(pythagorean_theorem_find_hypotenuse(north_east->get_x()-get_x(), north_east->get_y() - get_y()) < radius * get_scale())
    {
        collission = true;
    }
    else if(pythagorean_theorem_find_hypotenuse(north_west->get_x()-get_x(), north_west->get_y() - get_y()) < radius * get_scale())
    {
        collission = true;
    }
    else if(pythagorean_theorem_find_hypotenuse(south_east->get_x()-get_x(), south_east->get_y() - get_y()) < radius * get_scale())
    {
        collission = true;
    }
    else if(pythagorean_theorem_find_hypotenuse(south_west->get_x()-get_x(), south_west->get_y() - get_y()) < radius * get_scale())
    {
        collission = true;
    }

    return collission;
}