#include "Macierz2x2.hh"
#include <cmath>
#define PI 3.141592653589793238462643383279502884197
//https://www.piday.org/million/

//konstruktor
Macierz2x2::Macierz2x2(float kat) {
    float rad=((kat*PI)/180.0);         //rad - kat w radianach
    this->_Tab[0][0]=cos(rad);
    this->_Tab[0][1]=sin(-rad);
    this->_Tab[1][0]=sin(rad);
    this->_Tab[1][1]=cos(rad);
}

std::ostream & operator << (std::ostream &StrmWyj, const Macierz2x2 &Macierz) {
    StrmWyj << Macierz(0,0) << Macierz(0,1) << Macierz(1,0) << Macierz(1,1);
    return StrmWyj;
}
