#include <ostream>
using namespace std;

class Point
{
private:
    float x; //abcisse
    float y; //ordonnée
public:
    // accesseurs
    float getx()const;
    float gety()const;
    // mutateurs
    void setx(float xs);
    void sety(float ys);
    void setCoords(float xs, float ys);
    // surcharges
    void operator+=(Point const&c);
    // methodes
    // translater
    void translater(Point const&c);
    void translater(float xt, float yt); //avec 2 reels
    // contructeurs
    Point(); //sans paramètres
    Point(float xi, float yi); //avec 2 reels
    Point(Point const &ref);
    // destructeur
    ~Point();
};

ostream& operator<<(ostream&s, Point const&c); //surcharge <<

