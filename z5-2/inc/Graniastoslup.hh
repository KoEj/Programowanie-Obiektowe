#ifndef GRANIASTOSLUP_HH
#define GRANIASTOSLUP_HH

#include <iostream>
#include "Wektor3D.hh"
#include "Bryla.hh"
using namespace std;


/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
/* szablon Prostopadloscian oparta na szablonie Wektor
zawiera funkcje typu:
-porownaj boki
-buduj prostopadloscian za pomoca wektora i dlugosci bokow
-przeciazenie opratora [] oraz ()
*/

class Graniastoslup: public Bryla {
public:
    void StworzGraniastoslup( double Kat_st, double x_trans, double y_trans, double z_trans);
    void obrot( double Kat_st, double x_trans, double y_trans, double z_trans, double Z);
    Graniastoslup() {}
    Graniastoslup( int roz ) {
        wiersz.resize(roz);
    }
};

std::ostream & operator << ( std::ostream &Strm, const Graniastoslup &Gr );


#endif

