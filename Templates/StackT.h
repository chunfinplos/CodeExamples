#pragma once
#include <string>
#include <sstream>

using namespace std;

template <class T>
class StackT {

    struct stElem {
        T elem;
        stElem* sig;

        stElem(T e) : elem(e), sig(nullptr) {}
        ~stElem() { sig = nullptr; }
    };

public:
    StackT() : _Top(nullptr), _Size(0) {};
    StackT(const StackT &stack) { copyStack(stack); };
    ~StackT() { clearStack(); };

    inline const T peek() const;
    void push(const T &e);
    T pop();

    string toString();

    /* OPERATORS */
    StackT& operator=(const StackT &stack) {
        if (this != &stack) {
            clearStack();
            copyStack(stack);
        }
        return *this;
    }

private:
    void clearStack();
    void copyStack(const StackT &stack);

    stElem* _Top;
    int _Size;
};

template <class T>
void StackT<T>::clearStack() {
    while (_Top) pop();
}

template <class T>
void StackT<T>::copyStack(const StackT &stack) {
    stElem* readPivot = stack._Top;
    stElem* writePivot = new stElem(readPivot->elem);
    _Top = writePivot;
    _Size = stack._Size;
    for (int i = 1; i < _Size; i++) {
        readPivot = readPivot->sig;
        writePivot->sig = new stElem(readPivot->elem);
        writePivot = writePivot->sig;
    }
}

template <class T>
void StackT<T>::push(const T &e) {
    stElem* elem = new stElem(e);
    if (!_Top) {
        _Top = elem;
        elem->sig = nullptr;
    }
    else {
        elem->sig = _Top;
        _Top = elem;
    }
    _Size++;
}

template <class T>
inline const T StackT<T>::peek() const {
    return _Top->elem;
}

template <class T>
T StackT<T>::pop() {
    T res = 0;
    if (_Top) {
        stElem* elem = _Top;
        _Top = _Top->sig;
        res = elem->elem;
        elem->sig = nullptr;
        delete elem;
        _Size--;
    }
    return res;
}

template <class T>
string StackT<T>::toString() {
    if (_Top) {
        stElem* pivot = _Top;
        stringstream ss;
        ss << "\n\n\n";
        for (int i = 0; i < _Size; i++) {
            ss << "[" << pivot->elem << "]\n";
            pivot = pivot->sig;
        }
        ss << "---\n";
        return ss.str();
    }
    return "[]";
}