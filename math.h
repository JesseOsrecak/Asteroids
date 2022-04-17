#ifndef MATH_H
#define MATH_H
#include "Position.h"
#include <cmath>

Position calculate_new_position(double x, double y, double angle, double distance);

double pythagorean_theorem_find_hypotenuse(double a, double b);

double to_radians(double angle);

double to_degrees(double angle);

double get_angle_from_2_positions(Position & origin, Position & destination);
// Position apply_scale(Position * origin, Position * point, double scale);
#define PI 3.14159265

#endif