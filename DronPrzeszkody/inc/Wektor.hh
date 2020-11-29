#ifndef WEKTOR_HH
#define WEKTOR_HH

#include <iostream>
#include <iomanip>
#include <math.h>

/*!
 * \file  Wektor.hh
 *  
 *  Plik klasy Wektor
 */


/*!
 * \brief Klasa wektora
 * 
 *  Klasa zawiera narzedza niezbedne do dzialania wektorow.
 */
template <int wymiar>
class Wektor {
  double wektor[wymiar]={0};

  public:

  static int ilosc, calk_ilosc;

    Wektor() {
        ilosc++;
        calk_ilosc++;
    }

    Wektor(std:: initializer_list <double> inputs) :Wektor(){
      int i=0;
      for(double d : inputs) {
        wektor[i++]=d;
      }
    }

    Wektor(const Wektor& wektor1) {
      for(int i=0; i<wymiar; ++i) wektor[i]=wektor1[i];
    }

    Wektor(double Wspol[wymiar]) :Wektor() {
      for(int i=0; i<wymiar; ++i ) {
        wektor[i]=Wspol[i];
      }
    }

    ~Wektor() { --ilosc; }

  /*!
   * Realizuje przeciazenie nawiasow kwadratowych.
   * Argumenty:
   *    Ind - indeks.
   */
    double  operator [] (int Ind) const { return wektor[Ind]; }

    /*!
   * Realizuje przeciazenie nawiasow kwadratowych. TODO: ASSERRT!!!!!
   * Argumenty:
   *    Ind - indeks.
   */
    double & operator [] (int Ind)       { return wektor[Ind]; }


    /*!
   * Realizuje liczenie dlugosci wektora.
   * Argumenty:
   *    wektor1 - wektor do zmierzenia.
   */
    double length ( const Wektor &wektor) {
      double suma=0,y=0;
      for(int i=0; i<wymiar; ++i) {

        y=((*this)[i]-wektor[i]);
        y=y*y;
        suma+=y;
      }
      return sqrt(suma);
    }

    /*!
     * Realizuje mnozenie wektorowe wektorow.
     * Argumenty:
     *    wektor1 - wektor przez ktory chcemy przemnozyc.
     * Zwraca:
     *    wektor wynikowy.
     */
    Wektor operator * ( const Wektor<wymiar> &wektor) {
      Wektor<3>  Wynik;

      Wynik[0] = (this->wektor[1]*wektor[2])-(this->wektor[2]*wektor[1]);
      Wynik[1] = (this->wektor[2]*wektor[0])-(this->wektor[0]*wektor[2]);
      Wynik[2] = (this->wektor[0]*wektor[1])-(this->wektor[1]*wektor[0]);

      return Wynik;
    }

    /*!
     * Realizuje przypisanie wektorowe wektorow.
     * Argumenty:
     *    wektor1 - wektor przez ktory chcemy przypisac.
     * Zwraca:
     *    wektor wynikowy.
     */
    Wektor& operator = ( const Wektor<wymiar> &wektor) {
      for(int i=0; i<wymiar; ++i) {
        (*this)[i]=wektor[i];
      }
      return *this;
    }

    /*!
     * Realizuje mnozenie skalarne wektorw.
     * Argumenty:
     *    wektor1 - wektor przez ktory chcemy przemnozyc.
     * Zwraca:
     *    wektor wynikowy.
     */
    double operator & ( const Wektor<wymiar> &wektor) {
      double C;
      for(int i=0; i<wymiar; ++i) {
        C+=(this->wektor[i]*wektor[i]);
      }
      return C;
    }


    /*!
     * Realizuje odejmowanie wektorow.
     * Argumenty:
     *    wektor1 - wektor ktory chcemy odjac.
     * Zwraca:
     *    wektor wynikowy.
     */
    Wektor  operator - ( const Wektor<wymiar> &wektor) {
      Wektor<wymiar>  Wynik;

      for(int i=0; i<wymiar; ++i) {
        Wynik[i] = this->wektor[i]-wektor[i];
      }
      return Wynik;
    }

    /*!
     * Realizuje odejmowanie wektorow.
     * Argumenty:
     *    wektor1 - wektor ktory chcemy odjac.
     * Zwraca:
     *    wektor wynikowy.
     */
    bool  operator > ( const double d) {
      double Wynik=0;

      for(int i=0; i<wymiar; ++i) {
        Wynik += (this->wektor[i])*(this->wektor[i]);
      }
      return sqrt(Wynik)>d;
    }

    /*!
     * Realizuje dodawanie wektorow.
     * Argumenty:
     *    wektor1 - wektor ktory chcemy dodac.
     * Zwraca:
     *    wektor wynikowy.
     */
    Wektor  operator + ( const Wektor<wymiar> &wektor) {
      Wektor<wymiar>  Wynik;

      for(int i=0; i<wymiar; ++i) {
        Wynik[i] = this->wektor[i]+wektor[i];
      }
      return Wynik;
    }
    
};
  
template<int wymiar>
int Wektor<wymiar>::ilosc=0;

template<int wymiar>
int Wektor<wymiar>::calk_ilosc=0;

/*!
 * \brief Funkcja przeciazajaca wczytanie wektora
 *
 * Argumenty:
 *    Strumien wejscia,
 *    wektor do wypisania.
 * Zwraca:
 *    Strumien wejscia.
 */
template <int wymiar>
inline
std::istream& operator >> (std::istream &stream, const Wektor<wymiar> &wektor)
{
  for(int i=0; i<wymiar; ++i)   stream >> wektor[i];

  return stream;
}

/*!
 * \brief Funkcja przeciazajaca wypisanie wektora
 *
 * Argumenty:
 *    Strumien wyjscia,
 *    wektor do wprowadzenia.
 * Zwraca:
 *    Strumien wyjsica.
 */
template <int wymiar>
inline
std::ostream& operator << (std::ostream &stream, const Wektor<wymiar> &wektor) {
  
  stream << std::setw(16) << std::fixed << std::setprecision(10) << wektor[0]
         << std::setw(16) << std::fixed << std::setprecision(10) << wektor[1]
         << std::setw(16) << std::fixed << std::setprecision(10) << wektor[2]
         << std::endl;
  return stream;
}

#endif
