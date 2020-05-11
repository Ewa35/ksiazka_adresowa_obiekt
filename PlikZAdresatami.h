#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <sstream>

#include"Adresat.h"
#include"MetodyPomocnicze.h"
using namespace std;

class PlikZAdresatami
{
    string nazwaPlikuZAdresatami;

    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    string pobierzLiczbe(string tekst, int pozycjaZnaku);
    int konwersjaStringNaInt(string liczba);
    bool czyPlikJestPusty(fstream &plikTekstowy);
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    void wyswietlDaneAdresata(Adresat adresat);

public:
    PlikZAdresatami (string NAZWAPLIKUZADRESATAMI): nazwaPlikuZAdresatami(NAZWAPLIKUZADRESATAMI){};
   int wczytajAdresatowZalogowanegoUzytkownikaZPliku(vector <Adresat> &adresaci, int id);
   void dopiszAdresataDoPliku(Adresat adresat);


};
#endif
