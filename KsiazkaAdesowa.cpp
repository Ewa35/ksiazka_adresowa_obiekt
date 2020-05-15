# include "KsiazkaAdresowa.h"


char KsiazkaAdresowa ::wybierzOpcjeZMenuGlownego()
{
    char wybor;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = MetodyPomocnicze::wczytajZnak();

    return wybor;
}
char KsiazkaAdresowa ::wybierzOpcjeZMenuUzytkownika()
{
    char wybor;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj adresata" << endl;
    cout << "2. Wyswietl adresatow" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Zmien haslo" << endl;
    cout << "8. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = MetodyPomocnicze::wczytajZnak();

    return wybor;
}

void KsiazkaAdresowa :: rejestracjaUzytkownika() {
    uzytkownikMenedzer.rejestracjaUzytkownika();


}
void KsiazkaAdresowa ::logowanieUzytkownika() {

    uzytkownikMenedzer.logowanieUzytkownika();
    if (uzytkownikMenedzer.idAktualnegoUzytkownika()>0)
    {
        adresatMenedzer= new AdresatMenedzer (NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikMenedzer.idAktualnegoUzytkownika());
    }

}

void KsiazkaAdresowa ::dodajAdresata()
{
  adresatMenedzer->dodajAdresata();
}
void KsiazkaAdresowa ::wyswietlWszystkichAdresatow()
{
    adresatMenedzer->wyswietlWszystkichAdresatow();
}
void KsiazkaAdresowa ::zmianaHaslaZalogowanegoUzytkownika()
{
    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa :: wypiszWszystkichUzytkownikow() {
    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();

}

void KsiazkaAdresowa ::wylogujUzytkownika()
{
    uzytkownikMenedzer.wylogujUzytkownika();
    delete adresatMenedzer;
    adresatMenedzer=NULL;
}
bool KsiazkaAdresowa ::czyUzytkownikJestZalogowany()
{
   if( uzytkownikMenedzer.czyUzytkownikJestZalogowany())
    return true;
   else
    return false;
}
int KsiazkaAdresowa ::idAktualnegoUzytkownika()
{
    int id=uzytkownikMenedzer.idAktualnegoUzytkownika();
    return id;
}
