// Pointers2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


using namespace std;

#define NCIUDADES 5 
#define CIUDAD_A 0 
#define CIUDAD_B 1 
#define CIUDAD_C 2 
#define CIUDAD_D 3 
#define CIUDAD_E 4

const int _N = 6;
float _Numbers[_N] = { 1.32, 4.21, 2.33, 0.23, 8.35, 2.32 };

int Distancia(int, int, int **);
void AsignarDistancia(int**, int, int, int);
void Intercambio(int &, int &);
int* ordenar();
int comparar(const void*, const void*);
void concatenar(int[], int[], int, int);
int* concatenar2(int[], int[], int, int);

int main() {
    //int i;
    //int **tabla;

    //// Primer subíndice de A a D 
    //tabla = new int*[NCIUDADES - 1];
    //// Segundo subíndice de B a E, 
    //// define 4 arrays de 4, 3, 2 y 1 elemento: 
    //for (i = 0; i < NCIUDADES - 1; i++)
    //    tabla[i] = new int[NCIUDADES - 1 - i]; // 4, 3, 2, 1 
    //                                           // Inicialización: 
    //tabla[CIUDAD_A][CIUDAD_B - CIUDAD_A - 1] = 154;
    //tabla[CIUDAD_A][CIUDAD_C - CIUDAD_A - 1] = 245;
    //tabla[CIUDAD_A][CIUDAD_D - CIUDAD_A - 1] = 54;
    //tabla[CIUDAD_A][CIUDAD_E - CIUDAD_A - 1] = 452;
    //tabla[CIUDAD_B][CIUDAD_C - CIUDAD_B - 1] = 354;
    //tabla[CIUDAD_B][CIUDAD_D - CIUDAD_B - 1] = 125;
    //tabla[CIUDAD_B][CIUDAD_E - CIUDAD_B - 1] = 133;
    //tabla[CIUDAD_C][CIUDAD_D - CIUDAD_C - 1] = 152;
    //tabla[CIUDAD_C][CIUDAD_E - CIUDAD_C - 1] = 232;
    //tabla[CIUDAD_D][CIUDAD_E - CIUDAD_D - 1] = 110;

    //AsignarDistancia(tabla, CIUDAD_A, CIUDAD_D, 56);

    //cout << "Distancia A-D: " << Distancia(CIUDAD_A, CIUDAD_D, tabla) << endl;
    ////cout << "Distancia B-E: " << Distancia(CIUDAD_B, CIUDAD_E, tabla) << endl;
    ////cout << "Distancia D-A: " << Distancia(CIUDAD_D, CIUDAD_A, tabla) << endl;
    ////cout << "Distancia B-B: " << Distancia(CIUDAD_B, CIUDAD_B, tabla) << endl;
    ////cout << "Distancia E-D: " << Distancia(CIUDAD_E, CIUDAD_D, tabla) << endl;

    //// Liberar memoria dinámica: 
    //for (i = 0; i < NCIUDADES - 1; i++) delete[] tabla[i];
    //delete[] tabla;

    //int a = 9, b = 1;
    //Intercambio(a, b);

    //cout << "Intercambio:\na = " << a << ", b = " << b << endl;


    //cout << "["; for (int i = 0; i < _N; i++) cout << _Numbers[i] << ", "; cout << "]\n";
    //system("pause");
    //int* ord = ordenar();

    //cout << "["; for (int i = 0; i < _N; i++) cout << ord[i] << ", "; cout << "]\n";
    //
    //delete[] ord;


    int a1[] = { 1,3,4,7,8,9,12,15,16,17,21,23,25 };
    int a2[] = { 2,5,6,10,11,13,14,18,19,20,22,24,26,27,28 };
    int n1 = sizeof(a1) / sizeof(int);
    int n2 = sizeof(a2) / sizeof(int);
    concatenar(a1, a2, n1, n2);


    system("pause");
    return 0;
}

//Exercise 4
// a1 es la cadena por la que empezar
int* concatenar2(int a1[], int a2[], int n1, int n2) {
    int l = n1 + n2;
    int* ord = new int[l];
    bool found = false;
    int j = 0;
    int k = 0;

    for (int i = 0; i < n1; i++) {
        ord[k] = a1[i];
        k++;

        while (j < n2 && i < n1 && a2[j] <= a1[i + 1]) {
            ord[k] = a2[j];
            k++;
            j++;
        }
    }

    for (j; j < n2; j++) {
        ord[k] = a2[j];
        k++;
    }

    return ord;
}

void concatenar(int a1[], int a2[], int n1, int n2) {
    if (n1 > 0 && n2 > 0) {
        int* ord = a1[0] < a2[0] ? concatenar2(a1, a2, n1, n2) :
                                   concatenar2(a2, a1, n2, n1);

        cout << "["; for (int i = 0; i < n1 + n2; i++) cout << ord[i] << ", "; cout << "]\n";

        delete[] ord;
    }
}

//Exercise 3
//TO DO

//Exercise 2
int comparar(const void *arg1, const void *arg2) {
    float n1 = _Numbers[*(int *)arg1];
    float n2 = _Numbers[*(int *)arg2];

    if (n1 < n2) return -1;
    else if (n1 > n2) return 1;
    else return 0;
}

int* ordenar() {
    int* ord = new int[_N];
    for (int i = 0; i < _N; i++) ord[i] = i;
    qsort(ord, _N, sizeof(int), comparar);
    return ord;
}

//Exercise 1
void Intercambio(int &a, int &b) {
    int aux = a;
    a = b;
    b = aux;
}

void AsignarDistancia(int** tabla, int A, int B, int distancia) {
    int aux;
    if (A > B) {
        aux = A;
        A = B;
        B = aux;
    }

    tabla[A][B - A - 1] = distancia;
}

int Distancia(int A, int B, int **tabla) {
    int aux;

    // Si ambos subíndices son iguales, volver con cero: 
    if (A == B) return 0;
    // Si el subíndice A es mayor que B, intercambiarlos: 
    if (A > B) {
        aux = A;
        A = B;
        B = aux;
    }
    return tabla[A][B - A - 1];
}
