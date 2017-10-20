// Arrays.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

const int NUM = 10;
int arr[NUM] = { 3, 1, 78, 65, 23, 10, 8, 1, 99, -7 };

int Calculate1();
int Calculate2();
int Calculate3();
bool Incrementa(char[10]);
bool Palindromo();

void SortBubble(bool);
void PrintArr(int[], int);

int main() {
    //Calculate1();

    //Calculate2();

    //Calculate3();

    //char c[NUM] = { '1','2','3','4','5', '6','7','8','9', '\0' };
    //return Incrementa(c) ? 0 : -1;

    return Palindromo() ? 0 : -1;
}

//Exercise 5
bool Palindromo() {
    cout << "Introduzca la palabra: " << endl;
    string palabra;
    cin >> palabra;
    char c;
    int i = 0;
    while (c = palabra[i], c != '\0' && i < 40) i++;

    int j = 0;
    i--;
    bool isPal = true;
    while (isPal && j <= i) {
        isPal = tolower(palabra[j]) == tolower(palabra[i]);
        j++;
        i--;
    }
    string result = isPal ? "TRUE" : "FALSE";
    cout << "RESULT: " << result << endl;
    system("pause");
    return isPal;
}

//Excercise 4
bool Incrementa(char numero[10]) {
    int n = stoi(numero);
    n++;
    cout << "NUMBER INCREMENTED: " << n << endl;
    system("pause");
    return true;
}

//Exercise 3
int Calculate3() {
    int matrix[5][5] = { { 4,7,1,-1,0 },
    { 1,7,3,10,5 },
    { 3,6,3,17,5 },
    { 2,9,3,4,9 },
    { -5,8,-1,0,1 } };

    int totFil = 0;
    int sumCols[5] = { 0,0,0,0,0 };

    for (int f = 0; f < 5; f++) {
        totFil = 0;
        for (int c = 0; c < 5; c++) {
            cout << matrix[f][c] << ", ";
            totFil += matrix[f][c];
            sumCols[c] += matrix[f][c];
        }
        cout << ", = " << totFil << endl;
    }

    cout << "-------------------------" << endl;
    totFil = 0;
    for (int i = 0; i < 5; i++) {
        cout << sumCols[i] << ", ";
        totFil += sumCols[i];
    }
    cout << ", = " << totFil << endl;

    system("pause");
    return 0;
}

//Exercise 2
int Calculate2() {
    PrintArr(arr, NUM);
    system("pause");
    SortBubble(true);
    PrintArr(arr, NUM);
    system("pause");
    SortBubble(false);
    PrintArr(arr, NUM);
    system("pause");
    return 0;
}

void SortBubble(bool isCrescent) {
    for (int i = NUM - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (isCrescent) {
                if (arr[j] > arr[j + 1]) {
                    int aux = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = aux;
                }
            }
            else {
                if (arr[j] < arr[j + 1]) {
                    int aux = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = aux;
                }
            }
        }
    }
}

void PrintArr(int a[], int n) {
    cout << "[";
    for (int i = 0; i < n; i++) cout << a[i] << ", ";
    cout << "]\n";
}

//Exercise 1
int Calculate1() {
    string line = "";
    int numbers[NUM];
    cout << "Write " << NUM << " numbers separated by comma:\n";
    getline(cin, line);
    stringstream ss(line);

    /* Result data */
    int total = 0;
    double average = 0;
    int l = INT_MAX;
    int h = INT_MIN;

    /* Read input string */
    int value;
    char separator;
    int i = 0;
    while (ss >> value && i < NUM) {
        ss >> separator;
        numbers[i] = value;
        i++;
        total += value;
        if (value < l) l = value;
        if (value > h) h = value;
    }
    if (i < NUM) return -1;

    /* Calculate average */
    average = (double)total / (double)NUM;
    cout.precision(4);
    cout << "Total: " << total << "\nAverage: " << average << "\nHighest: " << h << "\nLowest: " << l << endl;
    system("pause");
    return 0;
}