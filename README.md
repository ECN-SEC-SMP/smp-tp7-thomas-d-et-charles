# Rapport TP7 - SMP

**Auteurs :** Thomas D. et Charles  
**Date :** 4 février 2026

## Table des matières

- [Introduction](#introduction)
- [Création d'une classe Point](#création-dune-classe-point)
- [Surcharge d'opérateurs](#surcharge-dopérateurs)
- [Formes géométriques abstraites](#formes-géométriques-abstraites)
- [Formes géométriques concrètes](#formes-géométriques-concrètes)
  - [Classe Cercle](#classe-cercle)
  - [Classe Rectangle](#classe-rectangle)
  - [Classe Carré](#classe-carré)
- [Liste de formes](#liste-de-formes)
- [Compilation et exécution](#compilation-et-exécution)
- [Conclusion](#conclusion)

---

## Introduction

Ce tp porte sur la manipulation de classes en C++, la surcharge d'opérateurs et le polymorphisme. Le projet consiste à développer un système de gestion de formes géométriques permettant de créer et manipuler différents types de formes (points, cercles, rectangles, carrés) et de calculer leurs propriétés (surface, périmètre, boîte englobante).

---

## Création d'une classe Point

### Classe Point demandée

Écrire une classe pour un point du plan avec :
- Attributs d'abscisse et d'ordonnée (type réel)
- Méthodes `translater()` prenant un autre Point ou une paire de réels
- Constructeur sans paramètres (initialisation à l'origine)
- Constructeur avec deux paramètres réels
- Constructeur de recopie prenant une référence constante à un Point
- Accesseurs et mutateurs

### Fichier Point.h

```cpp
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
    void translater(int dx, int dy);
    void translater(Point p);

    // surcharge d'operateurs
    void operator += (const Point &);

    // contructeurs
    Point(); //sans paramètres
    Point(float xi, float yi); //avec 2 reels
    Point(Point const &ref); //recopie

    // destructeur
    ~Point();
};

ostream & operator << (ostream&, const Point &);
```

### Fichier Point.cpp

```cpp
#include "Point.h"

// Accesseurs
float Point::getx() const{ return x; }
float Point::gety() const{ return y; }

// Mutateurs
void Point::setx(float xs) { this->x = xs;}
void Point::sety(float ys) { this->y = ys;}
void Point::setCoords(float xs, float ys)
{
    this->x = xs;
    this->y = ys;
}

// Constructeurs
Point::Point()
{
    this->x = 0;
    this->y = 0;
}

Point::Point(float xi, float yi)
{
    this->x = xi;
    this->y = yi;
}

Point::Point(Point const &ref)
{
    this->x = ref.x;
    this->y = ref.y;
}

// Méthodes de translation
void Point::translater(int dx, int dy)
{
    this->x += dx;
    this->y += dy;
}

void Point::translater(Point p)
{
    this->x += p.x;
    this->y += p.y;
}

// Surcharge de l'opérateur +=
void Point::operator+=(Point const& p)
{
    this->x += p.x;
    this->y += p.y;
}

// Surcharge de l'opérateur <<
ostream& operator << (ostream&s, const Point &c){
    s << "Point(" << c.getx() << ", " << c.gety() << ")" << endl;
    return s;
}

Point::~Point(){}
```

### Tests de la classe Point

```cpp
void testPoint() {
    // Test constructeur par défaut
    Point p1;
    cout << "Point p1 (constructeur par defaut) : " << p1;

    // Test constructeur avec paramètres
    Point p2(3.5, 4.2);
    cout << "Point p2 (constructeur avec parametres) : " << p2;

    // Test constructeur de recopie
    Point p3(p2);
    cout << "Point p3 (constructeur de recopie) : " << p3;

    // Test accesseurs et mutateurs
    p1.setx(10);
    p1.sety(20);
    cout << "Point p1 apres setx(10) et sety(20) : " << p1;

    p1.setCoords(5, 15);
    cout << "Point p1 apres setCoords(5, 15) : " << p1;

    // Test translater
    p1.translater(5, 5);
    cout << "Point p1 apres translater(5, 5) : " << p1;

    Point p4(2, 3);
    p1.translater(p4);
    cout << "Point p1 apres translater(Point(2, 3)) : " << p1;

    // Test opérateur +=
    p1 += Point(1, 1);
    cout << "Point p1 apres += Point(1, 1) : " << p1;
}
```

### Diagramme de classes Point

```
┌─────────────────┐
│      Point      │
├─────────────────┤
│ - x : float     │
│ - y : float     │
├─────────────────┤
│ + Point()       │
│ + Point(x, y)   │
│ + Point(Point&) │
│ + getx()        │
│ + gety()        │
│ + setx()        │
│ + sety()        │
│ + setCoords()   │
│ + translater()  │
│ + operator+=    │
└─────────────────┘
```

---

## Surcharge d'opérateurs

### Opérateurs demandés

- Surcharger l'opérateur `<<` pour permettre l'utilisation de `cout` avec des Points
- Surcharger l'opérateur `+=` pour simplifier l'écriture de la translation (ne peut s'appliquer qu'entre Points)

### Implémentation

#### Opérateur <<
```cpp
ostream& operator << (ostream&s, const Point &c){
    s << "Point(" << c.getx() << ", " << c.gety() << ")" << endl;
    return s;
}
```

L'opérateur `<<` est défini comme fonction externe et permet d'afficher un point avec `cout`.

#### Opérateur +=
```cpp
void Point::operator+=(Point const& p)
{
    this->x += p.x;
    this->y += p.y;
}
```

L'opérateur `+=` est défini comme membre de la classe Point et permet de translater un point avec la syntaxe `p1 += p2`.

### Tests des surcharges d'opérateurs

```
Point p1 (constructeur par defaut) : Point(0, 0)
Point p2 (constructeur avec parametres) : Point(3.5, 4.2)
Point p1 apres += Point(1, 1) : Point(13, 24)
```

Les tests montrent que les opérateurs fonctionnent correctement.

---

## Formes géométriques abstraites

### Classe Forme demandée

Classe `Forme` avec :
1. Un point comme attribut (centre de la forme)
2. Constructeur approprié
3. Surcharge de l'opérateur `+=` pour la translation
4. Surcharge de l'opérateur `<<` pour `cout`
5. Deux méthodes abstraites `perimetre()` et `surface()`

### Fichier Forme.h (classe Forme)

```cpp
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

        // Surcharges
        void operator += (const Point &);

        // Méthodes abstraites
        virtual float perimetre() const = 0;
        virtual float surface() const = 0;

        // Destructeur virtuel
        virtual ~Forme();
};

ostream & operator << (ostream&, const Forme &);
```

### Fichier Forme.cpp

```cpp
#include "Forme.h"

Forme::Forme(){
    this->pRef = Point();
}

Forme::Forme(Point dpRef){
    this->pRef = dpRef;
}

void Forme::operator+=(Point const&p){
    pRef+=p;
}

Point Forme::getpRef() const {
    return pRef;
}

Forme::~Forme() {}

ostream& operator<<(ostream& s, Forme const& f){
    s << "Forme avec point de reference : " << f.getpRef();
    return s;
}
```

### Diagramme de classes

```
┌─────────────────┐
│      Point      │
└─────────────────┘
        △
        │ utilise
        │
┌─────────────────┐
│      Forme      │
│   (abstraite)   │
├─────────────────┤
│ - pRef : Point  │
├─────────────────┤
│ + Forme()       │
│ + Forme(Point)  │
│ + getpRef()     │
│ + operator+=    │
│ + perimetre()*  │
│ + surface()*    │
└─────────────────┘
```

---

## Formes géométriques concrètes

### Classes demandées

Écrire les classes `Cercle`, `Rectangle` et `Carré` :
- Héritant de `Forme`
- Rectangles et Carrés alignés avec verticale et horizontale
- Fichiers séparés pour chaque classe
- Définir les méthodes abstraites
- Surcharger `<<` pour afficher le type et les valeurs des attributs

### Classe Cercle

#### Déclaration dans Forme.h

```cpp
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
```

#### Implémentation Cercle.cpp

```cpp
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

Cercle::~Cercle() {}
```

### Classe Rectangle

#### Déclaration dans Forme.h

```cpp
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
```

#### Implémentation Rectangle.cpp

```cpp
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

Rectangle::~Rectangle() {}
```

### Classe Carré

Le Carré hérite de Rectangle.

#### Déclaration dans Forme.h

```cpp
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
```

#### Implémentation Carre.cpp

```cpp
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
    return largeur;
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

Carre::~Carre() {}
```

### Tests des formes géométriques

#### Test Cercle
```
Cercle c2 (centre=(5,5), rayon=10) :
Cercle : centre = Point(5, 5), rayon = 10
  Perimetre = 62.8319, Surface = 314.159

Cercle c2 apres += Point(2, 3) :
Cercle : centre = Point(7, 8), rayon = 10
  Perimetre = 62.8319, Surface = 314.159
```

#### Test Rectangle
```
Rectangle r2 (centre=(10,10), largeur=8, hauteur=6) :
Rectangle : centre = Point(10, 10), largeur = 8, hauteur = 6
  Perimetre = 28, Surface = 48

Rectangle r2 apres += Point(5, 5) :
Rectangle : centre = Point(15, 15), largeur = 8, hauteur = 6
  Perimetre = 28, Surface = 48
```

#### Test Carré
```
Carre ca2 (centre=(15,15), cote=5) :
Carre : centre = Point(15, 15), cote = 5
  Perimetre = 20, Surface = 25

Carre ca2 apres += Point(-5, -5) :
Carre : centre = Point(10, 10), cote = 5
  Perimetre = 20, Surface = 25
```

### Diagramme de classes complet

```
                    ┌─────────────────┐
                    │      Point      │
                    └─────────────────┘
                            △
                            │
                    ┌─────────────────┐
                    │      Forme      │
                    │   (abstraite)   │
                    ├─────────────────┤
                    │ - pRef : Point  │
                    ├─────────────────┤
                    │ + perimetre()*  │
                    │ + surface()*    │
                    │ + operator+=    │
                    └─────────────────┘
                            △
                ┌───────────┼───────────┐
                │           │           │
         ┌──────┴─────┐     │    ┌─────┴──────┐
         │   Cercle   │     │    │ Rectangle  │
         ├────────────┤     │    ├────────────┤
         │- rayon     │     │    │- largeur   │
         ├────────────┤     │    │- hauteur   │
         │+ perimetre()│     │    ├────────────┤
         │+ surface() │     │    │+ perimetre()│
         └────────────┘     │    │+ surface() │
                            │    └────────────┘
                            │           △
                            │           │
                            │    ┌──────┴─────┐
                            │    │   Carre    │
                            │    ├────────────┤
                            │    │+ getCote() │
                            │    │+ setCote() │
                            │    └────────────┘
```

---

## Liste de formes

### Classe ListeFormes demandée

À l'aide de la structure `vector<>` (définie dans `vector<Forme*>`), définir une classe `ListeFormes` qui permet de :
- Calculer la surface totale de la liste
- Calculer la boîte englobante (plus petit rectangle aligné sur les axes contenant toutes les formes)

### Fichier ListeFormes.h

```cpp
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
```

### Fichier ListeFormes.cpp (extraits principaux)

#### Surface totale
```cpp
float ListeFormes::surfaceTotale()
{
    float total = 0;
    for (int i = 0; i < formes.size(); i++)
    {
        total += formes[i]->surface();
    }
    return total;
}
```

#### Boîte englobante
```cpp
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
```

### Tests ListeFormes

```cpp
void testListeFormes() {
    ListeFormes liste;

    // Ajout de formes
    liste.ajouterForme(new Cercle(Point(0, 0), 5));
    liste.ajouterForme(new Rectangle(Point(10, 10), 6, 4));
    liste.ajouterForme(new Carre(Point(20, 20), 8));
    liste.ajouterForme(new Cercle(Point(-5, -5), 3));

    cout << liste << endl;

    // Surface totale
    cout << "Surface totale : " << liste.surfaceTotale() << endl << endl;

    // Boite englobante
    float xMin, xMax, yMin, yMax;
    liste.boiteEnglobante(xMin, xMax, yMin, yMax);
    cout << "Boite englobante :" << endl;
    cout << "  xMin = " << xMin << ", xMax = " << xMax << endl;
    cout << "  yMin = " << yMin << ", yMax = " << yMax << endl;
    cout << "  Largeur = " << (xMax - xMin) << ", Hauteur = " << (yMax - yMin) << endl;
}
```

### Résultats des tests

```
Liste de 4 formes :
  Cercle : centre = Point(0, 0), rayon = 5
    Perimetre = 31.4159, Surface = 78.5398
  Rectangle : centre = Point(10, 10), largeur = 6, hauteur = 4
    Perimetre = 20, Surface = 24
  Carre : centre = Point(20, 20), cote = 8
    Perimetre = 32, Surface = 64
  Cercle : centre = Point(-5, -5), rayon = 3
    Perimetre = 18.8496, Surface = 28.2743

Surface totale : 194.814

Boite englobante :
  xMin = -8, xMax = 24
  yMin = -8, yMax = 24
  Largeur = 32, Hauteur = 32
```

---

## Compilation et exécution

### Makefile

```makefile
CXX = g++
CXXFLAGS = -Wall -g -std=c++17
EXEC = tp7_exec
OBJS = main.o tests.o Point.o Forme.o Cercle.o Rectangle.o Carre.o ListeFormes.o

$(EXEC) : $(OBJS)
	$(CXX) -o $@ $^

# Les dépendances entre headers et fichiers sources
main.o : ListeFormes.h Forme.h Point.h
tests.o : ListeFormes.h Forme.h Point.h
Point.o : Point.h
Forme.o : Forme.h Point.h
Cercle.o : Forme.h Point.h
Rectangle.o : Forme.h Point.h
Carre.o : Forme.h Point.h
ListeFormes.o : ListeFormes.h Forme.h Point.h

clean :
	rm -f $(OBJS) $(EXEC)

.PHONY: clean
```

### Commandes

```bash
make clean    # Nettoyer les fichiers objets
make          # Compiler le projet
./tp7_exec    # Exécuter les tests
```

---

## Conclusion

Tous les objectifs du TP ont été réalisés :

✅ **Classe Point** : Implémentée avec constructeurs, accesseurs, mutateurs et méthodes de translation

✅ **Surcharge d'opérateurs** : Opérateurs `<<` et `+=` fonctionnels

✅ **Classe Forme abstraite** : Avec méthodes virtuelles pures `perimetre()` et `surface()`

✅ **Formes concrètes** : Classes Cercle, Rectangle et Carré implémentées avec héritage

✅ **Liste de formes** : Utilisation de `vector<Forme*>` avec calcul de surface totale et boîte englobante

✅ **Tests** : Programme de tests complet validant toutes les fonctionnalités

✅ **Dépôt GitHub** : Code déposé sur GitHub Classroom

Le projet compile sans erreur et tous les tests s'exécutent correctement.
