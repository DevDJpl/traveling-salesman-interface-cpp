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

// ====== DODAJ "PRZYSTANEK" NA TRASIE POPRZEZ PODANIE KOORDYNATÓW I NAZWY (NP.: MIASTA) ======
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
}

// =========== WYŚWIETL TRASĘ "KOMIWOJAŻERA" WSZYSTKICH PRZYSTANKÓW Z KOORDYNATAMI ===========
void Komiwojazer::wyswietlTrase(){
    cout<<"========== TRASA KOMIWOJAZERA =========="<<endl;
    int lp = 1;
    for(auto przystanek : trasa){
        cout<<"["<<lp<<"] "<<przystanek.nazwa<<": ("<<przystanek.x <<", "<<przystanek.y<<")"<<endl;
        lp++;
    }
}

// =========== USUŃ PRZYSTANEK Z LISTY KOMIWOJAŻERA PRZEZ PODANIE KOORDYNATÓW X I Y ===========
void Komiwojazer::usunPrzystanekPoXY(int x, int y){
    for(auto item = trasa.begin(); item != trasa.end(); item++){
        if(item->x == x && item->y == y){
            trasa.erase(item);
            break;
        }
    }
}

// ============== USUŃ PRZYSTANEK Z LISTY KOMIWOJAŻERA PRZEZ PODANIE JEGO NAZWY ===============
void Komiwojazer::usunPrzystanekPoNazwa(std::string nazwa){
    for(auto item = trasa.begin(); item != trasa.end(); item++){
        if(item->nazwa == nazwa){
            trasa.erase(item);
            break;
        } 
    }
}

// ================ ZAMIEŃ PRZYSTANKI MIEJSCAMI PRZEZ PODANIE ICH KOORDYNATÓW =================
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
    }
}

// =================== ZAMIEŃ PRZYSTANKI MIEJSCAMI PRZEZ PODANIE ICH NAZWA ===================
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
    }
}

// ============ SPRAWDŹ CZY PRZYSTANEK ISTNIEJE PRZEZ PODANIE JEGO KOORDYNATÓW ==============
bool Komiwojazer::przystanekIstniejePoXY(int x, int y){
    for(auto przystanek : trasa){
        if(przystanek.x == x && przystanek.y == y){
            return true;
        }
    }
    return false;
}

// =============== SPRAWDŹ CZY PRZYSTANEK ISTNIEJE PRZEZ PODANIE JEGO NAZWY =================
bool Komiwojazer::przystanekIstniejePoNazwa(string nazwa){
    for(auto przystanek : trasa){
        if(przystanek.nazwa == nazwa){
            return true;
        }
    }
    return false;
}

// ======================== WYŚWIETLA DŁUGOŚĆ TRASY KOMIWOJAŻERA ===========================
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

// ======================== WYEKSPORTUJ "MAPĘ" PUNKTÓW DO EXCELA ===========================
void Komiwojazer::setMaxXMaxY(){
    maxX = maxY = 0;
    for(const auto& przystanek : trasa){
        maxX = max(maxX, przystanek.x);
        maxY = max(maxY, przystanek.y);
    }
}

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
}

void Komiwojazer::eksportujDoJSON(const string& nazwaPliku){

/*
    {"employees":[    
        {"name":"Ram", "email":"ram@gmail.com", "age":23},    
        {"name":"Shyam", "email":"shyam23@gmail.com", "age":28},  
        {"name":"John", "email":"john@gmail.com", "age":33},    
        {"name":"Bob", "email":"bob32@gmail.com", "age":41}   
    ]}  
*/

    ofstream file(nazwaPliku);
    file<<"[";
    for(auto& przystanek : trasa){
        file<<"{\"name\":\""<<przystanek.nazwa<<"\",\"position\":[{\"x\":\""<<przystanek.x<<"\",\"y\":\""<<przystanek.y<<"\"}]}";
        //file<<'{"name":"'<<przystanek.nazwa<<'"}';
        //file<<'{"name":"'<<przystanek.nazwa<<'","position":[x:'<<przystanek.x<<',y:'<<przystanek.y<<']}';
        if(&przystanek != &trasa.back()){
            file<<",";
        } 
    }
    file<<"]";
}

void Komiwojazer::eksportujDoTXT(const string& nazwaPliku){
    int lp = 0;

    // Zlicz wszystkie przystanki
    for(auto przystanek : trasa){
        lp++;
    }

    ofstream file(nazwaPliku);
    for(auto& przystanek : trasa){
        file<<przystanek.nazwa;
        if(&przystanek != &trasa.back()){
            file<<",";
        }
    }
}

void Komiwojazer::importujCSV(const string& nazwaPliku){

}

void Komiwojazer::importujJSON(const string& nazwaPliku){

}

void Komiwojazer::importujTXT(const string& nazwaPliku){

}