// ============================================================================
// ================ GLÓWNA FUNKCJA MAIN - INTERFEJS UŻYTKOWNIKA ===============
// ============================================================================
#include <iostream>
#include <list>
#include <string>
#include <cmath>
#include "komiwojazer.h"
#include "komiwojazer.cpp" // !sam plik .h w VSCode generuje błąd!
using namespace std;

int main() {
  system("chcp 65001");
  system("cls"); // ustaw polskie znaki i wyczysc konsole
  Komiwojazer kw;

  // =============== INTERFEJS UŻYTKOWNIKA - MENU OBSŁUGI LISTY ===============
  while (true) {
    cout << "========== MENU OBSŁUGI TRASY ==========" << endl;
    cout << "Wybierz opcję:" << endl;
    cout << "1. Dodaj przystanek" << endl;
    cout << "2. Usuń przystanek" << std::endl;
    cout << "3. Wyświetl listę trasy" << endl;
    cout << "4. Zakończ program" << endl;
    cout << "========================================" << endl;

    int wybor;
    cout << ">> WYBÓR: " << endl;
    cin >> wybor;

    // ============== INSTRUKCJE WARUNKOWE OBSŁUGUJĄCE INTERFEJS ==============
    if (wybor == 1) {
      int x, y;
      string nazwa;

      cout << "Podaj wartość X: ";
      cin >> x;
      cout << "Podaj wartość Y: ";
      cin >> y;
      cout << "Podaj nazwę przystanku (bez spacji): ";
      cin >> nazwa;

      system("cls");
      kw.dodajPrzystanek(x, y, nazwa);
    } else if (wybor == 2) {
        cout << "Chcesz usunąć przystanek przez podanie (1) wartości X i Y lub (2) nazwy?" << endl;
        int opcja;
        cin >> opcja;
        if (opcja == 1) {
            int x, y;
            cout << "Podaj wartość X: ";
            cin >> x;
            cout << "Podaj wartość Y: ";
            cin >> y;
            kw.usunPrzystanekPoXY(x, y);
        } else if (opcja == 2) {
            string nazwa;
            cout << "Podaj nazwę przystanku: ";
            cin >> nazwa;
            kw.usunPrzystanekPoNazwa(nazwa);
        }
    } else if (wybor == 3) {
        system("cls");
        kw.wyswietlTrase();
    } else if (wybor == 4) {
        break;
    } else {
        cout << "Wybierz opcję od 1 do 4";
    }


  }

  return 0;
}