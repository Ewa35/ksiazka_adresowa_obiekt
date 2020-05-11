#include "UzytkownikMenedzer.h"

int UzytkownikMenedzer :: rejestracjaUzytkownika ()
{
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);

    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);
    idZalogowanegoUzytkownika=uzytkownik.pobierzId();
    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
    return idZalogowanegoUzytkownika;
}

Uzytkownik UzytkownikMenedzer :: podajDaneNowegoUzytkownika()
{
    Uzytkownik uzytkownik;
    uzytkownik.ustawId(pobierzIdNowegoUzytkownika());
    string login;
    do
    {
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

int UzytkownikMenedzer :: pobierzIdNowegoUzytkownika()
{
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzId() + 1;
}

bool UzytkownikMenedzer :: czyIstniejeLogin( string login)
{

   for (int i=0; i<uzytkownicy.size(); i++)
   {
       if (uzytkownicy[i].pobierzLogin()==login)
       {
           cout<<endl<<"Istnieje uzytkownik o takim loginie" <<endl;
           return true;
       }
   }
  return false;
}

void UzytkownikMenedzer ::wypiszWszystkichUzytkownikow()
{
    for (int i=0; i<uzytkownicy.size(); i++)
   {

            cout<< uzytkownicy[i].pobierzId() <<endl;
            cout<< uzytkownicy[i].pobierzLogin() <<endl;
            cout<< uzytkownicy[i].pobierzHaslo() <<endl;

   }
}

void UzytkownikMenedzer :: wczytajUzytkownikowZPliku()
{
    uzytkownicy=plikZUzytkownikami.wczytajUzytkownikowZPliku();
}
int UzytkownikMenedzer ::idAktualnegoUzytkownika()
{
    return idZalogowanegoUzytkownika;
}
int UzytkownikMenedzer ::logowanieUzytkownika()
{
    Uzytkownik uzytkownik;
    string loginUzytkownika = "", hasloUzytkownika = "";

    cout << endl << "Podaj login: ";
    loginUzytkownika = wczytajLinie();

    for (int i=0; i<uzytkownicy.size(); i++)
    {
        if (uzytkownicy[i].pobierzLogin() == loginUzytkownika)
        {
            for (int iloscProb = 3; iloscProb > 0; iloscProb--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                hasloUzytkownika= wczytajLinie();

                if (uzytkownicy[i].pobierzHaslo() == hasloUzytkownika)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    idZalogowanegoUzytkownika=uzytkownicy[i].pobierzId();
                    system("pause");
                    return idZalogowanegoUzytkownika;
                }
            }

            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return 0;
        }
    }

    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;

    system("pause");
    return 0;
}
string UzytkownikMenedzer ::wczytajLinie()
{
    cin.sync();
    string wejscie = "";
    getline(cin, wejscie);
    return wejscie;
}
void UzytkownikMenedzer ::zmianaHaslaZalogowanegoUzytkownika()
{
    string noweHaslo = "";
    cout << "Podaj nowe haslo: ";
    noweHaslo = wczytajLinie();

    for (int i=0; i<uzytkownicy.size(); i++)
    {
        if (uzytkownicy[i].pobierzId() == idZalogowanegoUzytkownika)
        {
            uzytkownicy[i].ustawHaslo(noweHaslo);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
}
