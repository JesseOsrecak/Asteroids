#include <iostream>
#include "glFunctions.h"

using namespace std;
// using namespace glFunctions;

bool test_mode = false;
// for tests
#include "tests/collission_test.h"

int main(int argc, char **argv)
{
    if(test_mode)
    {
        collission_box_test();
    }
    
    cout << "Initiallising: " << endl;
    init(argc, argv);

    cout << "Launching: " << endl;
   
    // Is the event processing loop. This is actually the function that makes shit happen and should only ever happen once
    glutMainLoop();
    

    return(EXIT_SUCCESS);
}
