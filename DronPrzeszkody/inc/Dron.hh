#ifndef DRON_HH
#define DRON_HH

#include <iostream>
#include <iomanip>
#include <math.h>
#include <string.h>

#include "Korpus.hh"
#include "Wirnik.hh"
#include "Obiektsceny.hh"
#include "Przeszkoda.hh"


#define PREDKOSC_OBROTU                   10  // Predkosc obrotu drona
#define PROMIEN_ROTORA                    8

/*!
 * \file  Dron.hh
 *  
 *  Plik klasy Dron
 */


/*!
 * \brief Klasa drona
 * 
 *  Klasa zawiera narzedza niezbedne do dzialania drona.
 *	Skalda sie z 4 rotorow i ciala drona. 
 */
class Dron :public Obiekt_sceny {

  public:
  	Korpus korpus;
  	Wirnik wirnik[4];
  	int drone_speed=10;
  	int predkosc_wirnika=100;

  	Dron(const std::string &name, const Wektor3D &pozycja, const int width=24, const int height=20, const int long=20) {
  		this->name=name;
  		droga=pozycja;
  		int predkosc_wirnikow[4] = { predkosc_wirnika, predkosc_wirnika, predkosc_wirnika, predkosc_wirnika };
        przesuniecie(azymut, droga, predkosc_wirnikow);

  	}


    virtual ~Dron() { };

	/*!
	 * Realizuje obrot drona o zadany kat wokol osi drona. Posiada animacje.
	 * Argumenty:
	 *    angle - kat obrotu.
	 *    azymuth - aktualny azymut drona.
	 *    link - link do GNUPlota.
	 *    road - aktualne polozenie drona.
	 *    rotor_speed - predkosc obrotu rotorow przy wykonywaniu manewru.
	 */
  	void rotacja ( const double &kat,  PzG::LaczeDoGNUPlota  Lacze) {
         int predkosc_wirnikow[4] = { predkosc_wirnika, predkosc_wirnika, predkosc_wirnika, predkosc_wirnika };
      double drotacja=kat;
      int kierunek = (kat > 0) ? 1 : -1;
      if(kierunek>0) {
      	predkosc_wirnikow[0]=4*predkosc_wirnikow[0];
      	predkosc_wirnikow[3]=4*predkosc_wirnikow[3];
      }
      if(kierunek<0) {
      	predkosc_wirnikow[1]=4*predkosc_wirnikow[1];
      	predkosc_wirnikow[2]=4*predkosc_wirnikow[2];
      }

      while(abs(drotacja)>0) {
        if(abs(drotacja)>=PREDKOSC_OBROTU) {
          drotacja-=(PREDKOSC_OBROTU*kierunek);
          azymut+=(PREDKOSC_OBROTU*kierunek*M_PI/180);
        }
        else {
          azymut+=(drotacja*M_PI/180);
          drotacja=0;
        }
        przesuniecie(azymut, droga, predkosc_wirnikow);
	      zapis_do_pliku();
	      Lacze.Rysuj();
	      usleep(200000);
      }
      korpus.pokaz_wspol();
  	}

	/*!
	 * Realizuje przemieszczenie sie drona o zadany wektor. Posiada animacje.
	 * Argumenty:
	 *    buffor_road - trasa do przebycia.
	 *    azymuth - aktualny azymut drona.
	 *    rise_angle - kat lotu.
	 *    link - link do GNUPlota.
	 *    road - aktualne polozenie drona.
	 *    rotor_speed - predkosc obrotu rotorow przy wykonywaniu manewru.
	 *    drone_speed - predkosc poruszania sie drona.
	 */
    void do_przodu( const double &buffor_drogi, const double &kat_wznoszenia, std::list<std::shared_ptr<Obiekt_sceny>> &Obiekty, PzG::LaczeDoGNUPlota Lacze) {
        int predkosc_wirnikow[4] = { predkosc_wirnika, predkosc_wirnika, predkosc_wirnika, predkosc_wirnika };
        Wektor3D droga_do_przebycia;
        Wektor3D ostatnia_pozycja;;
        bool kolizja1=false;
        
        droga_do_przebycia[0]=(-buffor_drogi*cos(kat_wznoszenia*M_PI/180))*sin((M_PI-azymut));
        droga_do_przebycia[1]=(-buffor_drogi*cos(kat_wznoszenia*M_PI/180))*cos((M_PI-azymut));
        droga_do_przebycia[2]=buffor_drogi*sin(kat_wznoszenia*M_PI/180);
        
        int direction[3] = {
            (droga_do_przebycia[0] > 0) ? 1 : -1,
            (droga_do_przebycia[1] > 0) ? 1 : -1,
            (droga_do_przebycia[2] > 0) ? 1 : -1
        };
        
        while(droga_do_przebycia>0 && !kolizja1) {
            ostatnia_pozycja=droga;;
            for(int i=0; i<3; ++i) {
                
                if(abs(droga_do_przebycia[i])>=drone_speed) {
                    droga_do_przebycia[i]-=(drone_speed*direction[i]);
                    droga[i]+=(drone_speed*direction[i]);
                }
                else {
                    droga[i]+=(droga_do_przebycia[i]);
                    droga_do_przebycia[i]=0;
                }
            }
            przesuniecie(azymut, droga, predkosc_wirnikow);
            
            for(std::shared_ptr<Obiekt_sceny> Obj : Obiekty) {
                if(kolizja(Obj) && Obj.get()!=this) {
                    przesuniecie(azymut, ostatnia_pozycja, predkosc_wirnikow);
                    kolizja1=true;
                    droga=ostatnia_pozycja;
                    std::cout << "!@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@!" << std::endl;
                    std::cout << " Wykryta została kolizja z " + Obj->name;
                    std::cout << "!!! Lot zostal przerwany. " << std::endl;
                    std::cout << "!@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@!" << std::endl;
                    break;
                }
            }
            zapis_do_pliku();
            Lacze.Rysuj();
            usleep(200000);
        }
    }

