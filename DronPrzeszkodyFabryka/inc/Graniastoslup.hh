#ifndef GRANIASTOSLUP_HH
#define GRANIASTOSLUP_HH

#include <math.h>
#include <vector>
#include <string.h>
#include <fstream>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>

#include "Wektor3D.hh"
#include "Macierz3x3.hh"

#define EPSILON 0.0000001

/*!
 * \file  Graniastoslup.hh
 *  
 *  Plik klasy Graniastoslup
 */

/*!
 * \brief  Klasa wielokata
 *
 *  Klasa dla wielokota.
 */
template <int N>
class Graniastoslup {

  public:
  		
    std::vector<Wektor3D> wspol; // sklada sie z N wektorow.


  	Graniastoslup () { //Konstruktor domyslny
	 //  	for(int i=0; i<N; i++) {
		// 	wspol.push_back(*vec);
		// }
		wspol.resize(N);
  	} 
  
  	/*!
	 * Realizuje przeciazenie nawiasow kwadratowych.
	 * Argumenty:
	 *    Ind - indeks.
	 */
    Wektor3D  operator [] (int Ind) const { return wspol[Ind]; }

    /*!
	 * Realizuje przeciazenie nawiasow kwadratowych.
	 * Argumenty:
	 *    Ind - indeks.
	 */
    Wektor3D& operator [] (int Ind)       { return wspol[Ind]; }

    /*!
	 * Realizuje przesuniecie wierzcholkow.
	 * Argumenty:
	 *    vector - wektor przesuniecia.
	 */
    void przesuniecie ( const Wektor3D &wektor) {
		for(int i=0; i<N; i++) {
			(*this)[i]=(*this)[i]+wektor;
		}
    }

  	/*!
	 * Realizuje jednokrotny obrot wierzcholkow o zadany kat wokol osi.
	 * Argumenty:
	 *    angle - kat obrotu.
	 */
  	void rotacja ( const Macierz3x3 macierz_rotacji) {
  		for(int i=0; i<N; i++) {
			this->wspol[i]=macierz_rotacji*this->wspol[i];
		}
  	}

  	/*!
	 * Wypisuje informacje o wierzcholkach bokow.
	 */
  	void pokaz_wspol() {
  		std::cout << "Wspolrzedne wierzcholkow:" << std::endl;
  		for(int i=0; i<N; ++i) {
  			std::cout << 'A'+i << std::setw(16) << std::fixed << std::setprecision(10) << wspol[i];
  		}
 		std::cout << std::endl;
  	}

    /*!
	 * Realizuje wypisanie czworoscianu.
	 * Argumenty:
	 *    stream - strumien wyjsica,
	 *    cuboid - obiekt do wypisania.
	 * Zwraca:
	 *    Strumien wyjscia.
	 */
	friend std::ostream& operator << (std::ostream &stream, const Graniastoslup &graniastoslup) {
		for(int i=0; i<N; i++) {
			stream << graniastoslup.wspol[i];
			if((i+1)%2==0) stream << std::endl;
		}
	return stream;
	} 



	void zapis_do_pliku(std::string nazwa_pliku) {
        std::ofstream  zrodlo_pliku;
	  	zrodlo_pliku.open(nazwa_pliku);

	  	if (!zrodlo_pliku.is_open())  {
	      std::cerr << ":(  Operacja otwarcia do zapisu \"" << nazwa_pliku << "\"" << std::endl
	    << ":(  nie powiodla sie." << std::endl;
	    }

	    zrodlo_pliku << (*this) << (*this)[0] << (*this)[1];
	    zrodlo_pliku.close();
	    usleep(20000);
	}
};

#endif
