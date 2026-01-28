#include "Point.h"

// accesseurs
float Point::getx() { return x; }
float Point::gety() { return y; }
// mutateurs
void Point::setx(float xs) { this->x = xs;}
void Point::sety(float ys) { this->y = ys;}
void Point::setCoords(float xs, float ys) 
{
    this->x = xs;
    this->y = ys;
}
// contructeurs
Point::Point()
{
    this->x = 0;
    this->y = 0;
}
Point::Point(float xi, float yi)
{
    this->x = xi;
    this->y = yi;
}
Point::Point(Point const &ref) {}