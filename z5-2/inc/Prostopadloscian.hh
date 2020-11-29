#ifndef PROSTOKAT_HH
#define PROSTOKAT_HH

#include <iostream>
#include "Wektor3D.hh"
#include "Bryla.hh"
#include "Macierz3x3.hh"
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

class Prostopadloscian: public Bryla {
public:
    void StworzProstopadloscian( double x_trans,double y_trans,double z_trans );
    Prostopadloscian() {}
    Prostopadloscian( int roz ) {
        wiersz.resize(roz);
    }

    double get_Z(){return  wiersz[0][2];}
    Prostopadloscian operator * (Macierz3x3 M) {
        Prostopadloscian pr( (int)wiersz.size() );
        for(int i=0; i<(int)wiersz.size(); i++) {
            pr[i] = M * wiersz[i];
        }
        return pr;
    }
};

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt
 */
std::ostream& operator << ( std::ostream &Strm, const Prostopadloscian &Pr);


#endif
