// Structs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct stPerson {
    string name;
    string number;

    stPerson() { name = ""; number = ""; }
    void print() { cout << "Name: " << name << "\nNumber: " << number << "\n------------------------" << endl; }
} _People[10];
int _Num = 0;

//Exercise 2
/*
day -> 5 bits(32)
month -> 4 bits(16)
year -> 7 bits(128)
(YYYY-MM-DD)

total -> 16 bits
*/

const string MONTHS[12] = { "January", "February", "March", "April", "May", "June", "July", "August",
                            "Septempber","October" , "Nobember", "December" };
int DAYS_MONTH[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

struct stDate {
    unsigned short int day : 5;
    unsigned short int month : 4;
    unsigned short int year : 7;

    void print() { cout << 1960 + year << "/" << MONTHS[month-1] << "/" << day; }
};


int initProgram();
bool searchByName();
bool searchByNumber();
void insertPerson();
void showDate(stDate);
bool validateDate(stDate);
int compareDates(stDate, stDate);
int diffDates(stDate, stDate);


int main() {
    //return initProgram();

    stDate date;
    date.day = 28;
    date.month = 2;
    date.year = 45;
    showDate(date);
    return 0;
}

//Exercise 5
int diffDates(stDate date1, stDate date2) {
    //TO DO
}

int compareDates(stDate date1, stDate date2) {
    if (date1.year < date2.year) {
        return 1;
    }
    else if (date1.year > date2.year) {
        return -1;
    }
    else {
        if (date1.month < date2.month) {
            return 1;
        }
        else if (date1.month > date2.month) {
            return -1;
        }
        else {
            if (date1.day < date2.day) {
                return 1;
            }
            else if (date1.day > date2.day) {
                return -1;
            }
            else {
                return 0;
            }
        }
    }
}

//Exercise 4
bool validateDate(stDate date) {
    if (date.month < 1 || 12 < date.month) return false;
    if (date.month == 2) {
        if ((date.year + 1960) % 4 == 0) DAYS_MONTH[1] = 29;
        else DAYS_MONTH[1] = 28;
    }
    if (date.day < 1 || DAYS_MONTH[date.month-1] < date.day) return false;
    return true;
}

//Exercise 3
void showDate(stDate date) {
    if (validateDate(date)) {
        cout << "DATE: ";
        date.print();
        cout << endl;
    }
    else cout << "Wrong date!!" << endl;

    system("pause");
}

//Exercise 1
int initProgram() {
    bool exit = false;
    char op;
    stPerson person;

    while (!exit) {
        cout << "\n\n\na) Search by name\nb) Search by number\nc) Add person to list\nd) Print list\ne) Exit\nChoose an option:" << endl;
        cin >> op;

        switch (op) {
            case 'a':
                if (!searchByName()) cout << "No person found!!!" << endl;
                break;
            case 'b':
                if (!searchByNumber()) cout << "No person found!!!" << endl;
                break;
            case 'c':
                insertPerson();
                break;
            case 'd':
                for (int i = 0; i < _Num; i++) _People[i].print();
                break;
            default:
                exit = true;
        }
    }
    return 0;
}

bool searchByName() {
    string name;
    cout << "Write name:" << endl;
    cin >> name;
    transform(name.begin(), name.end(), name.begin(), tolower);

    bool found = false;
    int i = 0;
    while (!found && i < _Num) {
        if (_People[i].name == name) {
            _People[i].print();
            found = true;
        }
        else i++;
    }
    return found;
}

bool searchByNumber() {
    string number;
    cout << "Write number:" << endl;
    cin >> number;

    bool found = false;
    int i = 0;
    while (!found && i < _Num) {
        if (_People[i].number == number) {
            _People[i].print();
            found = true;
        }
        else i++;
    }
    return found;
}

void insertPerson() {
    if (_Num < 10) {
        stPerson person;
        cout << "Write name:" << endl;
        cin >> person.name;
        transform(person.name.begin(), person.name.end(), person.name.begin(), tolower);

        cout << "Write number:" << endl;
        cin >> person.number;

        _People[_Num] = person;
        _Num++;
    }
    else cout << "List full" << endl;
}