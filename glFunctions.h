#ifndef GL_FUNCTIONS_H
#define GL_FUNCTIONS_H


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

#include <iostream>





// Display function is the drawing Function
void display();
// Keyboard detects regular key presses
void keyboard(unsigned char key, int x, int y);
// Keyboard special detects special key presses
void keyboardSpecial(int key, int x, int y);

void reshape(int width, int height);

void init(int argc, char **argv);

// bool fullscreen;

#endif  // GL_FUNCTIONS_H



