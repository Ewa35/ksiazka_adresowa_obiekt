#include <iostream>
#include <cstdlib>
#include "KsiazkaAdresowa.h"
using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "PlikZAdresatami.txt");

    char wybor;
        while (true)
    {
        if (ksiazkaAdresowa.czyUzytkownikJestZalogowany()==false)
        {
            wybor = ksiazkaAdresowa.wybierzOpcjeZMenuGlownego();

            switch (wybor)
            {
            case '1':
                ksiazkaAdresowa.rejestracjaUzytkownika();
                break;
            case '2':
                ksiazkaAdresowa.logowanieUzytkownika();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }

       else
        {
            if (ksiazkaAdresowa.czyUzytkownikJestZalogowany())
            {
                wybor = ksiazkaAdresowa.wybierzOpcjeZMenuUzytkownika();

                switch (wybor)
                {
                case '1':
                    ksiazkaAdresowa.dodajAdresata();
                    break;
                case '2':
                    ksiazkaAdresowa.wyswietlWszystkichAdresatow();
                    break;
                case '3':
                    ksiazkaAdresowa.wyszukajAdresatowPoImieniu();
                    break;
                case '4':
                    ksiazkaAdresowa.wyszukajAdresatowPoNazwisku();
                    break;
                case '5':
                    ksiazkaAdresowa.usunAdresata();
                    break;
                case '6':
                    ksiazkaAdresowa.edytujAdresata();
                    break;
                case '7':
                    ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
                    break;
                case '8':
                    ksiazkaAdresowa.wylogujUzytkownika();
                    break;

            }
            }
        }

    }
    return 0;
}







