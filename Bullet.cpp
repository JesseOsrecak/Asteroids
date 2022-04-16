#include "Bullet.h"


Bullet::Bullet() : GameObject(0,0)
{
    set_pixels_per_second(10);
}
Bullet::Bullet(double x, double y) : GameObject(x,y)
{
    set_pixels_per_second(10);
}
Bullet::Bullet(double x, double y, double scale, double facing) : GameObject(x,y,scale,facing)
{
    set_pixels_per_second(10);
}
Bullet::Bullet(Bullet &copy) : GameObject(copy)
{
    set_pixels_per_second(10);
}
Bullet::~Bullet()
{

}