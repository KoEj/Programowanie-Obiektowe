#include "Prostopadloscian.hh"
#include <iomanip>

/*!
 * \file
 * \brief Plik zawiera dzialania na prostokacie
 */

/*!
 * \brief Porownianie bokow prostopadloscianu
 */
void Prostopadloscian::porownaj_boki()
{
    cout << setw(16) << fixed << setprecision(20) << wierzcholki[0].DlugoscWektora(wierzcholki[1]) << endl;
    cout << setw(16) << fixed << setprecision(20) << wierzcholki[2].DlugoscWektora(wierzcholki[3]) << endl;
    cout << setw(16) << fixed << setprecision(20) << wierzcholki[4].DlugoscWektora(wierzcholki[5]) << endl;
    cout << setw(16) << fixed << setprecision(20) << wierzcholki[6].DlugoscWektora(wierzcholki[7]) << endl;

    if (abs(wierzcholki[0].DlugoscWektora(wierzcholki[1]) - wierzcholki[2].DlugoscWektora(wierzcholki[3])) > EPS ||
            abs(wierzcholki[0].DlugoscWektora(wierzcholki[1]) - wierzcholki[4].DlugoscWektora(wierzcholki[5])) > EPS ||
            abs(wierzcholki[0].DlugoscWektora(wierzcholki[1]) - wierzcholki[6].DlugoscWektora(wierzcholki[7])) > EPS)
        cout << ":O Dluzsze przeciwlegle boki nie sa sobie rowne!!!" << endl;
    else
        cout << ":) Dluzsze przeciwlegle boki sa sobie rowne." << endl;

    cout << setw(16) << fixed << setprecision(20) << wierzcholki[7].DlugoscWektora(wierzcholki[1]) << endl;
    cout << setw(16) << fixed << setprecision(20) << wierzcholki[2].DlugoscWektora(wierzcholki[4]) << endl;
    cout << setw(16) << fixed << setprecision(20) << wierzcholki[5].DlugoscWektora(wierzcholki[3]) << endl;
    cout << setw(16) << fixed << setprecision(20) << wierzcholki[0].DlugoscWektora(wierzcholki[6]) << endl;

    if (abs(wierzcholki[0].DlugoscWektora(wierzcholki[6]) - wierzcholki[2].DlugoscWektora(wierzcholki[4])) > EPS ||
            abs(wierzcholki[0].DlugoscWektora(wierzcholki[6]) - wierzcholki[5].DlugoscWektora(wierzcholki[3])) > EPS ||
            abs(wierzcholki[0].DlugoscWektora(wierzcholki[6]) - wierzcholki[0].DlugoscWektora(wierzcholki[6])) > EPS)
        cout << ":O Krotsze przeciwlegle boki nie sa sobie rowne!!!" << endl;
    else
        cout << ":) Krotsze przeciwlegle boki sa sobie rowne." << endl;

    cout << setw(16) << fixed << setprecision(20) << wierzcholki[0].DlugoscWektora(wierzcholki[2]) << endl;
    cout << setw(16) << fixed << setprecision(20) << wierzcholki[1].DlugoscWektora(wierzcholki[3]) << endl;
    cout << setw(16) << fixed << setprecision(20) << wierzcholki[4].DlugoscWektora(wierzcholki[6]) << endl;
    cout << setw(16) << fixed << setprecision(20) << wierzcholki[5].DlugoscWektora(wierzcholki[7]) << endl;

    if (abs(wierzcholki[0].DlugoscWektora(wierzcholki[2]) - wierzcholki[1].DlugoscWektora(wierzcholki[3])) > EPS ||
            abs(wierzcholki[0].DlugoscWektora(wierzcholki[2]) - wierzcholki[4].DlugoscWektora(wierzcholki[6])) > EPS ||
            abs(wierzcholki[0].DlugoscWektora(wierzcholki[2]) - wierzcholki[5].DlugoscWektora(wierzcholki[7])) > EPS)
        cout << ":O Poprzeczne przeciwlegle boki nie sa sobie rowne!!!" << endl;
    else
        cout << ":) Poprzeczne przeciwlegle boki sa sobie rowne." << endl;
}

