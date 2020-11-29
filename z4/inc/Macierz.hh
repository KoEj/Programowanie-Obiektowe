#ifndef MACIERZ_HH
#define MACIERZ_HH

#include <iostream>
#include <cmath>
#include "Wektor.hh"

/*!
 * \file
 * \brief Ten plik zawiera definicję szablonu Macierz<>
 */

/*!
  \brief Szablon klasy macierz
    Szablon klasy macierz jest reprezentacja macierzy w przestrzeni n- wymiarowej gdzie n jest reprezenowana
    przez argument szablonu wymiar
  \param wymiar - wartość calkowita przyjmujaca wymiar macierzy
 */
template <int Wymiar>
class Macierz {
    Wektor <Wymiar> _Macierz[Wymiar];
    double kat;

public:
    /*!
    \brief Funkcja przyjmujaca wartosc kata
      funkcja służąca do zmiany wartosci kąta oraz przeliczania go na radiany, funkcja pobiera
      kąt, poczym przelicza go na radiany
    \param kat - parametr przyjmujacy wartosc kata w stopniach
    */
    void set_kat(double kat) {
        this->kat = kat * M_PI / 180;
    }

    double get_kat() {
        return kat;
    }
    /*!
    \brief Przeciązenie nawiasów funkcyjnych
    przez to przeciazenie zostaje zwrocony oryginal elementu macierzy
    \param[in] i - przyjmuje nr wiersza
    \param[in] j - przyjmuje nr kolumny
    \return  zwraca wartosc elementu macierzy typu double
    */

    double & operator () (int i, int j) {
        return _Macierz[i][j];
    }
    /*!
    \brief Przeciązenie nawiasów funkcyjnych
    przez to przeciazenie zostaje zwrocona stala wartosc macierzy
    \param[in] i - przyjmuje nr wiersza
    \param[in] j - przyjmuje nr kolumny
    \return  zwraca wartosc elementu macierzy typu double
    */
    double operator () (int i, int j) const {
        return _Macierz[i][j];
    }
    /*!
    \brief Przeciązenie operatora mnozenia
    służy do mnożenia macierzy
    \param[in] arg - przyjmuje wektor do przemnozenia przez macierz
    \return zwraca wektor
    */
    Wektor <Wymiar> operator * (Wektor<Wymiar> arg) {
        Wektor<Wymiar> wynik;
        for (int i = 0; i < Wymiar; i++)
            for (int j = 0; j < Wymiar; j++)
                wynik[i] += _Macierz[i][j] * arg[j];
        return wynik;
    }
};

/*!
 * \file
 * \brief Przeciążenie operatora przesuniecia bitowego w lewo
 * sluzy do przekazania strumienia danych na podane wyjscie
 *
 * \param[in] Strm - strumień wyjścia
 * \param[in] Mac - macierz do wyświetlenia
 * \return strumień wyjścia
 */
template <int Wymiar>
inline std::ostream & operator << (std::ostream &Strm, const Macierz <Wymiar> &Mac) {
    for (int i = 0; i < Wymiar; i++) {
        for (int j = 0; j < Wymiar; j++)
            Strm << Mac(i, j) << " ";
        Strm << std::endl;
    }
    return Strm;
}

#endif
