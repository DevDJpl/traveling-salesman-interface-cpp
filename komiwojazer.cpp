// ============================================================================
// ==================== KLASA KOMIWOJAZERA - METODY KLASY =====================
// ============================================================================

#include <iostream>
#include <string> 
#include <list>
#include <cmath>
#include "komiwojazer.h"

using namespace std;

// ====== DODAJ "PRZYSTANEK" NA TRASIE POPRZEZ PODANIE KOORDYNATÓW I NAZWY (NP.: MIASTA) ======
void Komiwojazer::dodajPrzystanek(int x, int y, string nazwa) {
    if (x < 0 || y < 0) {
        cout << "Wartości X i Y nie mogą być ujemne!" << endl;
        return;
    }

    Przystanek nowyPrzystanek = {x, y, nazwa, 0};
    if (trasa.size() > 0) {
        Przystanek poprzedniPrzystanek = trasa.back();
        nowyPrzystanek.dystans = sqrt(pow(x - poprzedniPrzystanek.x, 2) + pow(y - poprzedniPrzystanek.y, 2));
    }
    trasa.push_back(nowyPrzystanek);
}

// =========== WYŚWIETL TRASĘ "KOMIWOJAŻERA" WSZYSTKICH PRZYSTANKÓW Z KOORDYNATAMI ===========
void Komiwojazer::wyswietlTrase() {
  for (auto przystanek : trasa) {
      cout << przystanek.nazwa << ": (" << przystanek.x << ", " << przystanek.y << ")" << endl;
  }
}