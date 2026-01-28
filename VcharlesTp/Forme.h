#include "Point.h"

class Forme
{
private:
    Point c; //centre
public:
    // constructeur
    Forme();
    // surcharges
    void operator+=(Forme const&f);
    // methodes
    virtual float perimetre();
    virtual float surface();
};

ostream& operator<<(ostream&s, Forme const&f);