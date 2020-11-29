#ifndef DRON_HH
#define DRON_HH

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <unistd.h>
#include "Macierz3x3.hh"
#include "lacze_do_gnuplota.hh"
#include "Graniastoslup.hh"
#include "Prostopadloscian.hh"

#define NAZWA_PLIKU__PROSTOPADLOSCIAN  "dat/prostopadloscian1.dat"
#define NAZWA_PLIKU__GRANIATOSLUP_1    "dat/graniastoslup1.dat"
#define NAZWA_PLIKU__GRANIATOSLUP_2    "dat/graniastoslup2.dat"
#define NAZWA_PLIKU__GRANIATOSLUP_3    "dat/graniastoslup3.dat"
#define NAZWA_PLIKU__GRANIATOSLUP_4    "dat/graniastoslup4.dat"

class Dron {
    PzG::LaczeDoGNUPlota  Lacze;
    Prostopadloscian Pr;
    Graniastoslup Gr[4];
    double kat, droga;
    Macierz3x3 M_drogi;
    Macierz3x3 M;
    Macierz3x3 M_wirniki;
    Wektor3D Wek;
    double suma_katow;
    int wszystkie_wektory;
    int aktualne_wektory;
    
public:
    Dron();
    bool AnimacjaRuchuDrona( unsigned int IloscIteracji,double Kat_Zmiana_st,double x_Zmiana,double y_trans,double z_Zmiana );
    bool ruch();
    bool ZapiszDrona( double Kat_st, double x_trans , double y_trans, double z_trans );
    void zapisz();
    bool zmien( double Kat_st ,double x_trans, double y_trans, double z_trans );
};


#endif
