#include "Arena.h"
#include "helper.h"
#include <iostream>
using namespace std;

Arena::Arena() : GameObject(0,0)
{

}

Arena::Arena(double x, double y, double width, double height) : GameObject(x,y)
{
    this->width = width;
    this->height = height;
    // this->width = 100;
    // this->height = 100;
    set_scale(1);
}

Arena::Arena(Arena &copy) : GameObject(copy)
{
    this->width = copy.get_width();
    this->height = copy.get_height();
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

    // draw_north();
    // draw_south();
    // draw_east();
    // draw_west();

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
    // glColor3f(1,1,1);
    glColor3f(1,0,0);
    glVertex2f(width/2, height/2 -0.1);
    glVertex2f(width/2, height/2);
    glVertex2f(width/2 * -1, height/2);
    glVertex2f(width/2 * -1, height/2 -0.1);
    glEnd();

}

void Arena::draw_south()
{
    glBegin(GL_POLYGON);
    glColor3f(1,0,0);
    // glColor3f(1,1,1);
    glVertex2f(width/2, height/2* -1);
    glVertex2f(width/2, height/2*-1 +0.1);
    glVertex2f(width/2 * -1, height/2*-1 + 0.1);
    glVertex2f(width/2 * -1, height/2 *-1);
    glEnd();
}

void Arena::draw_east()
{
    glBegin(GL_POLYGON);
    // glColor3f(1,1,1);
    glColor3f(1,0,0);
    glVertex2f(width/2 * -1 + 0.1, height/2*-1);
    glVertex2f(width/2 * -1 + 0.1, height/2*1);
    glVertex2f(width/2 * -1, height/2*1);
    glVertex2f(width/2 * -1, height/2*-1);
    glEnd();
}

void Arena::draw_west()
{
    glBegin(GL_POLYGON);
    // glColor3f(1,1,1);
    glColor3f(1,0,0);
    glVertex2f(width/2, height/2*-1);
    glVertex2f(width/2, height/2*1);
    glVertex2f(width/2  -0.1, height/2*1);
    glVertex2f(width/2  -0.1, height/2*-1);
    glEnd();
}


bool Arena::in_collission_box(CollissionBox * object)
{
    bool collission = false;

    CollissionBox north_collision_box =  CollissionBox(0,(height/2) * get_scale() - 5, width, 10/get_scale(), get_scale(), 180);
    CollissionBox south_collision_box = CollissionBox(0, -1*(height/2)* get_scale() + 5, width, 10/get_scale(), get_scale(), 0);
    CollissionBox east_collision_box = CollissionBox((width/2)* get_scale() - 5, 0, height,  10/get_scale(), get_scale(), 90);
    CollissionBox west_collision_box = CollissionBox(-1*((width/2) * get_scale()) + 5, 0, height, 10/get_scale(),  get_scale(), 270);
    if (collission_check(north_collision_box, *object ) == true)
    {
        
        collission = true;
    }
    if (collission_check( south_collision_box, *object) == true)
    {
        
        collission = true;
    }
    if (collission_check( east_collision_box,*object) == true)
    {
        
        collission = true;
    }
    if (collission_check( west_collision_box, *object) == true)
    {
        
        collission = true;
    }

    return collission;
}