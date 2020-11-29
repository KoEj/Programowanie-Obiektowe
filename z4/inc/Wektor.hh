#ifndef WEKTOR_HH
#define WEKTOR_HH

#include <iostream>
#include <cmath>
/*!
 * \file
 * \brief Ten plik zawiera definicję szablonu Wektor<>
 */

/*!
  \brief Szablon klasy wektor
    Szablon klasy wektor jest reprezentacja wektoru w przestrzeni n- wymiarowej gdzie n jest reprezenowana
    przez argument szablonu wymiar
  \param wymiar - wartość calkowita przyjmujaca wymiar wektoru
 */
template <int Wymiar>
class Wektor
{
    double wspolrzedne[Wymiar];
public:
    Wektor()
    {
        for (int i=0; i<Wymiar; i++)
            wspolrzedne[i] = 0;

    }
    /*!
       \brief Przeciązenie nawiasów indeksowania
       przez to przeciazenie zostaje zwrocony oryginal elementu wektora
       \param[in] i -przyjmuje ideks elementu
       \return  zwraca wartosc elementu wektora typu double
       */
    double & operator [] (int i)
    {
        return wspolrzedne[i];
    }
    /*!
      \brief Przeciązenie nawiasów indeksowania
      przez to przeciazenie zostaje zwrocona stala wartosc elementu wektora
      \param[in] i -przyjmuje ideks elementu
      \return  zwraca wartosc elementu wektora typu double
      */
    double operator [] (int i) const
    {
        return wspolrzedne[i];
    }
    /*!
    \brief przeciazenie wektor odejmowania

        odejmuje do siebie dwa wektory
      \param arg - wartosc parametru z prawej strony operatora +
      \return wynik - zwraca roznice dwoch wektorow

      */
    Wektor <Wymiar> operator - (Wektor <Wymiar> arg)
    {
        Wektor <Wymiar> wynik;
        for (int i = 0; i < Wymiar; i++)
            wynik[i] = wspolrzedne[i] - arg[i];

        return wynik;
    }
    /*!
    \brief przeciazenie wektor dodawania

      dodaje do siebie dwa wektory
    \param arg - wartosc parametru z prawej strony operatora +
    \return wynik - zwraca sume dwoch wektorow

    */
    Wektor <Wymiar> operator + (Wektor <Wymiar> arg)
    {
        Wektor <Wymiar> wynik;
        for (int i = 0; i < Wymiar; i++)
            wynik[i] = wspolrzedne[i] + arg[i];
        return wynik;
    }
    /*!
    \brief Oblicza długość wektora

    liczy ona długość wektora, czyli odleglosc pomiedzy dwoma punktami w przestrzeni uzywa do tego algorytmu
    z zainicjowanymi funkcjami z biblioteki cmath
    \param arg - jeden z punktow dlugosci miedzy wektorami
    \return suma - zwraca odleglosc pomiedzy dwoma wektorami

    */
    double DlugoscWektora (Wektor <Wymiar> arg)
    {
        double suma = 0;
        for (int i = 0; i < Wymiar; i++)
            suma += pow(wspolrzedne[i] - arg[i], 2);

        return sqrt(suma);
    }
};

/*!
 * \brief Przeciążenie operatora przesuniecia bitowego w prawo
 * sluzy do przekazania strumienia danych na podane wejscie
 *
 * \param[in] Strm - strumień wejscia
 * \param[in] Wek - wektor do wprowadzenia
 * \return strumień wejscia
 */
template <int Wymiar>
inline std::istream & operator >> (std::istream &Strm, Wektor <Wymiar> &Wek)
{
    for (int i = 0; i < Wymiar; i++)
        Strm >> Wek[i];
    return Strm;
}

/*!
 * \brief Przeciążenie operatora przesuniecia bitowego w lewo
 * sluzy do przekazania strumienia danych na podane wyjscie
 *
 * \param[in] Strm - strumień wyjścia
 * \param[in] Wek - wektor do wyświetlenia
 * \return strumień wyjścia
 */
template <int Wymiar>
inline std::ostream & operator<<(std::ostream &Strm, const Wektor <Wymiar> &Wek)
{
    for (int i = 0; i < Wymiar; i++)
        Strm << Wek[i] << " ";
    return Strm;
}

#endif
