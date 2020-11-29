#ifndef MACIERZ3X3_HH
#define MACIERZ3X3_HH


#include <iostream>

#include "Macierz.hh"

/*!
 * \file
 * \brief Klasa Macierz3x3 jest instancją szablonu Macierz<3>
 *  modeluje ona macierz o rozmiarze 3 co powoduje wygenerowanie na podstawie szablonu
 *  klasy o wymiarze wiersz/kolumna o rozmiarze 3
 *
 */
typedef Macierz<3>  Macierz3x3;
/*!
 * \brief Funkcja Wylicz_macierz_x sluzy do okreslenia wartosci macierzy funkcji trygonometrycznej dla obrotu wokol
 * osi x
 *
 * \param[in] Mac - oryginalna macierz sluzaca do przechowywania wartosci obrotu
 */
void Wylicz_macierz_x(Macierz3x3 &Mac);

/*!
 * \brief Funkcja Wylicz_macierz_y sluzy do okreslenia wartosci macierzy funkcji trygonometrycznej dla obrotu wokol
 * osi y
 *
 * \param[in] Mac - oryginalna macierz sluzaca do przechowywania wartosci obrotu
 */
void Wylicz_macierz_y(Macierz3x3 &Mac);

/*!
 * \brief Funkcja Wylicz_macierz_z sluzy do okreslenia wartosci macierzy funkcji trygonometrycznej dla obrotu wokol
 * osi z
 *
 * \param[in] Mac - oryginalna macierz sluzaca do przechowywania wartosci obrotu
 */
void Wylicz_macierz_z(Macierz3x3 &Mac);
#endif
