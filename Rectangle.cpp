#include "Forme.h"

// Constructeurs
Rectangle::Rectangle() : Forme()
{
    this->largeur = 0;
    this->hauteur = 0;
}

Rectangle::Rectangle(Point dpRef, float dlargeur, float dhauteur) : Forme(dpRef)
{
    this->largeur = dlargeur;
    this->hauteur = dhauteur;
}

// Accesseurs
float Rectangle::getLargeur() const
{
    return largeur;
}

float Rectangle::getHauteur() const
{
    return hauteur;
}

// Mutateurs
void Rectangle::setLargeur(float dlargeur)
{
    this->largeur = dlargeur;
}

void Rectangle::setHauteur(float dhauteur)
{
    this->hauteur = dhauteur;
}

// Méthodes
float Rectangle::perimetre() const
{
    return 2 * (largeur + hauteur);
}

float Rectangle::surface() const
{
    return largeur * hauteur;
}

// Surcharge de l'opérateur <<
ostream& operator<<(ostream& s, Rectangle const& r)
{
    s << "Rectangle : centre = " << r.getpRef() << ", largeur = " << r.getLargeur() << ", hauteur = " << r.getHauteur() << endl;
    s << "  Perimetre = " << r.perimetre() << ", Surface = " << r.surface();
    return s;
}

// Destructeur
Rectangle::~Rectangle() {}
