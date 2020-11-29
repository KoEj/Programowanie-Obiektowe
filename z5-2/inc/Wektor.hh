#ifndef WEKTOR_HH
#define WEKTOR_HH

#include <iostream>
#include <cmath>

/*!
 * \file
 * \brief Ten plik powinien zawierać definicję szablonu Wektor<>
 *
 * Ten plik powinien zawierać definicję szablonu Wektor<>.
 * W tym celu należy przerobić definicję klasy Wektor2D.
 */


/*!
 * \brief Krótki opis czego to jest szablon
 *
 *  Tutaj trzeba opisac szablon. Jakie pojecie on modeluje
 *  i jakie ma glowne cechy.
 */
/* szablon Wektor oparta
zawiera funkcje typu:
-liczenie dlugosci wektora
-przeciazenie opratora wektor+wektor
-przeciazenie opratora wektor-wektor
-przeciazenie opratora []
*/
template <int Wymiar>
class Wektor {
    double wspolrzedne[Wymiar];
public:
    Wektor();
    double & operator [] (int i) { return  wspolrzedne[i]; };
    double operator [] (int i) const { return  wspolrzedne[i]; };
    Wektor operator + ( Wektor Lz1 );
    Wektor operator - ( Wektor Lz1 );
    double  dlugosc_wektora ( Wektor <Wymiar> Wek );
};

template <int Wymiar>
Wektor <Wymiar>::Wektor() {
    for ( int i=0; i<Wymiar; i++ )
        wspolrzedne[i] = 0;
  }

template <int Wymiar>
Wektor <Wymiar> Wektor<Wymiar>::operator + ( Wektor<Wymiar> Lz1 ) {
    Wektor <Wymiar> wynik;
        for ( int i=0; i<Wymiar; i++ )
            wynik[i] = wspolrzedne[i] + Lz1[i];
    return wynik;
}

template <int Wymiar>
    Wektor <Wymiar> Wektor <Wymiar>::operator - ( Wektor<Wymiar> Lz1 ) {
        Wektor <Wymiar> wynik;
        for ( int i=0; i<Wymiar; i++ )
            wynik[i] = wspolrzedne[i] - Lz1[i];
    return wynik;
}


/*!
 * \brief Przeciążenie dla wyjścia musi także być szablonem
 *
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt
 */
template <int Wymiar>
inline
std::ostream & operator << (std::ostream &Strm, const Wektor<Wymiar> &Wek) {
    for ( int i=0; i<Wymiar; i++ )
        Strm<<Wek[i]<<" ";
    return Strm;
}


/*!
 * \brief Przeciążenie dla wejścia musi także być szablonem
 *
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt
 */
template <int Wymiar>
inline
std::istream & operator >> (std::istream &Strm, Wektor <Wymiar> &Wek) {
    for ( int i=0; i<Wymiar; i++ )
        Strm>>Wek[i];
    return Strm;
}

#endif
