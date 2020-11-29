#include "Bryla.hh"

void Bryla::zamien_srodek(Wektor3D srodek) {
    this->srodek=srodek;
}

Wektor3D Bryla::zwroc_srodek() {
    return srodek;
}

void Bryla::ZapiszCzteryWierzcholki(double x_wiersz,double y_wiersz,double z_wiersz,double x_trans,double y_trans,double z_trans) {
    ZapiszTrzyWartosci( x_trans, y_trans, z_wiersz+z_trans );
    ZapiszTrzyWartosci( x_wiersz+x_trans, y_wiersz+y_trans, z_wiersz+z_trans );
    ZapiszTrzyWartosci( x_wiersz+x_trans, y_wiersz+y_trans, -z_wiersz+z_trans );
    ZapiszTrzyWartosci( x_trans, y_trans, -z_wiersz+z_trans );
}


