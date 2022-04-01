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
        GameObject(GameObject &copy);
        
        double get_scale();
        double get_x();
        double get_y();

        void set_scale(double scale);
        string toString();

        void draw();


    private:
        double scale;
        double x;
        double y;
};

#endif //GAME_OBJECT_H