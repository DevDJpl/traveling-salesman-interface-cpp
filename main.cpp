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
    cout << "1. Dodaj punkt" << endl;
    cout << "2. Wyświetl listę trasy" << endl;
    cout << "3. Zakończ program" << endl;
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
      cout << "Podaj nazwę punktu: ";
      cin >> nazwa;

      system("cls");
      kw.dodajPrzystanek(x, y, nazwa);
    } else if (wybor == 2) {
        system("cls");
        kw.wyswietlTrase();
    } else if (wybor == 3) {
        break;
    } else {
      cout << "Wybierz opcję od 1 do 3";
    }


  }

  return 0;
}