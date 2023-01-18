// ============================================================================
// =================== KLASA KOMIWOJAZERA - PLIK NAGŁÓWKOWY ===================
// ============================================================================

#ifndef KOMIWOJAZER_H
#define KOMIWOJAZER_H

#include <iostream>
#include <list>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

class Komiwojazer {
    struct Przystanek {
      int x, y;
      string nazwa;
      double dystans;
    };
    list<Przystanek> trasa;
    vector<Przystanek> trasa1;
    int maxX, maxY;

    public:
      /**
       * Deklaracja metody dodającej przystanek.
       *
       * @param  int  x
       * @param  int  y
       * @param  string  nazwa
       */
      void dodajPrzystanek(int x, int y, string nazwa); 

      /**
       * Deklaracja metody wyświetlającej trase.
       *
       * @return trasa
       */
      void wyswietlTrase();

      /**
       * Deklaracja metody usuwającej przystanek po współrzędnych.
       *
       * @param  int  x
       * @param  int  y
       */
      void usunPrzystanekPoXY(int x, int y);

      /**
       * Deklaracja metody usuwającej przystanek po nazwie.
       *
       * @param  string  nazwa
       */
      void usunPrzystanekPoNazwa(string nazwa);

      /**
       * Deklaracja metody, która zmienia kolejność przystanków po współrzędnych.
       *
       * @param  int  x1
       * @param  int  y1
       * @param  int  x2
       * @param  int  y2
       */
      void zamienKolejnosciaPoXY(int x1, int y1, int x2, int y2);

      /**
       * Deklaracja metody, która zmienia kolejność przystanków po ich nazwie.
       *
       * @param  string  nazwa1
       * @param  string  nazwa2
       */
      void zamienKolejnosciaPoNazwa(string nazwa1, string nazwa2);

      /**
       * Deklaracja metody sprawdzającej czy istnienie przystanek po współrzędnych.
       *
       * @param  int  x
       * @param  int  y
       * @return bool
       */
      bool przystanekIstniejePoXY(int x, int y);

      /**
       * Deklaracja metody sprawdzającej czy istnienie przystanek po nazwie.
       *
       * @param  string  nazwa
       * @return bool
       */
      bool przystanekIstniejePoNazwa(string nazwa);

      /**
       * Deklaracja metody sprawdzającej długość trasy.
       *
       * @return długość trasy
       */
      double getDlugoscTrasy();

      /**
       * Deklaracja metody ustawiającej maksymalną wartość x i y.
       *
       * @param  int  x
       * @param  int  y
       * @param  string  nazwa
       * @return output
       */
      void setMaxXMaxY();

      /**
       * Deklaracja metody eksportującej trasę do excela.
       *
       * @param  string  nazwaPliku
       */
      void eksportujDoCSV(const string& nazwaPliku);

      /**
       * Deklaracja metody eksportującej trasę do pliku json.
       *
       * @param  string  nazwaPliku
       */
      void eksportujDoJSON(const string& nazwaPliku);

      /**
       * Deklaracja metody eksportującej trasę do pliku txt.
       *
       * @param  string  nazwaPliku
       */
      void eksportujDoTXT(const string& nazwaPliku);

      /**
       * Deklaracja metody importującej trasę z pliku json.
       *
       * @param  string  nazwaPliku
       */
      void importujJSON(const string& nazwaPliku);
};

#endif