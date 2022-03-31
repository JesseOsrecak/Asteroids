#include <iostream>

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

void init()
{
    // These Call only need to be done once currently. but they would normally go elsewhere eg dispolay
    glMatrixMode(GL_PROJECTION);
    // Sets the clipping plane. What Will/Won't be Rendered
    glOrtho(-960.0, 960.0, -540.0, 540.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{
    // Is used to iniialise the Glut Library. Parameters are from commandline and will use any command line parameters intended for it.
    glutInit(&argc, argv);
    /* "Sets the Initial Display Mode"
    GLUT_RGB is an alias for GLUT_RGBA
        GLUT_RGBA is a bitmask to slectan RGBA mode window. (This is also the defaultmode)
    GLUT_DOUBLE bit mask to slect a double buffered window. if GLUT_SINGLE is also selected it will overide it
        (A Double buffred window refers to one buffer displaying whilst the other is drawing and switch which buffer is doing which simultaneously)
        GLUT_SINGLE is used to select a single buffered window. this is the Default is not selected.
    GLUT_DEPTH is used to select a window with a Depth Buffer
    */
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    // Creates a top level window, the window in this case will be called "I3DG&A - Tutorial2"
    glutCreateWindow("I3DG&A - Tutorial 2");
    glutReshapeWindow(1920, 1080);
    init();

    // Sets the display function for the callback (Which function to call to draw stuff ect...) Each time the window needs to be redrawed this function will be called
    glutDisplayFunc(display);
    // Sets the keyboard callback for the current window. (Each time a key is pressed the function will be called)
    glutKeyboardFunc(keyboard);

    // Is the event processing loop. This is actually the function that makes shit happen and should only ever happen once
    glutMainLoop();

    return(EXIT_SUCCESS);
}
