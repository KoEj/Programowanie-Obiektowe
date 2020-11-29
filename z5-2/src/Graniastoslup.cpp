#include "Graniastoslup.hh"


void Graniastoslup::StworzGraniastoslup( double Kat_st, double x_trans, double y_trans, double z_trans) {
    double  KatSkoku_st = 2*M_PI/ILOSC_WIERZCHOLKOW_GRANIATOSLUPA;
    double  x_wiersz, y_wiersz;

    for (unsigned int Idx = 0; Idx <= ILOSC_WIERZCHOLKOW_GRANIATOSLUPA; ++Idx) {
        x_wiersz = PROMIEN_PODSTAWY*cos(Kat_st);
        y_wiersz = PROMIEN_PODSTAWY*sin(Kat_st);
        Kat_st += KatSkoku_st;
        ZapiszCzteryWierzcholki(-x_wiersz, y_wiersz, GRUBOSC_ROTORA/2,x_trans,y_trans, PROSTOKAT_Z+GRUBOSC_ROTORA/2+z_trans);
    }
}

std::ostream & operator << ( std::ostream &Strm, const Graniastoslup &Gr ) {
    for (int i = 1; i <= Gr.get_size(); i++) {
        Strm << Gr[i - 1] << std::endl;
        if (i % 4 == 0)
            Strm << std::endl;
    }
    return Strm;
}
