#ifndef OBIEKTSCENY_HH
#define OBIEKTSCENY_HH

#include <iostream>
#include <iomanip>
#include <memory>
#include <string.h>

#include "Wektor3D.hh"
#include "Dron.hh"

/*!
 * \file  Obiektsceny.hh
 *  
 *  Plik klasy obiekt sceny 
 */


/*!
 * \brief Klasa Obiekt_Sceny
 * 
 *  Klasa zawiera narzedza niezbedne do dzialania sceny.
 */
class Obiekt_sceny  {
public:
    Wektor3D droga;
	double azymut;
	std::string name;
	static int ilosc, calk_ilosc;

	Obiekt_sceny() {
      ilosc++;
      calk_ilosc++;
    }

    virtual ~Obiekt_sceny() { --ilosc; }
    
    virtual void zapis_do_pliku()=0;

    virtual bool kolizja(std::shared_ptr<Obiekt_sceny> object) =0;

};

int Obiekt_sceny::ilosc=0;
int Obiekt_sceny::calk_ilosc=0;

#endif
