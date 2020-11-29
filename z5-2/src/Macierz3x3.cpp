#include "Macierz3x3.hh"


/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Macierz3x3, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */
Macierz3x3 obrot_x(Macierz3x3 M) {
    M(0,0)=1;
    M(0,1)=0;
    M(0,2)=0;

    M(1,0)=0;
    M(1,1)=cos(M.get_kat());
    M(1,2)=-sin(M.get_kat());

    M(2,0)=0;
    M(2,1)=sin(M.get_kat());
    M(2,2)=cos(M.get_kat());
return M;
}

Macierz3x3 obrot_y(Macierz3x3 M) {
    M(0,0)=cos(M.get_kat());
    M(0,1)=0;
    M(0,2)=sin(M.get_kat());

    M(1,0)=0;
    M(1,1)=1;
    M(1,2)=0;

    M(2,0)=-sin(M.get_kat());
    M(2,1)=0;
    M(2,2)=cos(M.get_kat());
return M;
}

Macierz3x3 obrot_z(Macierz3x3 M) {
    M(0,0)=cos(M.get_kat());
    M(0,1)=-sin(M.get_kat());
    M(0,2)=0;

    M(1,0)=sin(M.get_kat());
    M(1,1)=cos(M.get_kat());
    M(1,2)=0;

    M(2,0)=0;
    M(2,1)=0;
    M(2,2)=1;
return M;
}
