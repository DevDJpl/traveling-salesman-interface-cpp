// ============================================================================
// ==================== KLASA KOMIWOJAZERA - METODY KLASY =====================
// ============================================================================

#include <iostream>
#include <string> 
#include <list>
#include <cmath>
#include <fstream>
#include <vector>
#include <algorithm>
#include "komiwojazer.h"

using namespace std;

/**
 * Funkcja dodająca "Przystanek" na trasie poprzez podanie koordynatów i nazwy.
 *
 * @param  int  x
 * @param  int  y
 * @return string nazwa
 */
void Komiwojazer::dodajPrzystanek(int x, int y, string nazwa){
    if(x < 0 || y < 0){
        cout<<"Wartości X i Y nie mogą być ujemne!"<<endl;
        return;
    }

    Przystanek nowyPrzystanek = {x, y, nazwa, 0};
    if(trasa.size() > 0){
        Przystanek poprzedniPrzystanek = trasa.back();
        nowyPrzystanek.dystans = sqrt(pow(x - poprzedniPrzystanek.x, 2) + pow(y - poprzedniPrzystanek.y, 2));
    }
    trasa.push_back(nowyPrzystanek);
    return;
}

/**
 * Funkcja wyświetlająca trasę "Komiwojażera" wszystkich przystanków z koordynatami.
 *
 */
void Komiwojazer::wyswietlTrase(){
    cout<<"========== TRASA KOMIWOJAZERA =========="<<endl;
    int lp = 1;
    for(auto przystanek : trasa){
        cout<<"["<<lp<<"] "<<przystanek.nazwa<<": ("<<przystanek.x <<", "<<przystanek.y<<")"<<endl;
        lp++;
    }
}

/**
 * Funkcja usuwająca przystanek z listy komiwojażera przez podanie koordynatów x i y.
 *
 * @param  int  x
 * @param  int  y
 */
void Komiwojazer::usunPrzystanekPoXY(int x, int y){
    for(auto item = trasa.begin(); item != trasa.end(); item++){
        if(item->x == x && item->y == y){
            trasa.erase(item);
            break;
        }
    }
    return;
}

/**
 * Funkcja usuwająca przystanek z listy komiwojażera przez podanie ich nazwy.
 *
 * @param  string  nazwa
 */
void Komiwojazer::usunPrzystanekPoNazwa(std::string nazwa){
    for(auto item = trasa.begin(); item != trasa.end(); item++){
        if(item->nazwa == nazwa){
            trasa.erase(item);
            break;
        } 
    }
    return;
}

/**
 * Funkcja zmieniająca przystanki miejscami przez podanie ich koordynatów.
 *
 * @param  int  x1
 * @param  int  y1
 * @param  int  x2
 * @param  int  y2
 */
void Komiwojazer::zamienKolejnosciaPoXY(int x1, int y1, int x2, int y2){
    auto item1 = trasa.end(), item2 = trasa.end();
    for(auto item = trasa.begin(); item != trasa.end(); item++){
        if(item->x == x1 && item->y == y1){
            item1 = item;
        }else if(item->x == x2 && item->y == y2){
            item2 = item;
        }
    }

    if(item1 != trasa.end() && item2 != trasa.end()){
        iter_swap(item1, item2);
        return;
    }
}

/**
 * Funkcja zmieniająca przystanki miejscami przez podanie ich nazwy.
 *
 * @param  string  nazwa1
 * @param  string  nazwa2
 */
void Komiwojazer::zamienKolejnosciaPoNazwa(string nazwa1, string nazwa2){
    auto item1 = trasa.end(), item2 = trasa.end();
    for(auto it = trasa.begin(); it != trasa.end(); it++){
        if(it->nazwa == nazwa1){
            item1 = it;
        }else if(it->nazwa == nazwa2){
            item2 = it;
        }
    }

    if(item1 != trasa.end() && item2 != trasa.end()){
        iter_swap(item1, item2);
        return;
    }
}

/**
 * Funkcja sprawdzająca czy przystanek istnieje poprzez podanie jego koordynatów.
 *
 * @param  int  x
 * @param  int  y
 * @return bool
 */
bool Komiwojazer::przystanekIstniejePoXY(int x, int y){
    for(auto przystanek : trasa){
        if(przystanek.x == x && przystanek.y == y){
            return true;
        }
    }
    return false;
}

/**
 * Funkcja sprawdzająca czy przystanek istnieje poprzez podanie jego nazwy.
 *
 * @param  string  nazwa
 * @return bool
 */
bool Komiwojazer::przystanekIstniejePoNazwa(string nazwa){
    for(auto przystanek : trasa){
        if(przystanek.nazwa == nazwa){
            return true;
        }
    }
    return false;
}

/**
 * Funkcja wyświetlająca długość trasy komiwojażera.
 *
 * @return  double  dlugosc
 */
double Komiwojazer::getDlugoscTrasy(){
    double dlugosc = 0;
    Przystanek poprzedniPrzystanek;
    
    for(auto item = trasa.begin(); item != trasa.end(); item++){
        if(item != trasa.begin()){
            dlugosc += item->dystans;
        }
        poprzedniPrzystanek = *item;
    }
    return dlugosc;
}

/**
 * Funkcja ustawiająca maksymalną wartość dla x i y.
 *
 */
void Komiwojazer::setMaxXMaxY(){
    maxX = maxY = 0;
    for(const auto& przystanek : trasa){
        maxX = max(maxX, przystanek.x);
        maxY = max(maxY, przystanek.y);
    }
}

/**
 * Funkcja eksportująca "Mapę" punktów do Excela.
 *
 * @param  string  nazwaPliku
 */
void Komiwojazer::eksportujDoCSV(const string& nazwaPliku){
    // Policz maxX i maxY
    setMaxXMaxY();

    // Przygotuj tablicę maxX na maxY
    vector<vector<string>> grid(maxY+1, vector<string>(maxX+1, "0"));

    // Uzupełnij komórki nazwami przystanków
    for(const auto& przystanek : trasa){
        grid[przystanek.y][przystanek.x] = przystanek.nazwa;
    }
    ofstream file(nazwaPliku);
    for(unsigned int i = 0; i <= maxY; i++){
        for(unsigned int j = 0; j <= maxX; j++){
            file<<grid[i][j];
            if(j != maxX){
                file<<";";
            }
        }
        file<<"\n";
    }
    file.close();
    return;
}

/**
 * Funkcja eksportująca przystanki jako obiekt do pliku json.
 *
 * @param  string  nazwaPliku
 */
void Komiwojazer::eksportujDoJSON(const string& nazwaPliku){
    ofstream file(nazwaPliku);
    file<<"[";
    for(auto& przystanek : trasa){
        file<<"{\"name\":\""<<przystanek.nazwa<<"\",\"position\":[{\"x\":\""<<przystanek.x<<"\",\"y\":\""<<przystanek.y<<"\"}]}";
        if(&przystanek != &trasa.back()){
            file<<",";
        } 
    }
    file<<"]";
    file.close();
    return;
}

/**
 * Funkcja eksportująca listę przystanków do pliku txt.
 *
 * @param  string  nazwaPliku
 */
void Komiwojazer::eksportujDoTXT(const string& nazwaPliku){
    ofstream file(nazwaPliku);
    for(auto& przystanek : trasa){
        file<<przystanek.nazwa;
        if(&przystanek != &trasa.back()){
            file<<",";
        }
    }
    file.close();
    return;
}

/**
 * Funkcja importująca obiekt z pliku json.
 *
 * @param  string  nazwaPliku
 */
void Komiwojazer::importujJSON(const string& nazwaPliku){

}