#include <iostream>
#include "glFunctions.h"

using namespace std;
// using namespace glFunctions;



int main(int argc, char **argv)
{
    
    // glutFullScreen();
    init(argc, argv);

    

   
    // Is the event processing loop. This is actually the function that makes shit happen and should only ever happen once
    glutMainLoop();
    

    return(EXIT_SUCCESS);
}
