#include <iostream>
#include <iomanip>
#include <fstream>
#include <memory>

#include "Wektor3D.hh"
#include "Macierz3x3.hh"
#include "Prostopadloscian.hh"
#include "lacze_do_gnuplota.hh"
#include "Macierz.hh"
#include "Korpus.hh"
#include "Dron.hh"
#include "Wirnik.hh"
#include "Graniastoslup.hh"
#include "Obiektsceny.hh"
#include "Przeszkoda.hh"
#include "Scena.hh"
#include "Fabryka_obiektow.hh"

using namespace std;

int Menu(char &wybor) 
{
  cout << "***********************************" << endl;
  cout << "*              Menu:             * " << endl;
  cout << "* o  - obrot drona               * " << endl;
  cout << "* j  - lot na wprost             * " << endl;
  cout << "* s  - ustaw predkosc drona      * " << endl;
  cout << "* c  - ustaw predkosc rotorow    * " << endl;
  cout << "* d  - zmiana drona              * " << endl;
  cout << "* l  - dodaj przeszkode          * " << endl;
  cout << "* p  - usun przeszkode           * " << endl;
  cout << "* w  - wyswietl menu             * " << endl;
  cout << "* k  - wyjscie z programu        * " << endl;
  cout << "***********************************" << endl;
  cout << "! Twoj wybor? (w - menu) >   ";
  cin >> wybor;
  cout << endl;
  return 0;
}

