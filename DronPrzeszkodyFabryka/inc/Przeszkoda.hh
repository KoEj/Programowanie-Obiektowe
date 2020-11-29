#ifndef PRZESZKODA_HH
#define PRZESZKODA_HH

#include <iostream>
#include <iomanip>
#include <string.h>

#include "Obiektsceny.hh"


/*!
 * \file  obstacle.hh
 *  
 *  Plik klasy przeszkoda 
 */


/*!
 * \brief Klasa Przeszkoda
 * 
 *  Klasa zawiera narzedza niezbedne do dzialania przeszkod.
 */
class Przeszkoda :public Obiekt_sceny {


public:
  Graniastoslup<8> cialo;

    Przeszkoda(const std::string &name, const Wektor3D &wielkosc, const Wektor3D &pozycja) {
      this->name=name;

      cialo[0][0]=-wielkosc[2]/2;
      cialo[0][1]=-wielkosc[0]/2;
      cialo[0][2]=-wielkosc[1]/2;

      cialo[1][0]=wielkosc[2]/2;
      cialo[1][1]=-wielkosc[0]/2;
      cialo[1][2]=-wielkosc[1]/2;

      cialo[2][0]=-wielkosc[2]/2;
      cialo[2][1]=wielkosc[0]/2;
      cialo[2][2]=-wielkosc[1]/2;

      cialo[3][0]=wielkosc[2]/2;
      cialo[3][1]=wielkosc[0]/2;
      cialo[3][2]=-wielkosc[1]/2;


      cialo[4][0]=-wielkosc[2]/2;
      cialo[4][1]=wielkosc[0]/2;
      cialo[4][2]=wielkosc[1]/2;

      cialo[5][0]=wielkosc[2]/2;
      cialo[5][1]=wielkosc[0]/2;
      cialo[5][2]=wielkosc[1]/2;

      cialo[6][0]=-wielkosc[2]/2;
      cialo[6][1]=-wielkosc[0]/2;
      cialo[6][2]=wielkosc[1]/2;
      
      cialo[7][0]=wielkosc[2]/2;
      cialo[7][1]=-wielkosc[0]/2;
      cialo[7][2]=wielkosc[1]/2;

      for(int i=0; i<8; ++i) {
        cialo[i]=cialo[i]+pozycja;
      }
  } 

  virtual ~Przeszkoda() { };

  virtual void zapis_do_pliku() {
    cialo.zapis_do_pliku("data/obstacle_" + name + ".dat" );
  }

  virtual bool kolizja(std::shared_ptr<Obiekt_sceny> obiekt) {
    return 0;
    }

};

#endif
