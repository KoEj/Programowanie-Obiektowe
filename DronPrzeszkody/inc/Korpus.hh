#ifndef KORPUS_HH
#define KORPUS_HH

#include <iostream>
#include <iomanip>
#include "Prostopadloscian.hh"
#include "Wektor3D.hh"

#define DLUGOSC_PODSTAWY                  20
#define SZEROKOSC_PODSTAWY                24
#define WYSOKOSC_PODSTAWY                 20

/*!
 * \file  Korpus.hh
 *  
 *  Plik klasy Korpus
 */


/*!
 * \brief Klasa korpusu
 * 
 *  Klasa zawiera narzedza niezbedne do dzialania korpusu.
 *  Klasa Body dziedziczy publicznie od klasy Cuboid.
 */
class Korpus :public Prostopadloscian {
  double szerekosc, wysokosc, dlugosc;

  public:
      Korpus() {
        reset();
      }

    /*!
     * Realizuje przemieszczenie sie ciala drona do punktu startu .
     */
    void reset() {
      wspol[0][0]=-DLUGOSC_PODSTAWY/2;
      wspol[0][1]=-SZEROKOSC_PODSTAWY/2;
      wspol[0][2]=-WYSOKOSC_PODSTAWY/2;

      wspol[1][0]=DLUGOSC_PODSTAWY/2;
      wspol[1][1]=-SZEROKOSC_PODSTAWY/2;
      wspol[1][2]=-WYSOKOSC_PODSTAWY/2;

      wspol[2][0]=-DLUGOSC_PODSTAWY/2;
      wspol[2][1]=SZEROKOSC_PODSTAWY/2;
      wspol[2][2]=-WYSOKOSC_PODSTAWY/2;

      wspol[3][0]=DLUGOSC_PODSTAWY/2;
      wspol[3][1]=SZEROKOSC_PODSTAWY/2;
      wspol[3][2]=-WYSOKOSC_PODSTAWY/2;


      wspol[4][0]=-DLUGOSC_PODSTAWY/2;
      wspol[4][1]=SZEROKOSC_PODSTAWY/2;
      wspol[4][2]=WYSOKOSC_PODSTAWY/2;

      wspol[5][0]=DLUGOSC_PODSTAWY/2;
      wspol[5][1]=SZEROKOSC_PODSTAWY/2;
      wspol[5][2]=WYSOKOSC_PODSTAWY/2;

      wspol[6][0]=-DLUGOSC_PODSTAWY/2;
      wspol[6][1]=-SZEROKOSC_PODSTAWY/2;
      wspol[6][2]=WYSOKOSC_PODSTAWY/2;
      
      wspol[7][0]=DLUGOSC_PODSTAWY/2;
      wspol[7][1]=-SZEROKOSC_PODSTAWY/2;
      wspol[7][2]=WYSOKOSC_PODSTAWY/2;
    }

    Wektor3D srodek() {
      Wektor3D Wynik;
      Wynik[0]=wspol[0][0]+DLUGOSC_PODSTAWY/2;
      Wynik[1]=wspol[0][1]+SZEROKOSC_PODSTAWY/2;
      Wynik[2]=wspol[0][2]+WYSOKOSC_PODSTAWY/2;
      return Wynik;
    }

};

#endif
