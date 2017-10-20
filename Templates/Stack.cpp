#include "Stack.h"


void Stack::clearStack() {
    while (_Top) pop();
}

void Stack ::copyStack(const Stack &stack) {
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

void Stack::push(const int &e) {
    stElem* elem = new stElem(e);
    if (!_Top) {
        //stElem elem(e);
        //_Top = &elem;
        _Top = elem;
        elem->sig = nullptr;
    }
    else {
        elem->sig = _Top;
        _Top = elem;
    }
    _Size++;
    printf("PUSH: %i\n", e);
}

inline const int Stack::peek() const {
    return _Top->elem;
}

int Stack::pop() {
    int res = 0;
    if (_Top) {
        stElem* elem = _Top;
        _Top = _Top->sig;
        res = elem->elem;
        elem->sig = nullptr;
        delete elem;
        _Size--;
        printf("POP: %i\n", res);
    }
    else printf("POP ERROR\n");
    return res;
}

string Stack::toString() {
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