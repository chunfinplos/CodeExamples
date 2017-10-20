// Pointers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>


using namespace std;

string _Chars = "";

int charLength();
int searchChar(char);

int main() {
    bool exit = false;
    char op;

    while (!exit) {
        cout << "\n\n\na) Insert string\nb) Search character\nc) Exit\nSelect and option" << endl;
        cin >> op;

        switch (op) {
            case 'a':
                cout << "Write a word:" << endl;
                cin >> _Chars;
                cout << "Word Length: " << charLength() << "\n----------------------------" << endl;
                break;
            case 'b':
                if (_Chars.length() > 0) {
                    char c;
                    cout << "Write a character:" << endl;
                    cin >> c;
                    cout << "Charcter postion: " << searchChar(c) << "\n----------------------------" << endl;
                }
                else cout << "No word in memory" << endl;
                break;
            default:
                exit = true;
        }
    }
    return 0;
}

//Exercise 2
int searchChar(char c) {
    int pos = 0;
    const char* aux = _Chars.c_str();
    while (*aux != c) { pos++; aux++; }
    return pos;
}

//Exercise 1
int charLength() {
    int counter = 0;
    const char* aux = _Chars.c_str();
    while (*aux != '\0') { counter++; aux++; }
    return counter;
}