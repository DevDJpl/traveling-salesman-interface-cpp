// ============================================================================
// ================ GLÓWNA FUNKCJA MAIN - INTERFEJS UŻYTKOWNIKA ===============
// ============================================================================
#include <iostream>
#include <list>
#include <string>
#include <cmath>
#include <fstream>
#include <vector>
#include <algorithm>
#include "komiwojazer.h"
#include "komiwojazer.cpp" // !sam plik .h w VSCode generuje błąd!
using namespace std;

int main(){
  system("chcp 65001");
  system("cls"); // ustaw polskie znaki i wyczysc konsole
  Komiwojazer kw;

  while(true){
    // =============== INTERFEJS UŻYTKOWNIKA - MENU OBSŁUGI LISTY ===============
    cout<<"========== MENU OBSŁUGI TRASY =========="<<endl;
    cout<<"Wybierz opcję:"<<endl;
    cout<<"1. Dodaj przystanek"<<endl;
    cout<<"2. Usuń przystanek"<<endl;
    cout<<"3. Wyświetl listę trasy"<<endl;
    cout<<"4. Zamień przystanki miejscami"<<endl;
    cout<<"5. Sprawdź czy punkt istnieje"<<endl;
    cout<<"6. Wyświetl długość trasy"<<endl;
    cout<<"7. Eksportuj do CSV (Generuj mape)"<<endl;
    cout<<"8. Eksportuj do pliku (.TXT lub .JSON)"<<endl;
    cout<<"9. Zakończ program"<<endl;
    cout<<"========================================"<<endl;

    int wybor;
    cout<<">> WYBÓR: "<<endl;
    cin>>wybor;

    // ============== INSTRUKCJE OBSŁUGUJĄCE INTERFEJS ==============
    switch(wybor){
      case 1:
        {
          int x, y;
          string nazwa;

          cout<<"Podaj wartość X: ";
          cin>>x;
          cout<<"Podaj wartość Y: ";
          cin>>y;
          cout<<"Podaj nazwę przystanku (bez spacji): ";
          cin>>nazwa;

          kw.dodajPrzystanek(x, y, nazwa);
          system("cls");
          cout << "Dodano przystanek: (" << x << "," << y << ") - " << nazwa << endl;
          kw.wyswietlTrase();
        }
        break;
      case 2:
        {
          cout<<"Chcesz usunąć przystanek przez podanie (1) wartości X i Y, czy (2) nazwy?"<<endl;
          int opcja;
          cin>>opcja;
          switch(opcja){
            case 1:
              {
                int x, y;
                cout<<"Podaj wartość X: ";
                cin>>x;
                cout<<"Podaj wartość Y: ";
                cin>>y;
                kw.usunPrzystanekPoXY(x, y);
                system("cls");
                cout << "Usunieto przystanek: (" << x << "," << y << ")" << endl;
                kw.wyswietlTrase();
              }
              break;
            case 2:
              {
                string nazwa;
                cout<<"Podaj nazwę przystanku: ";
                cin>>nazwa;
                kw.usunPrzystanekPoNazwa(nazwa);
                system("cls");
                cout << "Usunieto przystanek: " << nazwa << endl;
                kw.wyswietlTrase();
              }
              break;
            default:
              cout<<"Wybierz opcję 1 lub 2"<<endl;
              break;
          }
        }
        break;
      case 3:
        system("cls");
        kw.wyswietlTrase();
        break;
      case 4:
        {
          cout<<"Chcesz zamienić przystanki miejscami przez podanie (1) wartości X i Y, czy (2) nazwy?"<<endl;
          int opcja;
          cin>>opcja;
          switch(opcja){
          case 1:
            {
              int x1, y1, x2, y2;
              cout<<"Podaj wartość X pierwszego przystanku: ";
              cin>>x1;
              cout<<"Podaj wartość Y pierwszego przystanku: ";
              cin>>y1;
              cout<<"Podaj wartość X drugiego przystanku: ";
              cin>>x2;
              cout<<"Podaj wartość Y drugiego przystanku: ";
              cin>>y2;
              kw.zamienKolejnosciaPoXY(x1, y1, x2, y2);
              system("cls");
              cout << "Zamieniono przystanek: (" << x1 << "," << y1 << ") z przystankiem: (" << x1 << "," << y1 << ")" << endl;
              kw.wyswietlTrase();
            }
            break;
          case 2:
            {
              string nazwa1, nazwa2;
              cout<<"Podaj nazwę pierwszego przystanku: ";
              cin>>nazwa1;
              cout<<"Podaj nazwę drugiego przystanku: ";
              cin>>nazwa2;
              kw.zamienKolejnosciaPoNazwa(nazwa1, nazwa2);
              system("cls");
              cout << "Zamieniono przystanek: (" << nazwa1 << ") z przystankiem: (" << nazwa2 << ")" << endl;
              kw.wyswietlTrase();
            }
            break;
          default:
            cout<<"Wybierz opcję 1 lub 2"<<endl;
            break;
          }
        }
        break;
      case 5:
        {
          cout<<"Chcesz sprawdzić czy przystanek istnieje przez podanie (1) wartości X i Y lub (2) nazwy?"<<endl;
          int opcja;
          cin>>opcja;
          switch(opcja){
            case 1:
              {
                int x, y;
                cout<<"Podaj wartość X: ";
                cin>>x;
                cout<<"Podaj wartość Y: ";
                cin>>y;
                system("cls");
                if(kw.przystanekIstniejePoXY(x, y)){
                    cout<<"Przystanek o podanych wartościach ("<<x<< ","<<y<<") istnieje na liście"<<endl;
                }else{
                    cout<<"Przystanek o podanych wartościach ("<<x<<","<<y<<") nie istnieje na liście"<<endl;
                }
                kw.wyswietlTrase();
              }
              break;
            case 2:
              {
                string nazwa;
                cout<<"Podaj nazwę przystanku: ";
                cin>>nazwa;
                system("cls");
                if(kw.przystanekIstniejePoNazwa(nazwa)){
                    cout<<"Przystanek o podanej nazwie: "<<nazwa<<" istnieje na liście"<<endl;
                }else{
                    cout<<"Przystanek o podanej nazwie: "<<nazwa<<" nie istnieje na liście"<<endl;
                }
                kw.wyswietlTrase();
              }
              break;
            default:
              cout<<"Wybierz opcję 1 lub 2"<<endl;
              break;
          }
        }
        break;
      case 6:
        system("cls");
        cout<<"Długość całej trasy: "<<kw.getDlugoscTrasy()<<endl;
        kw.wyswietlTrase();
        break;
      case 7:
        {
          string nazwaPliku = "trasa_komiwojazera.csv";
          kw.eksportujDoCSV(nazwaPliku);
          system("cls");
          cout << "Wyeksportowano plik: '" << nazwaPliku << "' .CSV do folderu z programem" <<endl;
          kw.wyswietlTrase();
        }
        break;
      case 8:
        {
          cout<<"========== MENU EXPORTOWANIA LISTY =========="<<endl;
          cout<<"Wybierz opcję:"<<endl;
          cout<<"1. JSON"<<endl;
          cout<<"2. TXT"<<endl;
          cout<<"============================================="<<endl;

          int opcja;
          cout<<">> WYBÓR: "<<endl;
          cin>>opcja;
          switch(opcja){
          case 1:
            {
              string nazwaPliku = "trasa_komiwojazera.json";
              kw.eksportujDoJSON(nazwaPliku);
              system("cls");
              cout << "Wyeksportowano plik: '" << nazwaPliku << "' w formacie .JSON do folderu z programem" <<endl;
              kw.wyswietlTrase();
            }
            break;
          case 2:
            {
              string nazwaPliku = "trasa_komiwojazera.txt";
              kw.eksportujDoTXT(nazwaPliku);
              system("cls");
              cout << "Wyeksportowano plik: '" << nazwaPliku << "' w formacie .TXT do folderu z programem" <<endl;
              kw.wyswietlTrase();
            }
            break;
          default:
            system("cls");
            cout<<"Wybierz opcję od 1 do 2";
            kw.wyswietlTrase();
            break;
          }
        }
        break;

      case 9:
        system("cls");
        cout<<"================================================"<<endl;
        cout<<"=============== KONIEC PROGRAMU ================"<<endl;
        cout<<"================================================"<<endl;
        cout<<"= Aby włączyć program od nowa wpisz: 'main.exe'="<<endl;
        cout<<"================================================"<<endl;
        return false;
        break;
      default:
        cout<<"Wybierz opcję od 1 do 9";
        break;
    }
  }

  return 0;
}