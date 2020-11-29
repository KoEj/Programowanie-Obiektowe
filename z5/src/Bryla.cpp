#include "Bryla.hh"

void Bryla::zamien_srodek(Wektor3D srodek) {
    this->srodek=srodek;
}

Wektor3D Bryla::zwroc_srodek() {
    return srodek;
}

void Bryla::ZapiszCzteryWierzcholki(double x_wierz,double y_wierz,double z_wierz,double x_trans,double y_trans,double z_trans) {
    ZapiszTrzyWartosci( x_trans, y_trans, z_wierz+z_trans );
    ZapiszTrzyWartosci( x_wierz+x_trans, y_wierz+y_trans, z_wierz+z_trans );
    ZapiszTrzyWartosci( x_wierz+x_trans, y_wierz+y_trans, -z_wierz+z_trans );
    ZapiszTrzyWartosci( x_trans, y_trans, -z_wierz+z_trans );
}


