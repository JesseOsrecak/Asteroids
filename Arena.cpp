#include "Arena.h"
#include "helper.h"
#include <iostream>
using namespace std;

Arena::Arena() : GameObject(0,0)
{
        close_north = false;
        close_east = false;
        close_south = false;
        close_west = false;
}

Arena::Arena(double x, double y, double width, double height) : GameObject(x,y)
{
    this->width = width;
    this->height = height;
    close_north = false;
    close_east = false;
    close_south = false;
    close_west = false;
    set_scale(1);
}

Arena::Arena(Arena &copy) : GameObject(copy)
{
    this->width = copy.get_width();
    this->height = copy.get_height();
    close_north = false;
    close_east = false;
    close_south = false;
    close_west = false;
}

void Arena::draw()
{
    GameObject::draw();


    // glBegin(GL_LINE_LOOP);
    glBegin(GL_POLYGON);
    glColor3f(0.5,0.5,0.5);
    glVertex2f(width/2, height/2*-1);
    glVertex2f(width/2, height/2*1);
    glVertex2f(width/2 * -1, height/2*1);
    glVertex2f(width/2 * -1, height/2*-1);
    glEnd();



    draw_north();
    draw_south();
    draw_east();
    draw_west();

    close_north = false;
    close_east = false;
    close_south = false;
    close_west = false;

    // if (get_debug_mode() == true)
    // {
    //     debug_draw();
    // }
}

void Arena::debug_draw()
{

    CollissionBox north_collision_box =  CollissionBox(0,(height/2) * get_scale() - 5, width, 10/get_scale(), get_scale(), 180);
    CollissionBox south_collision_box = CollissionBox(0, -1*(height/2)* get_scale() + 5, width, 10/get_scale(), get_scale(), 0);
    CollissionBox east_collision_box = CollissionBox((width/2)* get_scale() - 5, 0, height,  10/get_scale(), get_scale(), 90);
    CollissionBox west_collision_box = CollissionBox(-1*((width/2) * get_scale()) + 5, 0, height, 10/get_scale(),  get_scale(), 270);

    north_collision_box.draw();
    south_collision_box.draw();
    east_collision_box.draw();
    west_collision_box.draw();

}

double Arena::get_height()
{
    return height;
}

double Arena::get_width()
{
    return width;
}

void Arena::draw_north()
{
    glBegin(GL_POLYGON);

    if(close_north == true)
    {
        glColor3f(1,0,0);
    }
    else
    {
        glColor3f(1,1,1);
    }


    glVertex2f(width/2, height/2 -0.1);
    glVertex2f(width/2, height/2);
    glVertex2f(width/2 * -1, height/2);
    glVertex2f(width/2 * -1, height/2 -0.1);
    glEnd();

}

void Arena::draw_south()
{
    glBegin(GL_POLYGON);
    

    if(close_south == true)
    {
        glColor3f(1,0,0);
    }
    else
    {
        glColor3f(1,1,1);
    }
    glVertex2f(width/2, height/2* -1);
    glVertex2f(width/2, height/2*-1 +0.1);
    glVertex2f(width/2 * -1, height/2*-1 + 0.1);
    glVertex2f(width/2 * -1, height/2 *-1);
    glEnd();
}

void Arena::draw_west()
{
    glBegin(GL_POLYGON);

    if( close_west == true)
    {
        glColor3f(1,0,0);
    }
    else
    {
        glColor3f(1,1,1);
    }
    glVertex2f(width/2 * -1 + 0.1, height/2*-1);
    glVertex2f(width/2 * -1 + 0.1, height/2*1);
    glVertex2f(width/2 * -1, height/2*1);
    glVertex2f(width/2 * -1, height/2*-1);
    glEnd();
}

void Arena::draw_east()
{
    glBegin(GL_POLYGON);

    if(close_east == true)
    {
        glColor3f(1,0,0);
    }
    else
    {
        glColor3f(1,1,1);
    }
    glVertex2f(width/2, height/2*-1);
    glVertex2f(width/2, height/2*1);
    glVertex2f(width/2  -0.1, height/2*1);
    glVertex2f(width/2  -0.1, height/2*-1);
    glEnd();
}


bool Arena::in_collission_box(CollissionBox * object)
{
    bool collission = false;
    isClose(object);
    CollissionBox north_collision_box =  CollissionBox(0,(height/2) * get_scale() - 5, width, 10/get_scale(), get_scale(), 180);
    CollissionBox south_collision_box = CollissionBox(0, -1*(height/2)* get_scale() + 5, width, 10/get_scale(), get_scale(), 0);
    CollissionBox east_collision_box = CollissionBox((width/2)* get_scale() - 5, 0, height,  10/get_scale(), get_scale(), 90);
    CollissionBox west_collision_box = CollissionBox(-1*((width/2) * get_scale()) + 5, 0, height, 10/get_scale(),  get_scale(), 270);
    if (collission_check(north_collision_box, *object ) == true)
    {
        
        collission = true;
    }
    else if (collission_check( south_collision_box, *object) == true)
    {
        
        collission = true;
    }
    else if (collission_check( east_collision_box,*object) == true)
    {
        
        collission = true;
    }
    else if (collission_check( west_collision_box, *object) == true)
    {
        
        collission = true;
    }

    return collission;
}


void Arena::isClose(CollissionBox * object)
{
    CollissionBox north_close_box = CollissionBox(0,(height/2) * get_scale() - 30, width, 60/get_scale(), get_scale(), 180);
    CollissionBox south_close_box = CollissionBox(0, -1*(height/2)* get_scale() + 30, width, 60/get_scale(), get_scale(), 0);
    CollissionBox east_close_box  = CollissionBox((width/2)* get_scale() - 30, 0, height,  60/get_scale(), get_scale(), 90);
    CollissionBox west_close_box  = CollissionBox(-1*((width/2) * get_scale()) + 30, 0, height, 60/get_scale(),  get_scale(), 270);

    if (collission_check(north_close_box, *object ) == true)
    {
        
        close_north = true;
    }
    if (collission_check( south_close_box, *object) == true)
    {
        
        close_south = true;
    }
    if (collission_check( east_close_box, *object) == true)
    {
        
        close_east = true;
    }
    if (collission_check( west_close_box, *object) == true)
    {
        
        close_west = true;
    }
}