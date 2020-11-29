#ifndef PROSTOPADLOSCIAN_HH
#define PROSTOPADLOSCIAN_HH

#include <iostream>
#include <math.h>

#include "Wektor3D.hh"
#include "Macierz3x3.hh"
#include "Graniastoslup.hh"
#define EPSILON 0.0000001

/*!
 * \file  Prostopadloscian.hh
 *  
 *  Plik klasy Prostopadloscian
 */

/*!
 * \brief  Klasa czworoscianu
 *
 *  Klasa dla czworoscianu. Sklada sie z 8 wektorow. Dziedziczy z klasy wielokata.
 */
class Prostopadloscian :public Graniastoslup<8>{

protected:	
  public:
  	Prostopadloscian() : Graniastoslup(){}
    Prostopadloscian (Wektor3D v1, Wektor3D v2, Wektor3D v3, Wektor3D v4, Wektor3D v5, Wektor3D v6, Wektor3D v7, Wektor3D v8) {
  		this->wspol[0]=v1;
		this->wspol[1]=v2;
		this->wspol[2]=v3;
		this->wspol[3]=v4;
		this->wspol[4]=v5;
		this->wspol[5]=v6;
		this->wspol[6]=v7;
		this->wspol[7]=v8;
  	} //Konstruktor

  	void info() {
  	  double length[12];

	  length[0]=wspol[2].length(wspol[0]);
	  length[1]=wspol[3].length(wspol[1]);
	  length[2]=wspol[4].length(wspol[6]);
	  length[3]=wspol[5].length(wspol[7]);
	  
	  length[4]=wspol[4].length(wspol[2]);
	  length[5]=wspol[5].length(wspol[3]);
	  length[6]=wspol[7].length(wspol[1]);
	  length[7]=wspol[6].length(wspol[0]);
	  
	  length[8]=wspol[1].length(wspol[0]);
	  length[9]=wspol[3].length(wspol[2]);
	  length[10]=wspol[7].length(wspol[6]);
	  length[11]=wspol[5].length(wspol[4]);
	    
	  if(fabs(length[0]-length[1])<EPSILON && fabs(length[2]-length[3])<EPSILON) std::cout << "Dluzsze przeciwlegle boki sa sobie rowne." << std::endl;
	  else std::cout << "Dluzsze przeciwlegle boki nie sa sobie rowne." << std::endl;
	  std::cout << std::setprecision(10);
	  std::cout << length[0] << std::endl;
	  std::cout << length[1] << std::endl;
	  std::cout << length[2] << std::endl;
	  std::cout << length[3] << std::endl;
	  std::cout << std::endl;


	  if(fabs(length[4]-length[5])<EPSILON && fabs(length[6]-length[7])<EPSILON) std::cout << "Poprzeczne przeciwlegle boki sa sobie rowne" << std::endl;
	  else std::cout << "Poprzeczne przeciwlegle boki nie sa sobie rowne" << std::endl;
	  std::cout << std::setprecision(10);
	  std::cout << length[4] << std::endl;
	  std::cout << length[5] << std::endl;
	  std::cout << length[6] << std::endl;
	  std::cout << length[7] << std::endl;
	  std::cout << std::endl;

	  if(fabs(length[8]-length[9])<EPSILON && fabs(length[10]-length[11])<EPSILON) std::cout << "Krotsze przeciwlegle boki sa sobie rowne." << std::endl;
	  else std::cout << "Krotsze przeciwlegle boki nie sa sobie rowne." << std::endl;
	  std::cout << std::setprecision(10);
	  std::cout << length[8] << std::endl;
	  std::cout << length[9] << std::endl;
	  std::cout << length[10] << std::endl;
	  std::cout << length[11] << std::endl;
	  std::cout << std::endl;
  	}
};

#endif
