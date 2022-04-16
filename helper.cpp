#include "helper.h"
#include <iostream>
using namespace std;
bool collission_check(CollissionBox & a, CollissionBox & b)
{
    if (a.in_box(b) == true)
        return true;
    else
        return false;
    return false;
}