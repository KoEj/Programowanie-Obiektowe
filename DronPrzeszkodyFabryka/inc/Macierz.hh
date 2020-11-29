#ifndef MACIERZ_HH
#define MACIERZ_HH

#include <iostream>
#include <math.h>

#include "Wektor.hh"

/*!
 * \file  Macierz.hh
 *  
 *  Plik klasy Macierz
 */


/*!
 * \brief  Szablon macierzy
 *
 *  Szablon do tworzenia i operowania na macierzach kwadratowych dowolnej wielkosci
 */
template <int wymiar>
class Macierz {
    double Tab[wymiar][wymiar] = {0};
  public:

    /*!
    * Realizuje przeciazenie nawiasow okraglych.
    * Argumenty:
    *    Ind - indeks,
    *    Ind - indeks2,
    *    Ind - indeks3.
    */
    double  operator () (int Ind, int Ind1) const { return Tab[Ind][Ind1]; }

    /*!
    * Realizuje przeciazenie nawiasow okraglych.
    * Argumenty:
    *    Ind - indeks,
    *    Ind - indeks2,
    *    Ind - indeks3.
    */
    double& operator () (int Ind, int Ind1)  { return Tab[Ind][Ind1]; }

    /*!
   * Realizuje mnozenie macierzy przez wektor.
   * Argumenty:
   *    wektor - wektor przez ktory mnozymy.
   * Zwraca:
   *    Wektor wynikowy.
   */
    Wektor<wymiar>  operator * (const Wektor<wymiar> &  wektor) const {
        Wektor<wymiar> wynik;


    //   for(int j=0; j<wymiar; ++j) {
    //     for(int i=0; i<wymiar; ++i) {
    //       Wynik[j]+=Tab[j][i]*wektor[i];
    //     }
    //   }
    //   return Wynik;
    // }

      if(wymiar==3) {

        wynik[0]= (Tab[0][0]*wektor[0])+(Tab[0][1]*wektor[1])+(Tab[0][2]*wektor[2]);
        wynik[1]= (Tab[1][0]*wektor[0])+(Tab[1][1]*wektor[1])+(Tab[1][2]*wektor[2]);
        wynik[2]= (Tab[2][0]*wektor[0])+(Tab[2][1]*wektor[1])+(Tab[2][2]*wektor[2]);
        return wynik;
      }

      if(wymiar==2) {

        wynik[0]= (Tab[0][0]*wektor[0])+(Tab[0][1]*wektor[1]);
        wynik[1]= (Tab[1][0]*wektor[0])+(Tab[1][1]*wektor[1]);
        return wynik;
      }
    }

    /*!
   * Realizuje mnozenie macierzy przez skalar.
   * Argumenty:
   *    D - skalar przez ktory mnozym.
   * Zwraca:
   *    Macierz wynikowa.
   */
    Macierz operator * (double D) const {
      Macierz <wymiar> Bufor;
      Bufor = *this;
      for(int j=0; j<wymiar; ++j) {
        for(int i=0; i<wymiar; ++i) {
          Bufor(j,i)*=D;
        }
      }
      return Bufor;
    }

    /*!
   * Realizuje mnozenie macierzy przez inna macierz.
   * Argumenty:
   *    macierz - macierz przez ktora mnozymy.
   * Zwraca:
   *    Macierz wynikowa.
   */
    Macierz operator * (Macierz macierz) const {
      Macierz<wymiar> Wynik;

      for(int k=0; k<wymiar; ++k) {
        for(int j=0; j<wymiar; ++j) {
          for(int i=0; i<wymiar; ++i) {
            Wynik(k,j)+=(*this)(j,i)*macierz(i,k);
          }
        }
      }
      return Wynik;
    }

    /*!
   * Realizuje zmiane wartosci macierzy obrotu.
   * Argumenty:
   *    axis - os obrotu,
   *    angle - kat obrotu w radianach.
   */
    void zmien_macierz(const char axis, const Wektor3D &wektor);
};

/*!
   * Realizuje wypisanie macierzy.
   * Argumenty:
   *    stream - strumien wyjsica,
   *    matrix - obiekt do wypisania.
   * Zwraca:
   *    Strumien wyjscia.
   */
template <int wymiar>
inline
std::ostream& operator << (std::ostream &stream, const Macierz<wymiar> &macierz) {

  for(int i=0; i<wymiar; ++i) {
    for(int j=0; j<wymiar; ++j) {
      stream << std::setw(16) << std::fixed << std::setprecision(10) << macierz(i,j);
    }
    stream << std::endl;
  }
  stream << std::endl;
  return stream;
}


template <int wymiar>
void Macierz<wymiar>::zmien_macierz(const char axis, const Wektor3D &wektor) {

  Macierz<wymiar> OX;
  OX(0,0)=1;
  OX(0,1)=0;
  OX(0,2)=0;
  OX(1,0)=0;
  OX(1,1)=cos(wektor[0]);
  OX(1,2)=-sin(wektor[0]);
  OX(2,0)=0;
  OX(2,1)=sin(wektor[0]);
  OX(2,2)=cos(wektor[0]);

  Macierz<wymiar> OY;
  OY(0,0)=cos(wektor[1]);
  OY(0,1)=0;
  OY(0,2)=sin(wektor[1]);
  OY(1,0)=0;
  OY(1,1)=1;
  OY(1,2)=0;
  OY(2,0)=-sin(wektor[1]);
  OY(2,1)=0;
  OY(2,2)=cos(wektor[1]);

  Macierz<wymiar> OZ;
  OZ(0,0)=cos(wektor[2]);
  OZ(0,1)=-sin(wektor[2]);
  OZ(0,2)=0;
  OZ(1,0)=sin(wektor[2]);
  OZ(1,1)=cos(wektor[2]);
  OZ(1,2)=0;
  OZ(2,0)=0;
  OZ(2,1)=0;
  OZ(2,2)=1;

  switch (axis)
  {

    case 'x':
      (*this)=OX;      
      break;

    case 'y' :
      (*this)=OY;
      break;

    case 'z' :
      (*this)=OZ;
      break;   
  }
}

#endif
