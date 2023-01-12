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
    cout << "========== TRASA KOMIWOJAZERA ==========" << endl;
    int lp = 1;
    for (auto przystanek : trasa) {
        cout << "[" << lp << "] " << przystanek.nazwa << ": (" << przystanek.x << ", " << przystanek.y << ")" << endl;
        lp++;
    }
}

// =========== USUŃ PRZYSTANEK Z LISTY KOMIWOJAŻERA PRZEZ PODANIE KOORDYNATÓW X I Y ===========
void Komiwojazer::usunPrzystanekPoXY(int x, int y) {
    for (auto item = trasa.begin(); item != trasa.end(); item++) {
        if (item->x == x && item->y == y) {
            trasa.erase(item);
            break;
        }
    }
}

// ============== USUŃ PRZYSTANEK Z LISTY KOMIWOJAŻERA PRZEZ PODANIE JEGO NAZWY ===============
void Komiwojazer::usunPrzystanekPoNazwa(std::string nazwa) {
    for (auto item = trasa.begin(); item != trasa.end(); item++) {
        if (item->nazwa == nazwa) {
            trasa.erase(item);
            break;
        } 
    }
}

// ================ ZAMIEŃ PRZYSTANKI MIEJSCAMI PRZEZ PODANIE ICH KOORDYNATÓW =================
void Komiwojazer::zamienKolejnosciaPoXY(int x1, int y1, int x2, int y2) {
    auto item1 = trasa.end(), item2 = trasa.end();
    for (auto item = trasa.begin(); item != trasa.end(); item++) {
        if (item->x == x1 && item->y == y1) {
            item1 = item;
        } else if (item->x == x2 && item->y == y2) {
            item2 = item;
        }
    }

    if (item1 != trasa.end() && item2 != trasa.end()) {
        iter_swap(item1, item2);
    }
}

// =================== ZAMIEŃ PRZYSTANKI MIEJSCAMI PRZEZ PODANIE ICH NAZWA ===================
void Komiwojazer::zamienKolejnosciaPoNazwa(string nazwa1, string nazwa2) {
    auto item1 = trasa.end(), item2 = trasa.end();
    for (auto it = trasa.begin(); it != trasa.end(); it++) {
        if (it->nazwa == nazwa1) {
            item1 = it;
        } else if (it->nazwa == nazwa2) {
            item2 = it;
        }
    }

    if (item1 != trasa.end() && item2 != trasa.end()) {
        iter_swap(item1, item2);
    }
}

// ============ SPRAWDŹ CZY PRZYSTANEK ISTNIEJE PRZEZ PODANIE JEGO KOORDYNATÓW ==============
bool Komiwojazer::przystanekIstniejePoXY(int x, int y) {
    for (auto przystanek : trasa) {
        if (przystanek.x == x && przystanek.y == y) {
            return true;
        }
    }
    return false;
}

// =============== SPRAWDŹ CZY PRZYSTANEK ISTNIEJE PRZEZ PODANIE JEGO NAZWY =================
bool Komiwojazer::przystanekIstniejePoNazwa(string nazwa) {
    for (auto przystanek : trasa) {
        if (przystanek.nazwa == nazwa) {
            return true;
        }
    }
    return false;
}