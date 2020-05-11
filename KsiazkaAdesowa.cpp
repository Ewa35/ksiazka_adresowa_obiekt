# include "KsiazkaAdresowa.h"

int KsiazkaAdresowa :: rejestracjaUzytkownika()
{
    uzytkownikMenedzer.rejestracjaUzytkownika();
    id=uzytkownikMenedzer.idAktualnegoUzytkownika();
    adresatMenedzer.wczytajAdresatowZalogowanegoUzytkownikaZPliku(id);
    return id;
}
int KsiazkaAdresowa ::logowanieUzytkownika()
{
    uzytkownikMenedzer.logowanieUzytkownika();
    id=uzytkownikMenedzer.idAktualnegoUzytkownika();
   // adresatMenedzer.wczytajAdresatowZalogowanegoUzytkownikaZPliku(id);
   wczytajAdresatowZalogowanegoUzytkownikaZPliku();
    return id;
}
void KsiazkaAdresowa ::wczytajAdresatowZalogowanegoUzytkownikaZPliku()
{
    adresatMenedzer.wczytajAdresatowZalogowanegoUzytkownikaZPliku(id);
}
void KsiazkaAdresowa :: wypiszWszystkichUzytkownikow()
{
    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();

}
void KsiazkaAdresowa :: dodajAdresata()
{
    adresatMenedzer.dodajAdresata(id);
}

void KsiazkaAdresowa :: wyswietlWszystkichAdresatow()
{
    adresatMenedzer.wyswietlWszystkichAdresatow();
}
void KsiazkaAdresowa ::zmianaHaslaZalogowanegoUzytkownika()
{
    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
}
