#include "ListeFormes.h"
#include <iostream>

using namespace std;

void testPoint() {
    cout << "========== TEST DE LA CLASSE POINT ==========" << endl;

    // Test constructeurs
    Point p1;
    Point p2(3.5, 4.2);
    Point p3(p2);

    cout << "Point p1 (constructeur par defaut) : " << p1;
    cout << "Point p2 (constructeur avec parametres) : " << p2;
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

    // Test operateur +=
    p1 += Point(1, 1);
    cout << "Point p1 apres += Point(1, 1) : " << p1;
}

void testCercle() {
    cout << endl << "========== TEST DE LA CLASSE CERCLE ==========" << endl;

    Cercle c1;
    cout << "Cercle c1 (constructeur par defaut) :" << endl << c1 << endl;

    Cercle c2(Point(5, 5), 10);
    cout << "Cercle c2 (centre=(5,5), rayon=10) :" << endl << c2 << endl;

    // Test translation
    c2 += Point(2, 3);
    cout << "Cercle c2 apres += Point(2, 3) :" << endl << c2 << endl;
}

void testRectangle() {
    cout << endl << "========== TEST DE LA CLASSE RECTANGLE ==========" << endl;

    Rectangle r1;
    cout << "Rectangle r1 (constructeur par defaut) :" << endl << r1 << endl;

    Rectangle r2(Point(10, 10), 8, 6);
    cout << "Rectangle r2 (centre=(10,10), largeur=8, hauteur=6) :" << endl << r2 << endl;

    // Test translation
    r2 += Point(5, 5);
    cout << "Rectangle r2 apres += Point(5, 5) :" << endl << r2 << endl;
}

void testCarre() {
    cout << endl << "========== TEST DE LA CLASSE CARRE ==========" << endl;

    Carre ca1;
    cout << "Carre ca1 (constructeur par defaut) :" << endl << ca1 << endl;

    Carre ca2(Point(15, 15), 5);
    cout << "Carre ca2 (centre=(15,15), cote=5) :" << endl << ca2 << endl;

    // Test translation
    ca2 += Point(-5, -5);
    cout << "Carre ca2 apres += Point(-5, -5) :" << endl << ca2 << endl;
}

void testListeFormes() {
    cout << endl << "========== TEST DE LA CLASSE LISTEFORMES ==========" << endl;

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

void runAllTests() {
    testPoint();
    testCercle();
    testRectangle();
    testCarre();
    testListeFormes();
}
