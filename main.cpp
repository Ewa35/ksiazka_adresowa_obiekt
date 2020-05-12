#include <iostream>
#include <cstdlib>
#include "KsiazkaAdresowa.h"
using namespace std;

int main() {

    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "PlikZAdresatami.txt");
    char wybor;
    while(true) {
        system("cls");
        cout << "    >>> MENU  GLOWNE <<<" << endl;
        cout << "---------------------------" << endl;
        cout << "1. Rejestracja" << endl;
        cout << "2. Logowanie" << endl;
        cout << "9. Koniec programu" << endl;
        cout << "---------------------------" << endl;
        cout << "Twoj wybor: ";
        cin>>wybor;
        switch (wybor) {
        case '1':
            ksiazkaAdresowa.rejestracjaUzytkownika();
            break;
        case '2':
            ksiazkaAdresowa.logowanieUzytkownika();
            break;

        case '9':
            exit(0);
            break;
        }
    }




    return 0;
}
