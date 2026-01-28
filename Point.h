
class Point
{
private:
    float x; //abcisse
    float y; //ordonnée
public:
    // accesseurs
    float getx();
    float gety();
    // mutateurs
    void setx(float xs);
    void sety(float ys);
    void setCoords(float xs, float ys);
    // methodes
    // -- translater
    translater();
    type? translater(float x, float y); //avec 2 reels
    // contructeurs
    Point(); //sans paramètres
    Point(float xi, float yi); //avec 2 reels
    Point(Point const &ref); //

    // destructeur
    ~Point();
};


