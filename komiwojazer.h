// ============================================================================
// =================== KLASA KOMIWOJAZERA - PLIK NAGŁÓWKOWY ===================
// ============================================================================

#ifndef KOMIWOJAZER_H
#define KOMIWOJAZER_H

#include <iostream>
#include <list>
#include <string>
#include <cmath>

using namespace std;

class Komiwojazer {
    struct Przystanek {
      int x, y;
      string nazwa;
      double dystans;
    };
    list<Przystanek> trasa;

    public:
      // ================== DEKLARACJA METODY DODAJĄCEJ PRZYSTANEK ==================
      void dodajPrzystanek(int x, int y, string nazwa); 
      // ================== DEKLARACJA METODY DODAJĄCEJ PRZYSTANEK ==================
      void wyswietlTrase();

};

#endif