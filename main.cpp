#include <iostream>
#include "KsiazkaAdresowa.h"
using namespace std;

int main()
{

    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "PlikZAdresatami.txt");
    char wybor;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    cin>>wybor;
    switch (wybor)
    {
case '1':
    ksiazkaAdresowa.rejestracjaUzytkownika();
    break;
case '2':
    ksiazkaAdresowa.logowanieUzytkownika();
    break;
    }
ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
ksiazkaAdresowa.wyswietlWszystkichAdresatow();
   /* ksiazkaAdresowa.dodajAdresata();
    ksiazkaAdresowa.dodajAdresata();
    ksiazkaAdresowa.wyswietlWszystkichAdresatow();
    ksiazkaAdresowa.rejestracjaUzytkownika();
    ksiazkaAdresowa.dodajAdresata();
    ksiazkaAdresowa.dodajAdresata();
    ksiazkaAdresowa.wyswietlWszystkichAdresatow();

    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();*/



    return 0;
}
