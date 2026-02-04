#include "Forme.h"

Forme::Forme(){
    this->pRef = Point();
}

Forme::Forme(Point dpRef){
    this->pRef = dpRef;
}

void Forme::operator+=(Point const&p){pRef+=p;}

Point Forme::getpRef() const {
    return pRef;
}

Forme::~Forme() {}

ostream& operator<<(ostream& s, Forme const& f){
    s << "Forme avec point de reference : " << f.getpRef();
    return s;
}