#include "CollissionBox.h"
#include <iostream>
using namespace std;
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
    bool collission = false;
    // Check Vertex
    double other_north = other.get_north();
    double other_south = other.get_south();
    double other_east = other.get_east();
    double other_west = other.get_west();

    Position other_north_east = Position(other_east,other_north);
    Position other_north_west = Position(other_west, other_north);
    Position other_south_east = Position(other_south, other_east);
    Position other_south_west = Position(other_west, other_south);

    // Check Entire Object;
    if (other.get_x() >= get_west() && other.get_x() <= get_east() && other.get_y() >= get_south() and other.get_y() <= get_north())
    {
        collission = true;
    }

    // Check Verticies
    // Check Noth East
    
    else if (other_north_east.get_x() >= get_west() && other_north_east.get_x() <= get_east() && other_north_east.get_y() >= get_south() and other_north_east.get_y() <= get_north())
    {
        collission = true;
    }

    // Check North West
    
    else if (other_north_west.get_x() >= get_west() && other_north_west.get_x() <= get_east() && other_north_west.get_y() >= get_south() and other_north_west.get_y() <= get_north())
    {
        collission = true;
    }
    // Check South East
    
    else if (other_south_east.get_x() >= get_west() && other_south_east.get_x() <= get_east() && other_south_east.get_y() >= get_south() and other_south_east.get_y() <= get_north())
    {
        collission = true;
    }
    // Check South West
    
    else if (other_south_west.get_x() >= get_west() && other_south_west.get_x() <= get_east() && other_south_west.get_y() >= get_south() and other_south_west.get_y() <= get_north())
    {
        collission = true;
    }
    // Check Line Intersections
    else if (other_west <= get_east() && get_east() <= other_east && get_south() <= other_north && other_north <= get_north() )
    {
        // Collission with top other line and left current line
        // cout << "TOP, LEFT " << endl;
        collission = true;
    }
    else if (other_west <= get_west() && get_west() <= other_east  && get_south() <= other_north && other_north <= get_north())
    {
        // Collission with top other line and right current line
        // cout<< "TOP, RIGHT" << endl;
        collission = true;
    }
    else if (other_west <= get_east() && get_east() <= other_east && get_south() <= other_south && other_south <= get_north())
    {
        // Collission with bottom other line and left current line
        // cout<< "BOTTOM, LEFT" << endl;
        collission = true;
    }
    else if (other_west <= get_west() && get_west() <= other_east && get_south() <= other_south && other_south <+ get_north())
    {
        // Collission with bottom other line and right current line
        // cout<< "BOTTOM, RIGHT" << endl;
        collission = true;
    }
    else if (other_south <= get_north() && get_north() <= other_north && get_west() <= other_west && other_west <= get_east())
    {
        // Collission with right other line and top currnt line
        // cout << "RIGHT, TOP" <<endl;
        collission = true;
    }
    else if (other_south <= get_south() && get_south() <= other_north && get_west() <= other_west && other_west <= get_east())
    {
        // Collission with right other line and bottom current line
        // cout << "RIGHT, BOTTOM" <<endl;
        collission = true;
    }
    else if (other_south <= get_north() && get_north() <= other_north && get_west() <= other_east && other_east <= get_east())
    {
        // Collisson with left other line and top current line
        // cout << "LEFT, TOP" <<endl;
        collission = true;
    }
    else if (other_south <= get_south() && get_south() <= other_north && get_west() <= other_east && other_east <= get_east())
    {
        // Collission with left other line and bottom current line
        // cout << "LEFT, BOTTOM" <<endl;
        collission = true;
    }

    
    return collission;
}

