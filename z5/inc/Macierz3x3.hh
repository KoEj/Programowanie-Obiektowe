#ifndef MACIERZ3X3_HH
#define MACIERZ3X3_HH


#include <iostream>
#include <cmath>
#include "Macierz.hh"
#include "Wektor3D.hh"
/*!
Zadeklarowanie Macierzy 3x3 pod szablon
 * \brief Klasa Macierz3x3 ma być instancją szablonu Macierz<>
 *
 *  Tutaj trzeba opisac instancję szablonu. Jakie pojecie ona modeluje 
 *  i jakie ma glowne cechy.
 */
typedef Macierz<3>  Macierz3x3;
Macierz3x3 obrot_x(Macierz3x3 M);
Macierz3x3 obrot_y(Macierz3x3 M);
Macierz3x3 obrot_z(Macierz3x3 M);

#endif
