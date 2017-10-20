#pragma once
#include <string>
#include <sstream>

using namespace std;

class Stack {
    
    struct stElem {
        int elem;
        stElem* sig;

        stElem(int e=0) : elem(e), sig(nullptr) {}
        ~stElem() { sig = nullptr; }
    };

public:
    Stack() : _Top(nullptr), _Size(0) {};
    Stack(const Stack &stack) { copyStack(stack); };
    ~Stack() { clearStack(); };

    inline const int peek() const;
    void push(const int & e);
    int pop();
    
    string toString();

    /* OPERATORS */
    Stack& operator=(const Stack &stack){
        if (this != &stack) {
            clearStack();
            copyStack(stack);
        }
        return *this;
    }

private:
    void clearStack();
    void copyStack(const Stack &stack);

    stElem* _Top;
    int _Size;
};