int main()
{
  PzG::LaczeDoGNUPlota  Lacze;
  Lacze.ZmienTrybRys(PzG::TR_3D);
  Lacze.Inicjalizuj();
  char wybor;
  Scena scena(&Lacze);

  Fabryka_obiektow fabryka(scena);

  fabryka.stworz(Typ_obiektu::typ_Dron, "A");
  fabryka.stworz(Typ_obiektu::typ_Dron, "B", {70,0,0});
  fabryka.stworz(Typ_obiektu::typ_Dron, "C", {-70,-50,0});
  //fabryka.stworz(Typ_obiektu::typ_Dron, "D", {70,0,50});
  fabryka.stworz(Typ_obiektu::typ_Przeszkoda, "sciana1", {70,70,0});
  fabryka.stworz(Typ_obiektu::typ_Przeszkoda, "sciana2", {70,-70,0});
  fabryka.stworz(Typ_obiektu::typ_Przeszkoda, "sciana3", {-70,-70,-50});
  
  // Ustawienie zakresow poszczegolnych osi
  Lacze.UstawZakresX(-100,100);
  Lacze.UstawZakresY(-100,100);
  Lacze.UstawZakresZ(-100,100);

  scena.zapis_do_pliku();
  Lacze.Rysuj();

  while(wybor!='k') {
    cout << endl;
    cout << "* Laczna ilosc stworzonych obiektow klasy Wektor3D: "<< Wektor<3>::calk_ilosc <<  endl;
    cout << "* Ilosc istniejacych obiektow klasy Wektor3D: " << Wektor<3>::ilosc  << endl << endl;

    cout << "* Laczna ilosc stworzonych obiektow sceny: "<< Obiekt_sceny::calk_ilosc <<  endl;
    cout << "* Ilosc istniejacych obiektow sceny: " << Obiekt_sceny::ilosc  << endl << endl;

    cout << "* Aktualnie wyselekcjonowanym dronem jest: " << scena.aktualny_dron->name << endl;
    cout << "* Wspolrzedne:" << scena.aktualny_dron->korpus.srodek() << endl;
      
    Menu(wybor);
      
    switch(wybor) {
      case 'k': {
          Lacze.UsunWszystkieNazwyPlikow();

          scena.aktualny_dron=nullptr;
          scena.Obiekty.clear();
          scena.Drony.clear();
          cout << "* Ilosc istniejacych obiektow klasy Wektor3D: " << Wektor<3>::ilosc  << endl << endl;
          cout << "* Ilosc istniejacych obiektow sceny: " << Obiekt_sceny::ilosc  << endl << endl;
          break;
        }

      case 'w': break;
      case 'o': {
          cout << "* Podaj o jaki kat obrocic drona: ";
          double kat;
          cin >> kat;
          scena.aktualny_dron->rotacja(kat, Lacze);
          break;
        }

      case 'j': 
          cout << "* Podaj dlugosc drogi przelotu i kat wznoszenia (+)/ opadania (-)."<< endl;
          cout << "* Dlugosc drogi: ";
          double buffor_droga;
          cin >> buffor_droga;

          std::cout << "* Kat wznoszenia: ";
          double kat_wznoszenia;
          cin >> kat_wznoszenia;

          scena.aktualny_dron->do_przodu(buffor_droga, kat_wznoszenia, scena.Obiekty, Lacze);
          break;

      case 's': 
          cout << "* Jak szybko ma sie poruszac dron?";
          cin >> scena.aktualny_dron->drone_speed;
          cout << "* Predkosc drona ustawiona na: " << scena.aktualny_dron->drone_speed << "  (domyslnie 10) " << endl;
          break;

      case 'l':  {
          cout << "* Nazwa przeszkody: ";
          string nowa_nazwa;
          cin >> nowa_nazwa;
          cout << "* Wielkosc przeszkody: ";
          double wielkosc[3];
          cin >> wielkosc[0];
          cin >> wielkosc[1];
          cin >> wielkosc[2];
          cout << "* Miejsce przeszkody: ";
          double miejsce[3];
          cin >> miejsce[0];
          cin >> miejsce[1];
          cin >> miejsce[2];
          
          fabryka.stworz(Typ_obiektu::typ_Przeszkoda, nowa_nazwa , wielkosc, miejsce );
          
          scena.zapis_do_pliku();
          Lacze.Rysuj();
          break;
        }

        case 'p':  {
          int wybrany_obiekt,i=0;
          for(shared_ptr<Obiekt_sceny> Obj : scena.Obiekty) {
            ++i;
            cout << i << "* Nazwa obiektu: " << Obj->name << endl;
          }
          cout << "* Podaj numer obiektu, ktory chcesz usunac." << endl;
          cout << "* Wprowadz numer obiektu lub 0. ";
          cin >> wybrany_obiekt;
          if(wybrany_obiekt!=0) {
            i=0;
              for(shared_ptr<Obiekt_sceny> Obj : scena.Obiekty) {
              if(++i==wybrany_obiekt) {
                scena.usun_obiekt(Obj);
                break; 
              }
            }
          }
          scena.zapis_do_pliku();
          Lacze.Rysuj();
          break;
        }


      case 'd': {
          int wybrany_dron,i=0;
          for(shared_ptr<Dron> Obj : scena.Drony) {
            ++i;
            cout << i << "* Nazwa drona: " << Obj->name;
            cout << "* Wspolrzedne: " << Obj->korpus.srodek() << endl;
          }
          cout << "* Podaj numer drona, dla ktorego maja byc wykonane operacje sterowania" << endl;
          cout << "* Wprowadz numer drona lub 0 > ";
          cin >> wybrany_dron;
          if(wybrany_dron!=0) {
            i=0;
            for(shared_ptr<Dron> Obj : scena.Drony) {
              if(++i==wybrany_dron) scena.aktualny_dron=Obj;
            }
          }
          break;
        }

      case 'c': 
          cout << "* Jak szybko maja sie obracac wirniki? ";
            cin >> scena.aktualny_dron->predkosc_wirnika;
            cout << "* Predkosc rotorow ustawiona na: " << scena.aktualny_dron->predkosc_wirnika << "  (domyslnie 100)" << endl;
          break;

      default:
          cin.clear(); 
          cin.ignore(256,'\n');  
          cout << "* Nie mozna wybrac:" << wybor << endl << endl;
          break;
    }
  }
  return 0;
}
