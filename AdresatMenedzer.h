#ifndef ADRESATMENEDZER_H
#define ADRESATMENEDZER_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <algorithm>
#include <sstream>

#include "Adresat.h"
//#include "PlikZAdresatami.h"

using namespace std;

class AdresatMenedzer
{

    int idOstatniegoAdresata;
    vector <Adresat> adresaci;

     Adresat podajDaneNowegoAdresata();
    string wczytajLinie();
    string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    void wyswietlDaneAdresata(Adresat adresat);

 public:


     int dodajAdresata ();
    void wyswietlWszystkichAdresatow();

};

#endif
