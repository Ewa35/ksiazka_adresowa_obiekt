#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H
#include <iostream>

#include "UzytkownikMenedzer.h"
#include "AdresatMenedzer.h"
using namespace std;

class KsiazkaAdresowa {
    UzytkownikMenedzer uzytkownikMenedzer;
    AdresatMenedzer adresatMenedzer;
    int id;
public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami,string nazwaPlikuZAdresatami):uzytkownikMenedzer(nazwaPlikuZUzytkownikami),adresatMenedzer(nazwaPlikuZAdresatami) {
        uzytkownikMenedzer.wczytajUzytkownikowZPliku();
    };
    int rejestracjaUzytkownika();
    int logowanieUzytkownika();
    void menuUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void wczytajAdresatowZalogowanegoUzytkownikaZPliku();
};

#endif
