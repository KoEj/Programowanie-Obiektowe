#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Wektor3D.hh"
#include "Macierz3x3.hh"
#include "Prostopadloscian.hh"
#include "lacze_do_gnuplota.hh"
#define DLUGOSC 90
using namespace std;

/*!
 * \file
 * Plik main
 */

struct element_sekwencji
{
    char os;
    int kat;
};
/*!
 * \brief Menu programu
 */
void menu() {
    cout << "--------------------------------------------------------" << endl
    << "* MENU PROGRAMU" << endl
    << "* o - obrot bryly o kat" << endl
    << "* t - powtorzenie poprzedniego obrotu" << endl
    << "* r - wyswietlenie macierzy rotacji" << endl
    << "* p - przesuniecie prostokata o zadany wektor" << endl
    << "* w - wyswietlenie wspolrzednych wierzcholkow" << endl
    << "* s - sprawdzenie dlugosci przeciwleglych bokow" << endl
    << "* m - wyswietl menu" << endl
    << "* k - koniec dzialania programu" << endl
    << "--------------------------------------------------------" << endl;
}
/*!
 * \brief Czesc wykonywalna programu
 */
int main()
{
    Prostopadloscian Pr;
    PzG::LaczeDoGNUPlota Lacze;
    vector <element_sekwencji> sekwencja;
    element_sekwencji element;
    Wektor3D wek;
    Macierz3x3 M;
    char opcja;
    char os;
    double kat;

    //GNUPLOT
    Lacze.DodajNazwePliku("prostopadloscian.dat", PzG::RR_Ciagly, 2);
    Lacze.ZmienTrybRys(PzG::TR_3D);
    Lacze.UstawZakresY(-255, 255);
    Lacze.UstawZakresX(-255, 255);
    Lacze.UstawZakresZ(-255, 255);

    Pr.wartosci_wierzcholkow(wek, DLUGOSC, DLUGOSC, DLUGOSC);
    if (!ZapisWspolrzednychDoPliku("prostopadloscian.dat", wek, Pr))
        return 1;
    Lacze.Rysuj();

    Pr.porownaj_boki();


    //PROGRAM
    menu();

    int  ile_powt = 0;
    while (1)
    {
        cout << "! Podaj opcje ( m - menu )>> ";
        cin >> opcja;
        switch (opcja)
        {
        case 'o':
            os = ' ';
            sekwencja.clear();
                cout << "! Podaj sekwencje: " << endl << "* Prawidlowa postac: oś liczba" << endl << "* Gdzie oś->[x,y,z] liczba->[dowolna liczba]"<< endl << "* Zakończ wpisywanie znakiem '.'"<<endl;
            while (os != '.')
            {
                cin >> os;
                if (os != '.')
                {

                    cin >> kat;

                    if (os == 'x' || os == 'y' || os == 'z')
                    {
                        element.os = os;
                        element.kat = kat;
                        sekwencja.push_back(element);
                    }
                    else
                    {
                        cout << "* Nie ma takiej osi :(" << endl;
                    }
                }
                else
                {
                    cout << "! Ilosc powtorzen: ";
                    cin >> ile_powt;
                    for (int j = 0; j < ile_powt; j++)
                        for (int i = 0; i < (int)sekwencja.size(); i++)
                        {
                            if (sekwencja[i].os == 'x')
                            {
                                M.set_kat(sekwencja[i].kat);
                                Wylicz_macierz_x(M);
                                if (!ZapisWspolrzednychDoPliku("prostopadloscian.dat", M, Pr))
                                    return 1;
                            }
                            else if (sekwencja[i].os == 'y')
                            {
                                M.set_kat(sekwencja[i].kat);
                                Wylicz_macierz_y(M);
                                if (!ZapisWspolrzednychDoPliku("prostopadloscian.dat", M, Pr))
                                    return 1;
                            }
                            else if (sekwencja[i].os == 'z')
                            {
                                M.set_kat(sekwencja[i].kat);
                                Wylicz_macierz_z(M);
                                if (!ZapisWspolrzednychDoPliku("prostopadloscian.dat", M, Pr))
                                    return 1;
                            }
                        }
                }
            }

            Lacze.Rysuj();

            break;
        case 't':
            for (int i = 0; i < (int)sekwencja.size(); i++)
            {
                if (sekwencja[i].os == 'x')
                {
                    M.set_kat(sekwencja[i].kat);
                    Wylicz_macierz_x(M);
                    if (!ZapisWspolrzednychDoPliku("prostopadloscian.dat", M, Pr))
                        return 1;
                }
                else if (sekwencja[i].os == 'y')
                {
                    M.set_kat(sekwencja[i].kat);
                    Wylicz_macierz_y(M);
                    if (!ZapisWspolrzednychDoPliku("prostopadloscian.dat", M, Pr))
                        return 1;
                }
                else if (sekwencja[i].os == 'z')
                {
                    M.set_kat(sekwencja[i].kat);
                    Wylicz_macierz_z(M);
                    if (!ZapisWspolrzednychDoPliku("prostopadloscian.dat", M, Pr))
                        return 1;
                }
            }
            Lacze.Rysuj();
            break;
        case 'r':
                cout << "* Wyświetlanie wektora rotacji" << endl;
            cout << M;
            break;
        case 'p':
                cout << "* Podaj wektor przesuniecia w postaci" << endl << "* liczba (oś x)" << endl << "* liczba (oś y)" << endl << "* liczba (oś z)" << endl;
            cin >> wek;
            if (!ZapisWspolrzednychDoPliku("prostopadloscian.dat", wek, Pr))
                return 1;
            Lacze.Rysuj();
            break;
        case 'w':
                cout << "* Wyświetlanie wierzchołków" << endl;
            cout << Pr;
            break;
        case 'm':
            menu();
            break;
        case 's':
            Pr.porownaj_boki();
            break;
        case 'k':
            return 0;
            break;
        }
    }
}


