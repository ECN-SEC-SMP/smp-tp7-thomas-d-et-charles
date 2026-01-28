#include "Forme.h"

class Cercle
{
private:
    Forme F;
public:
    Cercle();
    ~Cercle();

};

class Rectangle
{
private:
    Forme F;
public:
    Rectangle();
    ~Rectangle();
};

class Carre
{
private:
    Rectangle R;
public:
    Carre(/* args */);
    ~Carre();
};

