#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#if _WIN32
#include <windows.h>
#endif
#if _APPLE_
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT.glut.h>
#else 
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif

#include <string>
#include "Position.h"
using namespace std;


class GameObject
{
    public:

        GameObject(double x, double y);
        GameObject(double x, double y, double scale, double degrees_per_second, double pixels_per_second);
        GameObject(double x, double y, double scale, double facing);
        GameObject(GameObject &copy);
        
        // Getters
        double get_scale();
        double get_x();
        double get_y();
        double get_facing();
        double get_pixels_per_second();
        double get_degrees_per_second();
        
        float get_last_update();

        bool get_rotate_left();
        bool get_rotate_right();
        bool get_move_forward();
        bool get_debug_mode();

        Position get_position();
        // Setters
        void set_scale(double scale);
        void set_facing(double facing);
        void set_pixels_per_second(double pixels);
        void set_degrees_per_second(double degrees);
        void set_last_update(double time);
        void set_x(double x);
        void set_y(double y);


        void set_rotate_left(bool rotate);
        void set_rotate_right(bool roate);
        void set_move_forward(bool move);
        void set_debug_mode(bool debug_mode);

        void set_position( Position position);
        // Other
        string toString();
        void draw();
        void debug_draw();
        // void debug_draw_hitbox();
        void updatePosition();
        void moveForward(double time_elappsed);
        void rotateRight(double time_elappsed);
        void rotateLeft(double time_elappsed);
        void resetMovement();
        


        

        
    protected:
        
        

    private:
        double scale;
        // double x;
        // double y;
        double facing;
        double degrees_per_second;
        double pixels_per_second;

        bool rotate_left;
        bool rotate_right;
        bool move_forward;
        bool debug_mode;
        float last_update;

        Position position;

};

#endif //GAME_OBJECT_H