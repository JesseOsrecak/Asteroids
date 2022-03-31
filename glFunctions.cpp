#include "glFunctions.h"


void display()
{
    // Clears sets the bitplane area of a window to values previously selected by glClearColor, glClearDepth ect..., (Clears the buffers)
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    // CODE GOES HERE

   


    int err;

    // Error Checking
    while ((err = glGetError()) != GL_NO_ERROR)
        printf("display: %s\n", gluErrorString(err));

    // If double buffred will swap the drawing and displaying buffers
    glutSwapBuffers();
    // Marks the window as needing to be redisplayed.( Call this method again)
    glutPostRedisplay();
}



void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27:
        case 'q':
            exit(EXIT_SUCCESS);
            break;
        default:
            break;

    }
}