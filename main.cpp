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
    cout<<"7. Eksportuj do CSV (Utwórz macierz)"<<endl;
    cout<<"8. Eksportuj do pliku"<<endl;
    cout<<"9. Importuj z pliku"<<endl;
    cout<<"10. Zakończ program"<<endl;
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

          system("cls");
          kw.dodajPrzystanek(x, y, nazwa);
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
              }
              break;
            case 2:
              {
                string nazwa;
                cout<<"Podaj nazwę przystanku: ";
                cin>>nazwa;
                kw.usunPrzystanekPoNazwa(nazwa);
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
          cout<<"Chcesz zamienić purzystanki miejscami przez podanie (1) wartości X i Y, czy (2) nazwy?"<<endl;
          int opcja;
          cin>>opcja;
          switch(opcja){
          case 1:
            {
              int x1, y1, x2, y2;
              cout<<"Podaj wartość X pierwszego punktu: ";
              cin>>x1;
              cout<<"Podaj wartość Y pierwszego punktu: ";
              cin>>y1;
              cout<<"Podaj wartość X drugiego punktu: ";
              cin>>x2;
              cout<<"Podaj wartość Y drugiego punktu: ";
              cin>>y2;
              kw.zamienKolejnosciaPoXY(x1, y1, x2, y2);
            }
            break;
          case 2:
            {
              string nazwa1, nazwa2;
              cout<<"Podaj nazwę pierwszego punktu: ";
              cin>>nazwa1;
              cout<<"Podaj nazwę drugiego punktu: ";
              cin>>nazwa2;
              kw.zamienKolejnosciaPoNazwa(nazwa1, nazwa2);
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
                if(kw.przystanekIstniejePoXY(x, y)){
                    cout<<"Przystanek o podanych wartościach ("<<x<< ","<<y<<") istnieje na liście"<<endl;
                }else{
                    cout<<"Przystanek o podanych wartościach ("<<x<<","<<y<<") nie istnieje na liście"<<endl;
                }
              }
              break;
            case 2:
              {
                string nazwa;
                cout<<"Podaj nazwę przystanku: ";
                cin>>nazwa;
                if(kw.przystanekIstniejePoNazwa(nazwa)){
                    cout<<"Przystanek o podanej nazwie: "<<nazwa<<" istnieje na liście"<<endl;
                }else{
                    cout<<"Przystanek o podanej nazwie: "<<nazwa<<" nie istnieje na liście"<<endl;
                }
              }
              break;
            default:
              cout<<"Wybierz opcję 1 lub 2"<<endl;
              break;
          }
        }
        break;
      case 6:
        cout<<"Długość całej trasy: "<<kw.getDlugoscTrasy()<<endl;
        break;
      case 7:
        {
          string nazwaPliku = "trasa_komiwojazera.csv";
          kw.eksportujDoCSV(nazwaPliku);
        }
        break;
      case 8:
        {
          cout<<"========== MENU EXPORTOWANIA =========="<<endl;
          cout<<"Wybierz opcję:"<<endl;
          cout<<"1. JSON"<<endl;
          cout<<"2. TXT"<<endl;
          cout<<"========================================"<<endl;

          int opcja;
          cout<<">> WYBÓR: "<<endl;
          cin>>opcja;
          switch(opcja){
          case 1:
            {
              string nazwaPliku = "trasa_komiwojazera.json";
              //kw.eksportujDoJSON(nazwaPliku);
            }
            break;
          case 2:
            {
              string nazwaPliku = "trasa_komiwojazera.txt";
              kw.eksportujDoTXT(nazwaPliku);
            }
            break;
          default:
            cout<<"Wybierz opcję od 1 do 2";
            break;
          }
        }
        break;
      /*
      case 9:
        {
          cout<<"========== MENU IMPORTOWANIA =========="<<endl;
          cout<<"Wybierz opcję:"<<endl;
          cout<<"1. CSV"<<endl;
          cout<<"2. JSON"<<endl;
          cout<<"3. TXT"<<endl;
          cout<<"========================================"<<endl;

          int opcja;
          cout<<">> WYBÓR: "<<endl;
          cin>>opcja;
          switch(opcja){
          case 1:
            {
              string nazwaPliku = "trasa_komiwojazera.csv";
              //kw.importujCSV(nazwaPliku);
            }
            break;
          case 2:
            {
              string nazwaPliku = "trasa_komiwojazera.json";
              //kw.importujJSON(nazwaPliku);
            }
            break;
          case 3:
            {
              string nazwaPliku = "trasa_komiwojazera.txt";
              //kw.importujTXT(nazwaPliku);
            }
            break;
          default:
            cout<<"Wybierz opcję od 1 do 3";
            break;
          }
        }
        break;
      */
      case 10:

        break;
      default:
        cout<<"Wybierz opcję od 1 do 10";
        break;
    }
  }
  /*
  while(true){
    int wybor;
    cout << ">> WYBÓR: " << endl;
    cin >> wybor;

    // ============== INSTRUKCJE WARUNKOWE OBSŁUGUJĄCE INTERFEJS ==============
    if (wybor == 1) {

    } else if (wybor == 2) {
    } else if (wybor == 3) {
    } else if (wybor == 4) {
    } else if (wybor == 5) {
    } else if (wybor == 6) {
    } else if (wybor == 7) {
    }  else if (wybor == 8) {
        break;
    } else {
        cout << "Wybierz opcję od 1 do 4";
    }

  }
  */

  return 0;
}