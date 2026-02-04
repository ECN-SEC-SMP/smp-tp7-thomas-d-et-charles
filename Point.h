#include <iostream>

using namespace std;

class Point
{
private:
    float x; //abcisse
    float y; //ordonnée

public:
    // accesseurs
    float getx() const;
    float gety() const;

    // mutateurs
    void setx(float xs);
    void sety(float ys);
    void setCoords(float xs, float ys);
    
    // methodes
    // -- translater
    void translater(int dx, int dy);
    void translater(Point p);

    // surcharge d'operateurs
    void operator += (const Point &);

    // contructeurs
    Point(); //sans paramètres
    Point(float xi, float yi); //avec 2 reels
    Point(Point const &ref); //

    // destructeur
    ~Point();
};

ostream & operator << (ostream&, const Point &);