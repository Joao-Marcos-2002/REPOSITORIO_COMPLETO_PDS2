#include "racional.h"

#include <cmath>
#include <iostream>


int mdc_(int n, int d) {
    if (d == 0)
        return n;
    return mdc_(d, n % d);
}

 // Divide o numerador e denominador pelo MDC, e
 // garante que o denominador é sempre positivo.
  void Racional::Simplificar() {
    if(denominador_ > 0) {
      int mdc = mdc_(numerador_, denominador_);
      numerador_ = numerador_ / mdc;
      denominador_ = denominador_ / mdc;
    }
  }


Racional::Racional() : numerador_(0), denominador_(1) {
}

Racional::Racional(int n) : numerador_(n), denominador_(1) {
}

Racional::Racional(int n, int d) : numerador_(n), denominador_(d) {
  Simplificar();
}

// Retorna o numerador.
int Racional::numerador() const {
  return numerador_;
}

// Retorna o denominador.
int Racional::denominador() const {
  return denominador_;
}

// Retorna o simétrico de *this.
Racional Racional::operator-() const {
  return Racional(-numerador_, denominador_);
}

// Retorna a soma de *this e k.
Racional Racional::operator+(Racional k) const {
  int num = numerador_ * k.denominador() + denominador_ * k.numerador();
  int den = denominador_ * k.denominador();
  return Racional(num, den);
}

// Retorna a subtração de *this e k.
Racional Racional::operator-(Racional k) const {
  int n = numerador_ * k.denominador() - denominador_ * k.numerador();
  int d = denominador_ * k.denominador();
  return Racional(n, d);
}

// Retorna a multiplicação de *this e k.
Racional Racional::operator*(Racional k) const {
  int n = numerador_ * k.numerador();
  int d = denominador_ * k.denominador();
  return Racional(n, d);
}

// Retorna a divisão de *this por k.
Racional Racional::operator/(Racional k) const {
  int n = numerador_ * k.denominador();
  int d = denominador_ * k.numerador();
  return Racional(n, d);
}

//operator divisao
Racional::operator float() const {
  return (float)numerador_ / denominador_;
}

//to string
Racional::operator string() const {
  return std::to_string(numerador_) + "/" + std::to_string(denominador_);
}

//sobrecarrega o operador de inserção de streams
ostream& operator<<(ostream& out, Racional r) {
  out << (string)r;
  return out;
}

// Sobrecarrega o operador de extração de streams.
istream& operator>>(istream& in, Racional& r) {
  int n, d;
  in >> n >> d;

  // Instancia o Racional
  r = Racional(n, d);
  return in;
}

