#include "Forme.h"
#include <cmath>

// Constructeurs
Cercle::Cercle() : Forme()
{
    this->rayon = 0;
}

Cercle::Cercle(Point dpRef, float drayon) : Forme(dpRef)
{
    this->rayon = drayon;
}

// Accesseur
float Cercle::getRayon() const
{
    return rayon;
}

// Mutateur
void Cercle::setRayon(float drayon)
{
    this->rayon = drayon;
}

// Méthodes
float Cercle::perimetre() const
{
    return 2 * M_PI * rayon;
}

float Cercle::surface() const
{
    return M_PI * rayon * rayon;
}

// Surcharge de l'opérateur <<
ostream& operator<<(ostream& s, Cercle const& c)
{
    s << "Cercle : centre = " << c.getpRef() << ", rayon = " << c.getRayon() << endl;
    s << "  Perimetre = " << c.perimetre() << ", Surface = " << c.surface();
    return s;
}

// Destructeur
Cercle::~Cercle() {}
