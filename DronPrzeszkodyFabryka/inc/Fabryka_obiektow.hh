#ifndef FABRYKA_OBIEKTOW_HH
#define FABRYKA_OBIEKTOW_HH

#include <iostream>
#include <iomanip>
#include <memory>
#include <string.h>

#include "Wektor3D.hh"
#include "Dron.hh"
#include "Scena.hh"
#include "Obiektsceny.hh"
/*!
 * \file  Fabryka_obiektow.hh
 *  
 *  Plik klasy fabryka obiektow
 */


/*!
 * \brief Klasa Fabryka_obietkow
 * 
 *  Klasa zawiera narzedza niezbedne do dzialania fabryki.
 */
enum Typ_obiektu{typ_Dron, typ_Przeszkoda};

class Fabryka_obiektow  {
  Scena *scena;
  public:
    Fabryka_obiektow (Scena &scena1) {
      scena=&scena1;
    }

    /*!
   * Realizuje tworzenie nowych obiektow.
   * Argumenty:
   *    type - typ obiektu.
   *    name - nazwa obiektu.
   *    pozition - pozycja obiektu.
   *    size - rozmiar obiektu.
   */
    std::shared_ptr<Obiekt_sceny> stworz(const Typ_obiektu &type, const std::string &name, Wektor3D pozycja=Wektor3D({0,0,0}), Wektor3D wielkosc=Wektor3D({40,50,60}) ) {
      if(type==typ_Dron) {
          std::shared_ptr<Dron> dron(new Dron(name, pozycja));
          scena->dodaj_drona(dron);
          return dron;
      } 
      if(type==typ_Przeszkoda) {
          std::shared_ptr<Przeszkoda> przeszkoda1(new Przeszkoda(name,wielkosc,pozycja));
          scena->dodaj_przeszkode(przeszkoda1);
          return przeszkoda1;
      }
      return nullptr;
    }

};

#endif
