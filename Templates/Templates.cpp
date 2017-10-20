// Templates.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<vld.h>
#include <iostream>

#include "Stack.h"
#include "StackT.h"

using namespace std;

bool isInteger(const string&);

int main() {
    //Stack stack;
    StackT<int> stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);

    //Stack stack2 = stack;// <==> Stack stack2(stack);

    //Stack stack2;
    //stack2 = stack;

    StackT<int> stack2;
    stack2 = stack;

    printf("\n\n\nAny number: PUSH\n'd': POP\n'e': EXIT");

    printf(stack.toString().c_str());
    printf(stack2.toString().c_str());

    string s;
    while (cin >> s, s != "e") {
        if (isInteger(s)) {
            stack.push(stoi(s));
            printf(stack.toString().c_str());
            printf(stack2.toString().c_str());
        }
        else if (s == "d") {
            stack.pop();
            printf(stack.toString().c_str());
            printf(stack2.toString().c_str());
        }
    }
    return 0;
}

inline bool isInteger(const string &s) {
    if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;

    char * p;
    strtol(s.c_str(), &p, 10);

    return (*p == 0);
}
