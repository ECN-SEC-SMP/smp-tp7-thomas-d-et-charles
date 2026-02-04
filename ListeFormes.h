#include "Forme.h"
#include <vector>

class ListeFormes {
    private :
        vector<Forme*> formes;

    public :
        // Constructeur
        ListeFormes();

        // Méthodes
        void ajouterForme(Forme* f);
        Forme* getForme(int index) const;
        int getNbFormes() const;
        float surfaceTotale();
        void boiteEnglobante(float& xMin, float& xMax, float& yMin, float& yMax);

        // Destructeur
        ~ListeFormes();
};

ostream & operator << (ostream&, const ListeFormes &);
