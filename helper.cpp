#include "helper.h"

bool collission_check(CollissionBox a, CollissionBox b)
{
    if (a.in_box(b) == true || b.in_box(a) == true)
        return true;
    else
        return false;
    return false;
}