Wektor3D & Prostopadloscian::operator [] (int i)
{
    return wierzcholki[i];
}

Wektor3D Prostopadloscian::operator [] (int i) const
{
    return wierzcholki[i];
}

void Prostopadloscian::wartosci_wierzcholkow(Wektor3D wierz1, double bok1, double bok2, double bok3)
{
    for (int i = 1; i <= 8; i++)
        wierzcholki[i] = wierz1;

    wierzcholki[1][0] += bok1;

    wierzcholki[2][1] += bok2;

    wierzcholki[3][0] += bok1;
    wierzcholki[3][1] += bok2;

    wierzcholki[4][1] += bok2;
    wierzcholki[4][2] += bok3;

    wierzcholki[5][0] += bok1;
    wierzcholki[5][1] += bok2;
    wierzcholki[5][2] += bok3;

    wierzcholki[6][2] += bok3;

    wierzcholki[7][0] += bok1;
    wierzcholki[7][2] += bok3;
}
/*!
 * \brief Przeciazenie operatora <<
 */
std::ostream & operator << (std::ostream &Strm, const Prostopadloscian &Pr)
{
    for (int i = 1; i <= 8; i++)
    {
        Strm << Pr[i - 1] << std::endl;
        if (i % 2 == 0)
            Strm << std::endl;
    }

    return Strm;
}
/*!
 * \brief Zapis danych do strumienia
 */
void ZapisDoStrumienia(ostream &StrmWy, Wektor3D Przesuniecie, Prostopadloscian &Pr)
{
  for (int i = 0; i < 8; i++)
    Pr[i] = Pr[i] + Przesuniecie;

  StrmWy << setw(16) << fixed << setprecision(10) << Pr;
  StrmWy << setw(16) << fixed << setprecision(10) << Pr[0] << endl;
  StrmWy << setw(16) << fixed << setprecision(10) << Pr[1];

}
/*!
 * \brief Zapis danych do strumienia
 */
void ZapisDoStrumienia(ostream &StrmWy, Macierz3x3 Przesuniecie, Prostopadloscian &Pr)
{
  for (int i = 0; i < 8; i++)
    Pr[i] = Przesuniecie * Pr[i];

  StrmWy << setw(16) << fixed << setprecision(10) << Pr;
  StrmWy << setw(16) << fixed << setprecision(10) << Pr[0] << endl;
  StrmWy << setw(16) << fixed << setprecision(10) << Pr[1];

}
/*!
 * \brief Zapis danych do pliku
 */
bool ZapisWspolrzednychDoPliku(const char *sNazwaPliku, Wektor3D Przesuniecie, Prostopadloscian &Pr)
{
  ofstream StrmPlikowy;

  StrmPlikowy.open(sNazwaPliku);
  if (!StrmPlikowy.is_open())
  {
    cerr << ":(  Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << endl
         << ":(  nie powiodla sie." << endl;
    return false;
  }

  ZapisDoStrumienia(StrmPlikowy, Przesuniecie, Pr);

  StrmPlikowy.close();
  return !StrmPlikowy.fail();
}
/*!
 * \brief Zapis danych do pliku
 */
bool ZapisWspolrzednychDoPliku(const char *sNazwaPliku, Macierz3x3 Przesuniecie, Prostopadloscian &Pr)
{
  ofstream StrmPlikowy;

  StrmPlikowy.open(sNazwaPliku);
  if (!StrmPlikowy.is_open())
  {
    cerr << ":(  Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << endl
         << ":(  nie powiodla sie." << endl;
    return false;
  }

  ZapisDoStrumienia(StrmPlikowy, Przesuniecie, Pr);

  StrmPlikowy.close();
  return !StrmPlikowy.fail();
}
