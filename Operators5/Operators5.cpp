// Operators5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


using namespace std;

struct stAngulo {
    int grados;
    int minutos;
    int segundos;

    stAngulo() { grados = 0; minutos = 0; segundos = 0; }
    void print() { cout << grados << " G, " << minutos << "', " << segundos << "''" << endl; }
};

stAngulo operator+(stAngulo, stAngulo);
stAngulo operator++(stAngulo&, int);

int main() {
    stAngulo a;
    a.grados = 359;
    a.minutos = 59;
    a.segundos = 59;
    stAngulo b;
    b.grados = 2;
    b.minutos = 2;
    b.segundos = 3;

    cout << "-------------------------------------------" << endl;

    a.print();
    a++;
    a.print();
    a++;
    a.print();
    
    cout << "-------------------------------------------" << endl;

    cout << "-------------------------------------------" << endl;

    b.print();
    b++;
    b.print();
    b++;
    b.print();

    cout << "-------------------------------------------" << endl;
    cout << "-------------------------------------------" << endl;

    stAngulo res = a + b;
    res.print();


    system("pause");
    return 0;
}

//Exercise 2
//TO DO

//Exercise 1
stAngulo operator++(stAngulo &res, int) {
    res.segundos++;
    if (res.segundos == 60) {
        res.segundos = 0;
        res.minutos++;
        if (res.minutos == 60) {
            res.minutos = 0;
            res.grados++;
            if (res.grados == 360) {
                res.grados = 0;
            }
        }
    }
    return res;
}

stAngulo operator+(stAngulo a, stAngulo b) {
    stAngulo res;

    res.segundos = a.segundos + b.segundos;
    if (res.segundos >= 60) {
        res.minutos += res.segundos / 60;
        res.segundos = res.segundos % 60;
        
    }

    res.minutos += a.minutos + b.minutos;
    if (res.minutos >= 60) {
        res.grados += res.minutos / 60;
        res.minutos = res.minutos % 60;
        
    }

    res.grados += a.grados + b.grados;
    if (res.grados >= 360) {
        res.grados = res.grados % 360;
    }

    return res;
}