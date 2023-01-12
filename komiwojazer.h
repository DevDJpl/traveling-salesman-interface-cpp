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
      // ========= DEKLARACJA METODY USUWAJĄCEJ PRZYSTANEK PO KOORDYNATACH ==========
      void usunPrzystanekPoXY(int x, int y);
      // ========= DEKLARACJA METODY USUWAJĄCEJ PRZYSTANEK PO JEGO NAZWIE ===========
      void usunPrzystanekPoNazwa(string nazwa);
      // ======== DEKLARACJA METODY ZAMIENIAJĄCEJ PRZYSTANKI PO KOORDYNATACH ========
      void zamienKolejnosciaPoXY(int x1, int y1, int x2, int y2);
      // ========= DEKLARACJA METODY ZAMIENIAJĄCEJ PRZYSTANKI PO ICH NAZWIE =========
      void zamienKolejnosciaPoNazwa(string nazwa1, string nazwa2);
      // === DEKLARACJA METODY SPRAWDZAJĄCEJ ISTNIENIE PRZYSTANKU PO KOORDYNATACH ===
      bool przystanekIstniejePoXY(int x, int y);
      // ====== DEKLARACJA METODY SPRAWDZAJĄCEJ ISTNIENIE PRZYSTANKU PO NAZWIE ======
      bool przystanekIstniejePoNazwa(string nazwa);
      // ============== DEKLARACJA METODY SPRAWDZAJĄCEJ DŁUGOŚĆ TRASY ===============
      double getDlugoscTrasy();
};

#endif