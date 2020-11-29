#include "Prostopadloscian.hh"

#define EPS 0.0000000001
/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Prostopadloscian, ktore zawieraja
 *  wiecej kodu niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */
void Prostopadloscian::StworzProstopadloscian(double x_trans = 0,double y_trans = 0,double z_trans = 0) {
    ZapiszCzteryWierzcholki(-PROSTOKAT_X, PROSTOKAT_Y,PROSTOKAT_Z,x_trans,y_trans,z_trans);
    ZapiszCzteryWierzcholki( PROSTOKAT_X, PROSTOKAT_Y,PROSTOKAT_Z,x_trans,y_trans,z_trans);
    ZapiszCzteryWierzcholki( PROSTOKAT_X,-PROSTOKAT_Y,PROSTOKAT_Z,x_trans,y_trans,z_trans);
    ZapiszCzteryWierzcholki(-PROSTOKAT_X,-PROSTOKAT_Y,PROSTOKAT_Z,x_trans,y_trans,z_trans);
    ZapiszCzteryWierzcholki(-PROSTOKAT_X, PROSTOKAT_Y,PROSTOKAT_Z,x_trans,y_trans,z_trans);
}


std::ostream & operator << (std::ostream &Strm, const Prostopadloscian &Pr) {
    for (int i = 1; i <= Pr.get_size(); i++) {
        Strm << Pr[i - 1] << std::endl;
        if (i % 4 == 0)
            Strm << std::endl;
    }
    return Strm;
}

