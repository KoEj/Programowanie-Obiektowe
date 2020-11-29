#include "Macierz3x3.hh"

/*!
 * \file
 * \brief Plik Macierz3x3
 * Wylicza macierz obrotu rotacji dla nastepujacych osi x,y i z
 */

 /*!
  * \brief Macierz rotacji dla osi x
  */
void Wylicz_macierz_x(Macierz3x3 &Mac)
{
    Mac(0, 0) = 1;
    Mac(0, 1) = Mac(0, 2) = Mac(1, 0) =Mac(2, 0) =0;
    Mac(1, 1) = cos(Mac.get_kat());
    Mac(1, 2) = -sin(Mac.get_kat());
    Mac(2, 1) = sin(Mac.get_kat());
    Mac(2, 2) = cos(Mac.get_kat());
}
/*!
 * \brief Macierz rotacji dla osi y
 */
void Wylicz_macierz_y(Macierz3x3 &Mac)
{

    Mac(0, 0) = cos(Mac.get_kat());
    Mac(0, 2) = sin(Mac.get_kat());
    Mac(2, 0) = -sin(Mac.get_kat());
    Mac(2, 2) = cos(Mac.get_kat());
    Mac(0, 1) =  Mac(1, 0) = Mac(1, 2) = Mac(2, 1) = 0;
    Mac(1, 1) = 1;
}
/*!
 * \brief Macierz rotacji dla osi z
 */
void Wylicz_macierz_z(Macierz3x3 &Mac)
{
    Mac(0, 0) = cos(Mac.get_kat());
    Mac(0, 1) = -sin(Mac.get_kat());
    Mac(1, 0) = sin(Mac.get_kat());
    Mac(1, 1) = cos(Mac.get_kat());
    Mac(0, 2) = Mac(1, 2) =  Mac(2, 0) = Mac(2, 1) =   0;
    Mac(2, 2) = 1;
}

