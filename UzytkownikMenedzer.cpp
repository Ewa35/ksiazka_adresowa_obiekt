#include "UzytkownikMenedzer.h"

void UzytkownikMenedzer :: rejestracjaUzytkownika () {
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);

    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);
    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

Uzytkownik UzytkownikMenedzer :: podajDaneNowegoUzytkownika() {
    Uzytkownik uzytkownik;
    uzytkownik.ustawId(pobierzIdNowegoUzytkownika());
    string login;
    do {
        cout << "Podaj login: ";
        cin>>login;
        uzytkownik.ustawLogin(login);
    } while (czyIstniejeLogin( uzytkownik.pobierzLogin()) == true);

    string haslo;
    cout << "Podaj haslo: ";
    cin>>haslo;
    uzytkownik.ustawHaslo(haslo);

    return uzytkownik;
}

int UzytkownikMenedzer :: pobierzIdNowegoUzytkownika() {
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzId() + 1;
}

bool UzytkownikMenedzer :: czyIstniejeLogin( string login) {

    for (int i=0; i<uzytkownicy.size(); i++) {
        if (uzytkownicy[i].pobierzLogin()==login) {
            cout<<endl<<"Istnieje uzytkownik o takim loginie" <<endl;
            return true;
        }
    }
    return false;
}

void UzytkownikMenedzer ::wypiszWszystkichUzytkownikow() {
    for (int i=0; i<uzytkownicy.size(); i++) {

        cout<< uzytkownicy[i].pobierzId() <<endl;
        cout<< uzytkownicy[i].pobierzLogin() <<endl;
        cout<< uzytkownicy[i].pobierzHaslo() <<endl;

    }
}
int UzytkownikMenedzer ::idAktualnegoUzytkownika() {
    return idZalogowanegoUzytkownika;
}
void UzytkownikMenedzer ::logowanieUzytkownika() {
    Uzytkownik uzytkownik;
    int iloscUzytkownikow=0;
    string loginUzytkownika = "", hasloUzytkownika = "";

    cout << endl << "Podaj login: ";
    loginUzytkownika = MetodyPomocnicze::wczytajLinie();

    for (int i=0; i<uzytkownicy.size(); i++) {
        if (uzytkownicy[i].pobierzLogin() == loginUzytkownika) {
                iloscUzytkownikow++;
            for (int iloscProb = 3; iloscProb > 0; iloscProb--) {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                hasloUzytkownika= MetodyPomocnicze::wczytajLinie();

                if (uzytkownicy[i].pobierzHaslo() == hasloUzytkownika) {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    idZalogowanegoUzytkownika=uzytkownicy[i].pobierzId();
                    system("pause");
                    iloscProb=0;
                }
                else if (iloscProb==0 && idZalogowanegoUzytkownika==0) {
                    cout << "Wprowadzono 3 razy bledne haslo." << endl;
                    system("pause");
                    idZalogowanegoUzytkownika=0;
                }
            }
        }
    }
    if (iloscUzytkownikow==0)
            {
                cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
                system("pause");
            }

}
    void UzytkownikMenedzer ::zmianaHaslaZalogowanegoUzytkownika() {
        string noweHaslo = "";
        cout << "Podaj nowe haslo: ";
        noweHaslo = MetodyPomocnicze::wczytajLinie();

        for (int i=0; i<uzytkownicy.size(); i++) {
            if (uzytkownicy[i].pobierzId() == idZalogowanegoUzytkownika) {
                uzytkownicy[i].ustawHaslo(noweHaslo);
                cout << "Haslo zostalo zmienione." << endl << endl;
                system("pause");
            }
        }
        plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
    }
    bool UzytkownikMenedzer::czyUzytkownikJestZalogowany() {
        if (idZalogowanegoUzytkownika>0)
            return true;
        else
            return false;
    }
    void UzytkownikMenedzer::wylogujUzytkownika() {
        idZalogowanegoUzytkownika=0;
    }
