#include "CollissionBox.h"
#include "math.h"
#include <iostream>
using namespace std;
// Constructors
CollissionBox::CollissionBox() : GameObject(0,0)
{
    this->width = 1;
    this->height = 1;

    north_east = new Position();
    north_west = new Position();
    south_east = new Position();
    south_west = new Position();
    update_position();
}

CollissionBox::CollissionBox(double x, double y): GameObject(x,y)
{
    this->width = 1;
    this->height = 1;
    
    north_east = new Position();
    north_west = new Position();
    south_east = new Position();
    south_west = new Position();
    update_position();
}

CollissionBox::CollissionBox(double x, double y, double width, double height) : GameObject(x,y,1,0)
{
    this->width = width;
    this->height = height;

    north_east = new Position();
    north_west = new Position();
    south_east = new Position();
    south_west = new Position();
    update_position();
}

CollissionBox::CollissionBox(double x, double y, double width, double height, double scale, double facing) : GameObject(x,y,scale,facing)
{

    this->width = width*scale;
    this->height = height*scale;
    north_east = new Position();
    north_west = new Position();
    south_east = new Position();
    south_west = new Position();
    update_position();
}

CollissionBox::CollissionBox(CollissionBox &copy)  : GameObject(copy)
{
    this->width = copy.get_width();
    this->height = copy.get_height();
    north_east = new Position();
    north_west = new Position();
    south_east = new Position();
    south_west = new Position();
    update_position();
}



