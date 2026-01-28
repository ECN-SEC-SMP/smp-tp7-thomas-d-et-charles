#include "Point.h"

// surcharges
ostream& operator<<(ostream&s, Point const&c)
{
    s << " x : " << c.getx() << " y : " << c.gety() ;
    return s;
}
void Point::operator+=(Point const&c)
{
    x += c.x;
    y += c.y;
}

// methodes
// -- translater
void Point::translater(Point const&c) { *this += c; }
void Point::translater(float xt, float yt)
{
    x += xt;
    y += yt;
}

// accesseurs
float Point::getx()const { return x; }
float Point::gety()const { return y; }

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
Point::Point(Point const &ref) 
{
    this->x = ref.x;
    this->y = ref.y;
}

// destructeur
Point::~Point() {}