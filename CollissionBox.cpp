#include "CollissionBox.h"

// Constructors
CollissionBox::CollissionBox() : GameObject(0,0)
{
    this->width = 1;
    this->height = 1;
}

CollissionBox::CollissionBox(double x, double y): GameObject(x,y)
{
    this->width = 1;
    this->height = 1;
}

CollissionBox::CollissionBox(double x, double y, double scale) : GameObject(x,y,scale,0,0)
{
    this->width = 1;
    this->height = 1;
}

CollissionBox::CollissionBox(double x, double y, double height, double width, double scale) : GameObject(x,y,scale,0,0)
{
    this->width = width;
    this->height = height;
}

CollissionBox::CollissionBox(CollissionBox &copy)  : GameObject(copy)
{
    this->width = copy.get_width();
    this->height = copy.get_height();
}

// Getters
double CollissionBox::get_height()
{
    return height;
}

double CollissionBox::get_width()
{
    return width;
}

double CollissionBox::get_north()
{
    return get_y() + height/2;
}

double CollissionBox::get_east()
{
    return get_x() + width/2;
}

double CollissionBox::get_south()
{
    return get_y() - height/2;
}

double CollissionBox::get_west()
{
    return get_x() - width/2;
}

// Setters
void CollissionBox::set_height(double height)
{
    this->height = height;
}

void CollissionBox::set_width(double width)
{
    this->width = width;
}

void CollissionBox::set_dimensions(double width, double height)
{
    this->height = height;
    this->width = width;
}
// Other Methods
void CollissionBox::draw()
{
    glBegin(GL_LINE_LOOP);
    glColor3f(1,1,1);
    glVertex2f(get_west(), get_south());
    glVertex2f(get_west(), get_north());
    glVertex2f(get_east(), get_north());
    glVertex2f(get_east(), get_south());
    glEnd();
}

bool CollissionBox::in_box(CollissionBox &other)
{
    return false;
}