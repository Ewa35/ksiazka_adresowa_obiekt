# include "KsiazkaAdresowa.h"

int KsiazkaAdresowa :: rejestracjaUzytkownika()
{
    uzytkownikMenedzer.rejestracjaUzytkownika();
    id=uzytkownikMenedzer.idAktualnegoUzytkownika();
    wczytajAdresatowZalogowanegoUzytkownikaZPliku();
    menuUzytkownika();
    return id;
}
int KsiazkaAdresowa ::logowanieUzytkownika()
{

    uzytkownikMenedzer.logowanieUzytkownika();
    id=uzytkownikMenedzer.idAktualnegoUzytkownika();
   if (id==0)
   {
       return 0;
   }
   else
   {
       wczytajAdresatowZalogowanegoUzytkownikaZPliku();
       menuUzytkownika();
       return id;
   }

}
void KsiazkaAdresowa ::wczytajAdresatowZalogowanegoUzytkownikaZPliku()
{
    adresatMenedzer.wczytajAdresatowZalogowanegoUzytkownikaZPliku(id);
}
void KsiazkaAdresowa ::menuUzytkownika()
{
    char wybor;
while (id>0)
{
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
    cin>>wybor;
    switch(wybor)
{
case '1':
        adresatMenedzer.dodajAdresata(id);
        break;
case '2':
        adresatMenedzer.wyswietlWszystkichAdresatow();
        break;
case '7':
        uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
        break;
case '8':
        id=0;

}
}
}
void KsiazkaAdresowa :: wypiszWszystkichUzytkownikow()
{
    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();

}

