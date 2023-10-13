#include "Complexo.h";

Complexo::operator-(Complexo y) {
    return (*this) - y;
}

Complexo::operator/(Complexo y) {
    //*this  equivale ao Complexo
    return (*this) * y.inverso();
}


