#include "Point.h"

class Forme {
    private :
        Point pRef;

    public :
        // Constructeurs
        Forme();
        Forme(Point dpRef);
        // Accesseur
        Point getpRef() const;
        // Surchages
        void operator += (const Point &);
        // Méthodes abstraites
        virtual float perimetre() const = 0;
        virtual float surface() const = 0;

        // Destructeur virtuel
        virtual ~Forme();
};

ostream & operator << (ostream&, const Forme &);

// ======== CLASSE CERCLE ========
class Cercle : public Forme {
    private :
        float rayon;

    public :
        // Constructeurs
        Cercle();
        Cercle(Point dpRef, float drayon);

        // Accesseur
        float getRayon() const;

        // Mutateur
        void setRayon(float drayon);

        // Méthodes virtuelles
        float perimetre() const override;
        float surface() const override;

        // Destructeur
        ~Cercle();
};

ostream & operator << (ostream&, const Cercle &);

// ======== CLASSE RECTANGLE ========
class Rectangle : public Forme {
    protected :
        float largeur;
        float hauteur;

    public :
        // Constructeurs
        Rectangle();
        Rectangle(Point dpRef, float dlargeur, float dhauteur);

        // Accesseurs
        float getLargeur() const;
        float getHauteur() const;

        // Mutateurs
        void setLargeur(float dlargeur);
        void setHauteur(float dhauteur);

        // Méthodes virtuelles
        float perimetre() const override;
        float surface() const override;

        // Destructeur
        virtual ~Rectangle();
};

ostream & operator << (ostream&, const Rectangle &);

// ======== CLASSE CARRE ========
class Carre : public Rectangle {
    public :
        // Constructeurs
        Carre();
        Carre(Point dpRef, float dcote);

        // Accesseur
        float getCote() const;

        // Mutateur
        void setCote(float dcote);

        // Destructeur
        ~Carre();
};

ostream & operator << (ostream&, const Carre &);
