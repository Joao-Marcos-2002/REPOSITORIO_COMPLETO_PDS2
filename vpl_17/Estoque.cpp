#include <iostream>
#include <map>
#include <string>
#include <utility>

#include "Estoque.hpp"

using namespace std;

void Estoque::add_mercadoria(const std::string &mercadoria, unsigned int qtd) {
  map<string, int>::iterator it = armazenamento_.find(mercadoria);
  if (it == armazenamento_.end()) {
    armazenamento_[mercadoria] = qtd;
  } else {
    armazenamento_[mercadoria] += qtd;
  }
}

void Estoque::sub_mercadoria(const std::string &mercadoria, unsigned int qtd) {
  map<string, int>::iterator it = armazenamento_.find(mercadoria);
  if (it == armazenamento_.end()) {
    cout << mercadoria << " inexistente" << endl;
    return;
  }
  if (qtd > armazenamento_[mercadoria]) {
    cout << mercadoria << " insuficiente" << endl;
    return;
  } else {
    armazenamento_[mercadoria] -= qtd;
  }
}

unsigned int Estoque::get_qtd(const std::string &mercadoria) const {
  //busca
  auto it = armazenamento_.find(mercadoria);

  if (it == armazenamento_.end()) {
    return 0;
  } else {
    return *it->second;
  }
}

void Estoque::imprime_estoque() const {
  for (pair<string, int> item : armazenamento_) {
    cout << item.first << ", " << item.second << endl;
  }
}

Estoque &Estoque::operator+=(const Estoque &rhs) {
  for (pair<string, int> item : rhs.armazenamento_) {
    map<string, int>::iterator it = armazenamento_.find(item.first);
    if (it != armazenamento_.end()) {
      armazenamento_[item.first] += item.second;
    } else {
      (*this).armazenamento_.insert(item);
    }
  }
  return *this;
}

Estoque &Estoque::operator-=(const Estoque &rhs) {
  for (pair<string, int> item : rhs.armazenamento_) {
    map<string, int>::iterator it = armazenamento_.find(item.first);
    if (it != armazenamento_.end()) {
      armazenamento_[item.first] -= item.second;
    } 
  }
  return *this;
}

  bool operator<(Estoque &lhs, Estoque &rhs) {
    for (pair<string, int> x : lhs.armazenamento_) {

      map<string, int>::iterator it = rhs.armazenamento_.find(x.first);
      //busca no estoque.
      if (it != rhs.armazenamento_.end()) {
        if (rhs.armazenamento_[x.first] > x.second) {
          return true;
        } else {
          return false;
        }
      } else {
        return false;
      }
    }
  }

  bool operator>(Estoque &lhs, Estoque &rhs) {  
    for (pair<string, int> x : rhs.armazenamento_) {
      map<string, int>::iterator it = lhs.armazenamento_.find(x.first);
      if (it != lhs.armazenamento_.end()) {
        if (lhs.armazenamento_[x.first] > x.second) {
          return true;
        } else {
          return false;
        }
      } else {
        return false;
      }
    }
  }