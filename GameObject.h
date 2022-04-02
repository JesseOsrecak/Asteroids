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
using namespace std;


class GameObject
{
    public:

        GameObject(double x, double y);
        GameObject(double x, double y, double scale, double degrees_per_second, double pixels_per_second);
        GameObject(GameObject &copy);
        
        // Getters
        double get_scale();
        double get_x();
        double get_y();
        double get_facing();
        double get_pixels_per_second();
        double get_degrees_per_second();
        float get_last_update();

        // Setters
        void set_scale(double scale);
        void set_facing(double facing);
        void set_pixels_per_second(double pixels);
        void set_degrees_per_second(double degrees);

        // Other
        string toString();
        void draw();
        void updatePosition();
        
    protected:
        void set_last_update(float time);
        void moveForward(float time_elappsed);
        void rotate(float time_elappsed);

    private:
        double scale;
        double x;
        double y;
        double facing;
        double degrees_per_second;
        double pixels_per_second;

        float last_update;
};

#endif //GAME_OBJECT_H