CollissionBox::~CollissionBox()
{
    delete north_east; 
    delete north_west;
    delete south_east;
    delete south_west;
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

Position * CollissionBox::get_north_east()
{
    return north_east;
}
Position * CollissionBox::get_north_west()
{
    return north_west;
}
Position * CollissionBox::get_south_east()
{
    return south_east;
}
Position * CollissionBox::get_south_west()
{
    return south_west;
}

// Setters
void CollissionBox::set_height(double height)
{
    this->height = height * get_scale();
}

void CollissionBox::set_width(double width)
{
    this->width = width * get_scale();
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

    glVertex2f(north_east->get_x(), north_east->get_y());
    glVertex2f(north_west->get_x(), north_west->get_y());
    glVertex2f(south_west->get_x(), south_west->get_y());
    glVertex2f(south_east->get_x(), south_east->get_y());

    glEnd();
}

void CollissionBox::update_position()
{
    
    north_east->set_x(get_east());
    north_east->set_y(get_north());

    north_west->set_x(get_west());
    north_west->set_y(get_north());

    south_west->set_x(get_west());
    south_west->set_y(get_south());

    south_east->set_x(get_east());
    south_east->set_y(get_south());
    cout<<"UPDATE"<<endl<<endl;
    cout<<north_west->toString()<<north_east->toString()<<endl<<south_west->toString()<<south_east->toString()<<endl;

    double h = height /2;
    double w = width /2 ;
    // Quadrant 1
    if (get_facing() < 90)
    {
        double feta = get_facing();
        double beta = 90 - feta;
        Position p = Position(h*sin(feta) * -1 + get_x(), h*cos(feta) + get_y());
        // North East
        north_east->set_x(w*cos(beta)+p.get_x());
        north_east->set_y(w*sin(beta)+p.get_y());
        // North West
        north_west->set_x(-1*width*sin(beta)+north_east->get_x());
        north_west->set_y(-1*width*cos(beta)+north_east->get_y());
        // Sout East
        south_east->set_x(height*sin(feta)+north_east->get_x());
        south_east->set_y(-1*height*cos(feta)+north_east->get_y());
        // South West
        south_west->set_x(height*sin(feta)+north_west->get_x());
        south_west->set_y(-1*height*cos(feta)+north_west->get_y());

    }
    // Quadrant 2
    else if(get_facing() < 180)
    {
        double feta= get_facing() - 90;
        double beta = 90 - feta;
        Position p = Position(-1*h*cos(feta) + get_x(), -1 * h * sin(feta) + get_y());
        // North East
        north_east->set_x(-1*w*cos(beta)+p.get_x());
        north_east->set_y(w*sin(beta)+p.get_y());
        // North West
        north_west->set_x(-1*width*sin(beta)+north_east->get_x());
        north_west->set_y(-1*width*cos(beta)+north_east->get_y());
        // Sout East
        south_east->set_x(height*cos(feta)+north_east->get_x());
        south_east->set_y(height*sin(feta)+north_east->get_y());
        // South West
        south_west->set_x(height*cos(feta)+north_west->get_x());
        south_west->set_y(height*sin(feta)+north_west->get_y());
    }
    // Quadrant 3
    else if(get_facing() < 270)
    {
        double feta= get_facing() - 180;
        double beta = 90 - feta;
        Position p = Position(-1*h*sin(feta)+get_x(), -1*h*cos(feta)+get_y());
        // North East
        north_east->set_x(-1*w*sin(beta)+p.get_x());
        north_east->set_y(-1*w*cos(beta)+p.get_y());
        // North West
        north_west->set_x(width*sin(beta)+north_east->get_x());
        north_west->set_y(width*cos(beta)+north_east->get_y());
        // Sout East
        south_east->set_x(-1*height*sin(feta)+north_east->get_x());
        south_east->set_y(height*cos(feta)+north_east->get_y());
        // South West
        south_west->set_x(-1*height*sin(feta)+north_west->get_x());
        south_west->set_y(height*cos(feta)+north_west->get_y());
    }
    else
    {
        double feta= get_facing() - 270;
        double beta = 90 - feta;
        Position p = Position(h*cos(feta), h*sin(feta));
        // North East
        north_east->set_x(-1*w*sin(beta)+p.get_x());
        north_east->set_y(w*cos(beta)+p.get_y());
        // North West
        north_west->set_x(-1*width*sin(beta)+north_east->get_x());
        north_west->set_y(width*cos(beta)+north_east->get_y());
        // Sout East
        south_east->set_x(-1*height*cos(feta)+north_east->get_x());
        south_east->set_y(-1*height*sin(feta)+north_east->get_y());
        // South West
        south_west->set_x(-1*height*cos(feta)+north_west->get_x());
        south_west->set_y(-1*height*sin(feta)+north_west->get_y());
    }

    cout<<north_west->toString()<<north_east->toString()<<endl<<south_west->toString()<<south_east->toString()<<endl<<endl;

}

bool CollissionBox::in_box(CollissionBox &other)
{
    
    bool collission = false;
    // Check Vertex
    double other_north = other.get_north();
    double other_south = other.get_south();
    double other_east = other.get_east();
    double other_west = other.get_west();

    Position * other_north_east = other.get_north_east();
    Position * other_north_west = other.get_north_west();
    Position * other_south_east = other.get_south_east();
    Position * other_south_west = other.get_south_west();

    
    // Check Entire Object;
    if (other.get_x() >= get_west() && other.get_x() <= get_east() && other.get_y() >= get_south() and other.get_y() <= get_north())
    {
        collission = true;
    }

    // Check Verticies
    // Check Noth East
    
    else if (other_north_east->get_x() >= get_west() && other_north_east->get_x() <= get_east() && other_north_east->get_y() >= get_south() and other_north_east->get_y() <= get_north())
    {
        collission = true;
    }

    // Check North West
    
    else if (other_north_west->get_x() >= get_west() && other_north_west->get_x() <= get_east() && other_north_west->get_y() >= get_south() and other_north_west->get_y() <= get_north())
    {
        collission = true;
    }
    // Check South East
    
    else if (other_south_east->get_x() >= get_west() && other_south_east->get_x() <= get_east() && other_south_east->get_y() >= get_south() and other_south_east->get_y() <= get_north())
    {
        collission = true;
    }
    // Check South West
    
    else if (other_south_west->get_x() >= get_west() && other_south_west->get_x() <= get_east() && other_south_west->get_y() >= get_south() and other_south_west->get_y() <= get_north())
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

