// Functions4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdarg.h>

using namespace std;

int mayor(int a, int b);
int mayor(int a, int b, int c);
int mayor(int a, int b, int c, int d);
inline int* mapFunction(void (*f) (int&), int, ...);
void invert(int&);

int main() {
    //cout << mayor(10, 4) << endl;
    //cout << mayor(15, 35, 23) << endl;
    //cout << mayor(10, 12, 12, 18) << endl;


    int* arr = mapFunction(invert, 3, 1, 2, 3);
    if (arr) cout << "["; for (int i = 0; i < 3; i++) cout << arr[i] << ", "; cout << "]\n";

    system("pause");
    return 0;
}

//Exercise
int* mapFunction(void(*f) (int&), int num, ...) {
    int* n = nullptr;
    if (num > 0) {
        va_list ar;
        va_start(ar, num);
        n = new int[num];
        for (int i = 0; i < num; i++) {
            n[i] = va_arg(ar, int);
            f(n[i]);
        }
        va_end(ar);
    }
    return n;
}

void invert(int &n) {
    n *= -1;
}


int mayor(int a, int b) {
    if (a > b) return a; else return b;
}

int mayor(int a, int b, int c) {
    return mayor(mayor(a, b), c);
}

int mayor(int a, int b, int c, int d) {
    return mayor(mayor(a, b), mayor(c, d));
}