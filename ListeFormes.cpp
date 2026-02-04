#include "ListeFormes.h"
#include <limits>

// Constructeur
ListeFormes::ListeFormes()
{
}

// Méthodes
void ListeFormes::ajouterForme(Forme* f)
{
    formes.push_back(f);
}

Forme* ListeFormes::getForme(int index) const
{
    if (index >= 0 && index < formes.size())
        return formes[index];
    return nullptr;
}

int ListeFormes::getNbFormes() const
{
    return formes.size();
}

float ListeFormes::surfaceTotale()
{
    float total = 0;
    for (int i = 0; i < formes.size(); i++)
    {
        total += formes[i]->surface();
    }
    return total;
}

void ListeFormes::boiteEnglobante(float& xMin, float& xMax, float& yMin, float& yMax)
{
    if (formes.empty())
    {
        xMin = xMax = yMin = yMax = 0;
        return;
    }

    xMin = numeric_limits<float>::max();
    xMax = numeric_limits<float>::lowest();
    yMin = numeric_limits<float>::max();
    yMax = numeric_limits<float>::lowest();

    for (int i = 0; i < formes.size(); i++)
    {
        Point pRef = formes[i]->getpRef();
        float px = pRef.getx();
        float py = pRef.gety();

        // Déterminer les limites selon le type de forme
        Cercle* c = dynamic_cast<Cercle*>(formes[i]);
        if (c != nullptr)
        {
            float r = c->getRayon();
            xMin = min(xMin, px - r);
            xMax = max(xMax, px + r);
            yMin = min(yMin, py - r);
            yMax = max(yMax, py + r);
        }
        else
        {
            Rectangle* r = dynamic_cast<Rectangle*>(formes[i]);
            if (r != nullptr)
            {
                float l = r->getLargeur() / 2.0;
                float h = r->getHauteur() / 2.0;
                xMin = min(xMin, px - l);
                xMax = max(xMax, px + l);
                yMin = min(yMin, py - h);
                yMax = max(yMax, py + h);
            }
        }
    }
}

// Surcharge de l'opérateur <<
ostream& operator<<(ostream& s, ListeFormes const& lf)
{
    s << "Liste de " << lf.getNbFormes() << " formes :" << endl;
    for (int i = 0; i < lf.getNbFormes(); i++)
    {
        Forme* f = lf.getForme(i);
        Cercle* c = dynamic_cast<Cercle*>(f);
        if (c != nullptr)
        {
            s << "  " << *c << endl;
        }
        else
        {
            Carre* ca = dynamic_cast<Carre*>(f);
            if (ca != nullptr)
            {
                s << "  " << *ca << endl;
            }
            else
            {
                Rectangle* r = dynamic_cast<Rectangle*>(f);
                if (r != nullptr)
                {
                    s << "  " << *r << endl;
                }
            }
        }
    }
    return s;
}

// Destructeur
ListeFormes::~ListeFormes()
{
    // Libération de la mémoire
    for (int i = 0; i < formes.size(); i++)
    {
        delete formes[i];
    }
    formes.clear();
}
