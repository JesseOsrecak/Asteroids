#include "glFunctions.h"
#include "Spaceship.h"
#include "Arena.h"
#include "helper.h"
#include "AsteroidLaunchArea.h"
#include "Asteroid.h"
#include "math.h"
#include <iostream>

using namespace std;

Spaceship *player1;
Arena *arena;
AsteroidLaunchArea * asteroidLaunchArea;
vector<Asteroid * >  asteroids;
bool fullscreen = true;

double res_width = 1280;
double res_height = 720;

bool debug_mode = false;
void display()
{
    // Clears sets the bitplane area of a window to values previously selected by glClearColor, glClearDepth ect..., (Clears the buffers)
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);



    // CODE GOES HERE
    glPushMatrix();
    arena->draw();
    glPopMatrix();
    // Draw Spaceship
    glPushMatrix();
    player1->draw();
    glPopMatrix();
    
    player1->draw_bullets();

    for(Asteroid * asteroid : asteroids)
    {
        asteroid->draw();
    }

    if (debug_mode)
    {
        glPushMatrix();
            // cout << "Player 1: " << endl;
            player1->get_collission_box()->draw();
            // cout << "Arena: " <<endl;
            arena->debug_draw();
            vector<Bullet *> bullets = player1->get_bullets();
            for (Bullet * bullet : bullets)
            {
                bullet->get_collission_box()->draw();
            }
        glPopMatrix();
    }
    


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
            player1->set_move_forward(true);
            break;
        case 'a':
        case 'A':
            player1->set_rotate_left(true);
            break;
        case 'd':
        case 'D':
            player1->set_rotate_right(true);
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
            player1->set_move_forward(false);
            break;
        case 'a':
        case 'A':
            player1->set_rotate_left(false);
            break;
        case 'd':
        case 'D':
            player1->set_rotate_right(false);
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
            set_debug_mode();
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

void mouse_function(int button, int state, int x, int y)
{
    switch (button)
    {
        case GLUT_LEFT_BUTTON:
            
            if(state == GLUT_DOWN)
            {
                player1->set_trigger_down(true);
            }
            else
            {
                player1->set_trigger_down(false);
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
    // glOrtho(16*new_scale/2*-1, 16*new_scale/2,9*new_scale/2*-1, 9*new_scale/2, -1.0, 1.0);

    double old_scale = arena->get_scale();
    double new_scale = width/16;

    if (height < new_scale*9)
    {
        new_scale = height/9;
    }

    arena->set_scale(new_scale);
    asteroidLaunchArea->set_scale(new_scale);
    double mult_factor = new_scale / old_scale;

    player1->set_x(player1->get_x()/(16*old_scale) * 16*new_scale );
    player1->set_y(player1->get_y()/(9*old_scale) * 9 * new_scale);
    player1->set_scale(player1->get_scale() * mult_factor);

    for(Asteroid * asteroid : asteroids)
    {
        asteroid->set_x(asteroid->get_x()/(16*old_scale) * 16*new_scale );
        asteroid->set_y(asteroid->get_y()/(9*old_scale) * 9 * new_scale);
        asteroid->set_scale(asteroid->get_scale() * mult_factor);

    }

    res_width = glutGet(GLUT_WINDOW_WIDTH);
    res_height = glutGet(GLUT_WINDOW_HEIGHT);


    
}


void idle()
{

    // Update All object Positions
    collission_detection();
    
    player1->updatePosition();
    for(Asteroid * asteroid : asteroids)
    {
        asteroid->updatePosition();
    }

    if (asteroids.size() <= 3)
    {
        spawn_asteroid_wave();
    }
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

    glutMouseFunc(mouse_function);

    generateObjects();

    
    
}


void generateObjects()
{
    // Initialize Game Objects
    player1 = new Spaceship(0,0, 50, 360, 300);
    arena = new Arena(0,0, 16, 9);
    asteroidLaunchArea = new AsteroidLaunchArea(20, 120);
    arena->set_scale(120);
    spawn_asteroid_wave();

}

void set_debug_mode()
{
    if(debug_mode == true)
        debug_mode = false;
    else
        debug_mode = true;
    // TODO go through the list of objects that debug mode needs to be set to true/false
    player1->set_debug_mode(debug_mode);
    arena->set_debug_mode(debug_mode);
    
}

int collission_num = 0;
void collission_detection()
{
    
    arena->isClose(player1->get_collission_box());

    if(arena->in_collission_box(player1->get_collission_box()) == true)
    {
        // collission_num++;
        player1->set_x(0);
        player1->set_y(0);
        // cout << "collision: "<< to_string(collission_num) << endl;
    }

    vector<Bullet * > bullets  = player1->get_bullets();
    vector<int> delete_list_asteroid;
    vector<int> delete_list_bullet;
    int index_bullet = 0;
    int index_asteroid = 0;
    for (Bullet * bullet : bullets)
    {
        if ( arena->in_collission_box(bullet->get_collission_box()))
        {
            // remove bullet;
            delete_list_bullet.insert(delete_list_bullet.begin(), index_bullet);
        }
        else
        {
            // Check for collission with asteroid
            for (Asteroid * asteroid : asteroids)
            {
                if(asteroid->test_collission(bullet->get_collission_box()))
                {
                    // remove bullet;
                    delete_list_bullet.insert(delete_list_bullet.begin(), index_bullet);
                    delete_list_asteroid.insert(delete_list_asteroid.begin(), index_asteroid);
                }

                index_asteroid++;
            }
            index_asteroid = 0;
            
        }
        index_bullet++;
    }
    
    

    
    
    for (Asteroid * asteroid : asteroids)
    {
        
        if(asteroidLaunchArea->out_of_bounds(asteroid->get_position()))
        {
            delete_list_asteroid.insert(delete_list_asteroid.begin(), index_asteroid);
        }
        else
        {
            // Check for Collission With Player:
            if(asteroid->test_collission(player1->get_collission_box()))
            {
                // remove bullet;
                player1->set_x(0);
                player1->set_y(0);
                asteroids.clear();
                spawn_asteroid_wave();

            }
        }
        index_asteroid++;
    }
    for(int i = delete_list_asteroid.size() - 1; i >= 0; i--)
    {
        asteroids.erase(asteroids.begin() + delete_list_asteroid[i] );
    }

    player1->delete_bullets(delete_list_bullet);

}


void spawn_asteroid()
{
    
    // Position location = Position(-1000,1000);
    Position location = asteroidLaunchArea->get_location();
    double facing = get_angle_from_2_positions(location, *player1->get_position());
    Asteroid * asteroid = new Asteroid(location.get_x(), location.get_y(), player1->get_scale(), facing);
    asteroids.push_back(asteroid);


}

void spawn_asteroid_wave()
{
    for(int i = 0; i < 10; i++)
    {
        spawn_asteroid();
    }
}

// End glFunctions
