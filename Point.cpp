#include "Point.h"
// accesseurs
float Point::getx() const{ return x; }
float Point::gety() const{ return y; }
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

// Méthodes
void Point::translater(int dx, int dy)
{
    this->x += dx;
    this->y += dy;
}

void Point::translater(Point p)
{
    this->x += p.x;
    this->y += p.y;
}

// Surcharge de l'opérateur +=
void Point::operator+=(Point const& p)
{
    this->x += p.x;
    this->y += p.y;
}

ostream& operator << (ostream&s, const Point &c){
    s << "Point(" << c.getx() << ", " << c.gety() << ")" << endl;
    return s;
}

Point::~Point(){} // Nothing to do