	  /*!
		 * Realizuje przemieszczenie sie drona do punktu startu i wykonuje na nim niezbedne transformacje.
		 * Argumenty:
		 *    azymuth - aktualny azymut drona.
		 *    road - aktualne polozenie drona.
		 *    rotors_speed - predkosc obrotu rotorow przy wykonywaniu manewru.
		 */
	  void przesuniecie(const double &azymut, const Wektor3D &droga, const int predkosc_wirnikow[4]) {
	  	Macierz3x3 macierz_rotacji;
        Wektor3D trans;
        trans[2]=azymut;
	  	korpus.reset();
	  	macierz_rotacji.zmien_macierz('z', trans);
        korpus.rotacja(macierz_rotacji);

        korpus.przesuniecie(droga);
        wrinik_obrot();

      wirnik[0].obrot_rotora( -predkosc_wirnikow[0]);
      wirnik[1].obrot_rotora(  predkosc_wirnikow[1]);
      wirnik[2].obrot_rotora(  predkosc_wirnikow[2]);
      wirnik[3].obrot_rotora( -predkosc_wirnikow[3]);
	  }
	  
	  /*!
		 * Realizuje przemieszczenie sie rotorow.
		 */
	  void  wrinik_obrot() {
		  wirnik[0].srodek();
		  wirnik[1].srodek();
		  wirnik[2].srodek();
		  wirnik[3].srodek();
		  wirnik[0].przesuniecie(korpus.wspol[6]);
		  wirnik[1].przesuniecie(korpus.wspol[7]);
		  wirnik[2].przesuniecie(korpus.wspol[4]);
		  wirnik[3].przesuniecie(korpus.wspol[5]);
		}


		virtual void zapis_do_pliku() {
			korpus.zapis_do_pliku("data/drone_" + name + "_body.dat");

			for(int i=0; i<4; ++i) {
			wirnik[i].zapis_do_pliku("data/drone_" +name+ "_rotor" + std::to_string(i) + ".dat");
			}
		}

		/*!
   * Sprawdza czy obiekty sie zderzaja.
   * Argumenty:
   *    shared_ptr<Scene_object> object - lista obiektow.
   */
		virtual bool kolizja(std::shared_ptr<Obiekt_sceny> obiekt) {
    	if(Dron* dron = dynamic_cast<Dron*>(obiekt.get())) {
    		Wektor3D center1 = korpus.srodek();
    		Wektor3D center2 = dron->korpus.srodek();
    		double distance= sqrt(( center1[0] - center2[0])*( center1[0] - center2[0]) +  ( center1[1] - center2[1])*( center1[1] - center2[1]) );
    		return distance<= wez_kat()+ dron->wez_kat();
    	}

    	if(Przeszkoda* przeszkoda = dynamic_cast<Przeszkoda*>(obiekt.get())) {
    		Wektor3D center = korpus.srodek();
    		return (center[0] > przeszkoda->cialo[0][0] - wez_kat() &&
    		 			center[0] < przeszkoda->cialo[5][0] + wez_kat() &&
    		  			center[1] > przeszkoda->cialo[0][1] - wez_kat() &&
    		   			center[1] < przeszkoda->cialo[5][1] + wez_kat() &&
    		   			center[2] > przeszkoda->cialo[0][2] - wez_kat() &&
    		   			center[2] < przeszkoda->cialo[5][2] + wez_kat() );
    	}
    	return 0;
		}

    /*!
   * Realizuje liczenie promienia drona.
   */
		double wez_kat() {
			Wektor3D P1;
			P1=korpus.srodek();
			return P1.length(korpus.wspol[0])+PROMIEN_ROTORA;
		}


};

#endif
