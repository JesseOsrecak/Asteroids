#ifndef MATH_H
#define MATH_H
#include "Position.h"
#include <cmath>

Position calculate_new_position(double x, double y, double angle, double distance);

double pythagorean_theorem_find_hypotenuse(double a, double b);

// Position apply_scale(Position * origin, Position * point, double scale);
#define PI 3.14159265

#endif