#ifndef SCENA_HH
#define SCENA_HH

#include <iostream>
#include <iomanip>
#include "lacze_do_gnuplota.hh"

/*!
 * \file  Scena.hh
 *  
 *  Plik klasy sceny 
 */


/*!
 * \brief Klasa Scena
 * 
 *  Klasa zawiera narzedza niezbedne do dzialania sceny.
 */
class Scena  {
  PzG::LaczeDoGNUPlota  *Lacze;

  public:
    std::list<std::shared_ptr<Dron>> Drony;
    std::list<std::shared_ptr<Obiekt_sceny>> Obiekty;
    std::shared_ptr<Dron> aktualny_dron;

    Scena(PzG::LaczeDoGNUPlota *gnuplot) {
      Lacze=gnuplot;
    }

    /*!
   * Realizuje dodawanie nowych obiektow.
   * Argumenty:
   *    przeszkoda1 - nowy obiekt do dodania.
   */
    void dodaj_przeszkode(std::shared_ptr<Przeszkoda> przeszkoda1) {
      Obiekty.push_back(przeszkoda1);
      PzG::InfoPlikuDoRysowania *wInfoPliku1 = &Lacze->DodajNazwePliku(("data/obstacle_" + przeszkoda1->name + ".dat").data());
      wInfoPliku1->ZmienKolor(Obiekty.size());
      wInfoPliku1->ZmienSzerokosc(2);
    }

    /*!
   * Realizuje dodawanie nowych dronow.
   * Argumenty:
   *    drone - nowy dron do dodania.
   */
    void dodaj_drona(std::shared_ptr<Dron> dron) {
      Obiekty.push_back(dron);
      Drony.push_back(dron);
      aktualny_dron=dron;

      PzG::InfoPlikuDoRysowania *wInfoPliku1 = &Lacze->DodajNazwePliku(("data/drone_" + dron->name + "_body.dat").data());
      PzG::InfoPlikuDoRysowania *wInfoPliku2 = &Lacze->DodajNazwePliku(("data/drone_" + dron->name + "_rotor0.dat").data());
      PzG::InfoPlikuDoRysowania *wInfoPliku3 = &Lacze->DodajNazwePliku(("data/drone_" + dron->name + "_rotor1.dat").data());
      PzG::InfoPlikuDoRysowania *wInfoPliku4 = &Lacze->DodajNazwePliku(("data/drone_" + dron->name + "_rotor2.dat").data());
      PzG::InfoPlikuDoRysowania *wInfoPliku5 = &Lacze->DodajNazwePliku(("data/drone_" + dron->name + "_rotor3.dat").data());

      wInfoPliku1->ZmienKolor(Obiekty.size());
      wInfoPliku1->ZmienSzerokosc(2);
      wInfoPliku2->ZmienKolor(Obiekty.size());
      wInfoPliku2->ZmienSzerokosc(2);
      wInfoPliku3->ZmienKolor(Obiekty.size());
      wInfoPliku3->ZmienSzerokosc(2);
      wInfoPliku4->ZmienKolor(Obiekty.size());
      wInfoPliku4->ZmienSzerokosc(2);
      wInfoPliku5->ZmienKolor(Obiekty.size());
      wInfoPliku5->ZmienSzerokosc(2);
    }


    /*!
   * Realizuje zapisywanie obiektow do pliku.
   * Argumenty:
   *    Obiekty - obiekt do zapisania.
   */
    void zapis_do_pliku() {
      for( std::shared_ptr<Obiekt_sceny> Obj : Obiekty) {
        Obj->zapis_do_pliku();
      }
    }

};

#endif
