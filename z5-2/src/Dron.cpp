#include "Dron.hh"
Dron::Dron() {
    suma_katow=0;
    wszystkie_wektory=0;
    aktualne_wektory=0;
    Lacze.DodajNazwePliku(NAZWA_PLIKU__PROSTOPADLOSCIAN);
    Lacze.DodajNazwePliku(NAZWA_PLIKU__GRANIATOSLUP_1);
    Lacze.DodajNazwePliku(NAZWA_PLIKU__GRANIATOSLUP_2);
    Lacze.DodajNazwePliku(NAZWA_PLIKU__GRANIATOSLUP_3);
    Lacze.DodajNazwePliku(NAZWA_PLIKU__GRANIATOSLUP_4);
    Lacze.ZmienTrybRys(PzG::TR_3D);
    Lacze.Inicjalizuj();  // Tutaj startuje gnuplot.
    Lacze.UstawZakresX(-90, 90);
    Lacze.UstawZakresY(-60, 150);
    Lacze.UstawZakresZ(-20, 90);
    Lacze.UstawRotacjeXZ(64,65); // Tutaj ustawiany jest widok
    ZapiszDrona(0,0,0,0);
}


bool Dron::ruch() {

    Lacze.Rysuj();
    char opcja;
    aktualne_wektory=0;
    
    for ( int j=0; j<4 ;j++ )
        aktualne_wektory+=Gr[j].get_size();
    aktualne_wektory+=Pr.get_size();

    cout << "Obiekty Wektora3D " << aktualne_wektory << endl;
    cout << "Wszystkie obiekty Wektora3D " << wszystkie_wektory << endl;
    cout << "Podaj opcje r- ruch o-obrot k - koniec" << endl;
    cin >> opcja;
  
    if(opcja=='r') {
        cout << "! Podaj kat wznoszenia" << endl;
        cin >> kat;
        cout << "! Podaj droge" << endl;
        cin >> droga;
        
        Wek[0]=1*cos(kat*M_PI/180);
        Wek[1]=0;
        Wek[2]=1*sin(kat*M_PI/180);
        
        M_drogi.set_kat(suma_katow);
        M_drogi = obrot_z(M_drogi);
        Wek=M_drogi*Wek;
        
        for ( int i=0; i<droga; i++ ) {
            Pr.zamien_srodek ( (Pr.zwroc_srodek()+Wek));
            for ( int i=0; i<Pr.get_size(); i++ )
                Pr[i]=Pr[i]+Wek;
            for ( int i=0; i<4; i++ )
                for ( int j=0; j<Gr[i].get_size(); j++ )
            Gr[i][j]=Gr[i][j]+Wek;
            
            //rotacje wirnikow
            for ( int i=0; i<4; i++ ) {
                M_wirniki.set_kat(10);
                M_wirniki.srodek(Gr[i][0]);
                M_wirniki = obrot_z(M_wirniki);
                for ( int j=0; j<Gr[i].get_size(); j++ )
                    Gr[i][j]=M_wirniki*Gr[i][j];
                }
            
        usleep(50000);
        zapisz();
        Lacze.Rysuj();
         
        for(int j=0; j<4; j++)
            wszystkie_wektory+=Gr[j].get_size();
        wszystkie_wektory+=Pr.get_size();
     }
  }

  else if (opcja=='o') {
      cin >> kat;
      suma_katow+=kat;
      M.set_kat(1);
      M.srodek(Pr.zwroc_srodek());
        for(int i=0; i<kat; i++) {
                M = obrot_z(M);
                for(int i=0; i<Pr.get_size(); i++)
                    Pr[i]=M*Pr[i];
                for(int i=0; i<4; i++)
                for(int j=0; j<Gr[i].get_size(); j++)
                    Gr[i][j]=M*Gr[i][j];
    
                //rotacje wirnikow
                for(int i=0; i<4; i++) {
                    M_wirniki.set_kat(10);
                    M_wirniki.srodek(Gr[i][0]);
                    M_wirniki = obrot_z(M_wirniki);
                    for ( int j=0; j<Gr[i].get_size(); j++ )
                        Gr[i][j]=M_wirniki*Gr[i][j];
                    
                }
                usleep(50000);
                zapisz();
                Lacze.Rysuj();
            
                for(int j=0; j<4; j++)
                    wszystkie_wektory+=Gr[j].get_size();
                wszystkie_wektory+=Pr.get_size();
              }

  }
else if(opcja=='k') {
      return false;
  }
return true;
}


void Dron::zapisz() {
    ofstream korpus(NAZWA_PLIKU__PROSTOPADLOSCIAN);
    korpus<<Pr;
    
    ofstream wirnik1(NAZWA_PLIKU__GRANIATOSLUP_1);
    wirnik1<<Gr[0];
    wirnik1.close();
    ofstream wirnik2(NAZWA_PLIKU__GRANIATOSLUP_2);
    wirnik2<<Gr[1];
    wirnik2.close();
    ofstream wirnik3(NAZWA_PLIKU__GRANIATOSLUP_3);
    wirnik3<<Gr[2];
    wirnik3.close();
    ofstream wirnik4(NAZWA_PLIKU__GRANIATOSLUP_4);
    wirnik4<<Gr[3];
    wirnik4.close();
}

bool Dron::ZapiszDrona( double Kat_st = 0, double x_trans = 0, double y_trans = 0,double z_trans = 0) {
    Pr.StworzProstopadloscian(x_trans,y_trans,z_trans);
    Gr[0].StworzGraniastoslup( Kat_st,x_trans+PROSTOKAT_X, PROSTOKAT_Y,z_trans);
    Gr[1].StworzGraniastoslup(-Kat_st,x_trans-PROSTOKAT_X, PROSTOKAT_Y,z_trans);
    Gr[2].StworzGraniastoslup( Kat_st,x_trans-PROSTOKAT_X,-PROSTOKAT_Y,z_trans);
    Gr[3].StworzGraniastoslup(-Kat_st,x_trans+PROSTOKAT_X,-PROSTOKAT_Y,z_trans );
    zapisz();
return true;
}
