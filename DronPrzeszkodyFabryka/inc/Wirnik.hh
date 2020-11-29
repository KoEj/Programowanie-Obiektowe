#ifndef WIRNIK_HH
#define WIRNIK_HH

#include <iostream>
#include <iomanip>
#include "Prostopadloscian.hh"
#include "Graniastoslup.hh"

#define ILOSC_WIERZCHOLKOW_ROTORA         6
#define PROMIEN_ROTORA                    8
#define GRUPOSC_ROTORA                    3

/*!
 * \file  Wirnik.hh
 *  
 *  Plik klasy Wirnik
 */


/*!
 * \brief Klasa Wirnik
 * 
 *  Klasa zawiera narzedza niezbedne do dzialania rotorow.
 */
class Wirnik :public Graniastoslup<24> {
  double set=0;

  public:
    Wirnik() : Graniastoslup(){}


      /*!
      * Realizuje przemieszczenie sie rotorow na srodek ukladu wspolrzednych.
      */
      void srodek() {
        for(int r=0; r<4; ++r) {
        int zmiana=360/ILOSC_WIERZCHOLKOW_ROTORA;
        int kat=0;

          for(int i=0; i<24; i=i+3) {
            wspol[i][0]=PROMIEN_ROTORA*cos(kat*M_PI/180);
            wspol[i][1]=PROMIEN_ROTORA*sin(kat*M_PI/180);
            wspol[i][2]=0;

            wspol[i+1][0]=PROMIEN_ROTORA*cos(kat*M_PI/180);
            wspol[i+1][1]=PROMIEN_ROTORA*sin(kat*M_PI/180);
            wspol[i+1][2]=GRUPOSC_ROTORA;

            wspol[i+2][0]=0;
            wspol[i+2][1]=0;
            wspol[i+2][2]=0;
            kat+=zmiana;
          }
        }
      }

      /*!
      * Realizuje rotacje rotorow.
      * Argumenty:
      *    angle - kat o jaki rotory maja sie obrocic.
      */
      void obrot_rotora(double kat) {
        Macierz3x3 macierz_rotacji;
        Wektor3D przesun;
        set+=kat;
        przesun[2]=set;
        macierz_rotacji.zmien_macierz('z', przesun);
        Wektor3D pozycja;
        pozycja = wspol[2];

        (*this).srodek();
        (*this).rotacja(macierz_rotacji);
        (*this).przesuniecie(pozycja);
      }

};

#endif
