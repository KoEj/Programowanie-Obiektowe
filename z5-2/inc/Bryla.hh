#ifndef BRYLA_HH
#define BRYLA_HH

#include <iostream>
#include "Wektor3D.hh"
#include "Macierz3x3.hh"
#include <vector>

#define PROSTOKAT_X  10
#define PROSTOKAT_Y  12
#define PROSTOKAT_Z  5
#define ILOSC_WIERZCHOLKOW_GRANIATOSLUPA  6
#define PROMIEN_PODSTAWY                  10
#define GRUBOSC_ROTORA                    5.0

class Bryla {
protected:
    std::vector <Wektor3D> wiersz;
    Wektor3D srodek;
public:
    Bryla() {}
    Bryla (int roz) {
        wiersz.resize(roz);
    }
    
    void czysc_wektor() { wiersz.clear(); }
    void zamien_srodek( Wektor3D srodek ) ;
    int get_size() const { return wiersz.size(); }
    Wektor3D zwroc_srodek();
    Wektor3D & operator [] (int i) { return wiersz[i]; }
    Wektor3D operator [] (int i) const { return wiersz[i]; }


    void ZapiszTrzyWartosci( double w1, double w2, double w3) {
        Wektor3D wek_pom;
        wek_pom[0]=w1;
        wek_pom[1]=w2;
        wek_pom[2]=w3;
        wiersz.push_back(wek_pom);
    }

    void przsun( double w1, double w2, double w3) {
        Wektor3D wek_pom;
        for(int i=0; i<(int)wiersz.size(); i++) {
            wiersz[i][0]=w1+wek_pom[0];
            wiersz[i][1]=w2+wek_pom[1];
            wiersz[i][2]=w3+wek_pom[2];
        }
    }

    Wektor3D zwroc() {
        return wiersz[0];
    }

    void ZapiszCzteryWierzcholki ( double x_wiersz,double y_wiersz,double z_wiersz,double x_trans,double y_trans,double z_trans );
    void ZapiszCzteryWierzcholki_prze ( double x_trans,double y_trans,double z_trans );
};

#endif
