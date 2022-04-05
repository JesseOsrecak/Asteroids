#include "glFunctions.h"
#include "Spaceship.h"
#include "Arena.h"
#include <iostream>

using namespace std;

Spaceship player1;
Arena arena;
bool fullscreen = true;

double res_width = 1280;
double res_height = 720;


void display()
{
    // Clears sets the bitplane area of a window to values previously selected by glClearColor, glClearDepth ect..., (Clears the buffers)
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    // CODE GOES HERE
    // Draw Spaceship
    glPushMatrix();
    player1.draw();
    glPopMatrix();

    glPushMatrix();
    arena.draw();
    glPopMatrix();


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
        // This is for the ESC KEZY Detection
        case 27:
            exit(EXIT_SUCCESS);
            break;
        case 'w':
        case 'W':
            player1.set_move_forward(true);
            break;
        case 'a':
        case 'A':
            player1.set_rotate_left(true);
            break;
        case 'd':
        case 'D':
            player1.set_rotate_right(true);
            break;
        default:
            break;

    }
}

void keyboardUp(unsigned char key, int x, int y)
{
    switch (key)
    {
                case 'w':
        case 'W':
            player1.set_move_forward(false);
            break;
        case 'a':
        case 'A':
            player1.set_rotate_left(false);
            break;
        case 'd':
        case 'D':
            player1.set_rotate_right(false);
            break;
        default:
            break;
    }
}

void keyboardSpecial(int key, int x, int y)
{
    switch (key)
    {
        // f1
        case 1:
            break;
        // f2
        case 2:
            break;
        // f3
        case 3:
            break;
        // f4
        case 4:
            break;
        // f5
        case 5:
            break;
        // f6
        case 6:
            break;
        // f7
        case 7:
            break;
        // f8
        case 8:
            break;
        // f9
        case 9:
            break;
        // f10
        case 10:
            break;
        // f11
        case 11:
            // This Enables and disables full Screen mode. bu positioning window instead of Reshapoing Window. Reshape function is only called once not twice.
            if (fullscreen == false)
            {
                glutFullScreen();
                fullscreen = true;
            }
            else
            {
                glutPositionWindow(0,0);
                fullscreen = false;
            }

            break;
        default:
            break;
    }
}

void reshape(int width, int height)
{
    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(width/2*-1, width/2, height/2*-1, height/2, -1.0, 1.0);

    double old_scale = arena.get_scale();
    double new_scale = width/16;

    if (height < new_scale*9)
    {
        new_scale = height/9;
    }

    arena.set_scale(new_scale);

    double mult_factor = new_scale / old_scale;

    player1.set_scale(player1.get_scale() * mult_factor);

    res_width = glutGet(GLUT_WINDOW_WIDTH);
    res_height = glutGet(GLUT_WINDOW_HEIGHT);


    
}


void idle()
{

    // Update All object Positions
    player1.updatePosition();
    glutPostRedisplay();
}

void init(int argc, char **argv)
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

   // Sets the clipping plane. What Will/Won't be Rendered
    glOrtho(res_width/2*-1, res_width/2, res_height/2*-1, res_height/2, -1.0, 1.0);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    // Sets the Initial Size of the Window
    glutInitWindowSize(res_width, res_height);
    // Creates a top level window, the window in this case will be called "Asteroids"
    glutCreateWindow("Asteroids");
    // / Sets Screen into Fullscren Mode
    glutFullScreen();
    
    
    // These Call only need to be done once currently. but they would normally go elsewhere eg dispolay
    glMatrixMode(GL_PROJECTION);
    

    glutReshapeFunc(reshape);
    // Sets the display function for the callback (Which function to call to draw stuff ect...) Each time the window needs to be redrawed this function will be called
    glutDisplayFunc(display);
    // Sets the keyboard callback for the current window. (Each time a key is pressed the function will be called)
    glutKeyboardFunc(keyboard);
    glutKeyboardUpFunc(keyboardUp);
    glutSpecialFunc(keyboardSpecial);

    glutIdleFunc(idle);

    generateObjects();

    
    
}


void generateObjects()
{
    // Initialize Game Objects
    player1 = Spaceship(0,0, 50, 360, 300);
    arena = Arena(0,0, 16, 9);
    arena.set_scale(120);

}