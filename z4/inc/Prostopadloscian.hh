#ifndef PROSTOKAT_HH
#define PROSTOKAT_HH

#include <iostream>
#include <fstream>
#include "Wektor3D.hh"
#include "Macierz3x3.hh"
#define EPS 0.00000000000001

using namespace std;
/*!
 * \file
 * \brief Ten plik zawiera definicję Klasy
 */

/*!
  \brief Klasa prostopadloscian
   Klasa prostopadloscian jest reprezentacja prostopadloscianu w przestrzeni 3D
 */
class Prostopadloscian
{
  Wektor3D wierzcholki[8];

public:
/*!
       \brief Przeciązenie nawiasów indeksowania
       przez to przeciazenie zostaje zwrocony oryginal elementu prostopadloscianu
       \param[in] i -przyjmuje ideks elementu
       \return  zwraca wartosc elementu prostopadloscianu typu wektor 3D
       */
  Wektor3D & operator [] (int i);
/*!
       \brief Przeciązenie nawiasów indeksowania
       przez to przeciazenie zostaje zwrocona wartosc stala elementu prostopadloscianu
       \param[in] i -przyjmuje ideks elementu
       \return  zwraca wartosc elementu prostopadloscianu typu wektor 3D
       */
  Wektor3D operator [] (int i) const;
  /*!
  \brief Obliczanie punktow wierzcholkow
  Sluzy do obliczania kazdego punktu prostopadłościanu
  \param[in] wierz1 - wspolrzedne pierwszego wierzcholka
  \param[in]  bok1, bok2, bok3 - dlugosci bokow
 */
  void wartosci_wierzcholkow(Wektor3D wierz1, double bok1, double bok2, double bok3);
  /*!
  \brief Porównanie boków
  służy do porównywania boków
 */
  void porownaj_boki();
};
/*!
 * \brief Przeciążenie operatora przesuniecia bitowego w lewo
 * sluzy do przekazania strumienia danych na podane wyjscie
 *
 * \param[in] Strm - strumień wyjścia
 * \param[in] Pr - prostopadloscian do wyświetlenia
 * \return strumień wyjścia
 */
std::ostream &operator<<(std::ostream &Strm, const Prostopadloscian &Pr);

/*!
 * Zapis wspolrzednych zbioru punktow do strumienia wyjściowego.
 * Dane sa odpowiednio sformatowane, tzn. przyjęto notację stałoprzecinkową
 * z dokładnością do 10 miejsca po przecinku. Szerokość wyświetlanego pola
 * to 16 miejsc, sposób wyrównywania - do prawej strony.
 * \param[in] StrmWy - strumien wyjsciowy, do ktorego maja zostac zapisane
 *                     kolejne wspolrzedne.
 * \param[in] Przesuniecie - ten parameter jest aby przekazac macierz obrotu
 * \param[in] Prostopadloscian - ten parameter przekazuje oryginal obiektu bryly
 */

void ZapisDoStrumienia(ostream &StrmWy, Macierz3x3 Przesuniecie, Prostopadloscian &Pr);
/*!
 * Zapis wspolrzednych zbioru punktow do strumienia wyjściowego.
 * Dane sa odpowiednio sformatowane, tzn. przyjęto notację stałoprzecinkową
 * z dokładnością do 10 miejsca po przecinku. Szerokość wyświetlanego pola
 * to 16 miejsc, sposób wyrównywania - do prawej strony.
 * \param[in] StrmWy - strumien wyjsciowy, do ktorego maja zostac zapisane
 *                     kolejne wspolrzedne.
 * \param[in] Przesuniecie - ten parameter jest aby przekazac wektor przesuniecia
 * \param[in] Prostopadloscian - ten parameter przekazuje oryginal obiektu bryly
 */

void ZapisDoStrumienia(ostream &StrmWy, Wektor3D Przesuniecie, Prostopadloscian &Pr);

/*!
 * Zapis wspolrzednych zbioru punktow do pliku, z ktorego
 * dane odczyta program gnuplot i narysuje je w swoim oknie graficznym.
 * \param[in] sNazwaPliku - nazwa pliku, do którego zostana zapisane
 *                          wspolrzędne punktów.
 * \param[in] Przesuniecie - ten parameter jest aby przekazac macierz obrotu
 * \param[in] Prostopadloscian - ten parameter przekazuje oryginal obiektu bryly
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */

bool ZapisWspolrzednychDoPliku(const char *sNazwaPliku, Macierz3x3 Przesuniecie, Prostopadloscian &Pr);
/*!
 * Zapis wspolrzednych zbioru punktow do pliku, z ktorego
 * dane odczyta program gnuplot i narysuje je w swoim oknie graficznym.
 * \param[in] sNazwaPliku - nazwa pliku, do którego zostana zapisane
 *                          wspolrzędne punktów.
 * \param[in] Przesuniecie - ten parameter jest aby przekazac wektor przesuniecia
 * \param[in] Prostopadloscian - ten parameter przekazuje oryginal obiektu bryly
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
bool ZapisWspolrzednychDoPliku(const char *sNazwaPliku, Wektor3D Przesuniecie, Prostopadloscian &Pr);
#endif
