#include "Forme.h"

// Constructeurs
Carre::Carre() : Rectangle()
{
}

Carre::Carre(Point dpRef, float dcote) : Rectangle(dpRef, dcote, dcote)
{
}

// Accesseur
float Carre::getCote() const
{
    return largeur; // ou hauteur, c'est la même chose
}

// Mutateur
void Carre::setCote(float dcote)
{
    this->largeur = dcote;
    this->hauteur = dcote;
}

// Surcharge de l'opérateur <<
ostream& operator<<(ostream& s, Carre const& c)
{
    s << "Carre : centre = " << c.getpRef() << ", cote = " << c.getCote() << endl;
    s << "  Perimetre = " << c.perimetre() << ", Surface = " << c.surface();
    return s;
}

// Destructeur
Carre::~Carre() {}
