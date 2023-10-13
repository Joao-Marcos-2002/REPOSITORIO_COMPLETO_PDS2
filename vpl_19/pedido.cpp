#include "pedido.hpp"

#include <sstream>

using namespace std;

Pedido::~Pedido() {
  for (auto x : m_produtos) {
    delete x;
  } 
}

void Pedido::setEndereco(const std::string& endereco) {
  m_endereco = endereco;
}

float Pedido::calculaTotal() const {
  float tot = 0.0;
  for (auto x : m_produtos) {
    tot += x->getQtd() * x->getValor();
  } 
  return tot;
}

//Add pedido
void Pedido::adicionaProduto(Produto* p) {
  m_produtos.push_back(p);
}

// Resumo do pedido.
std::string Pedido::resumo() const {
  stringstream ss;
  for (auto p : m_produtos) { 
    ss << p->descricao() << endl;
  }

  ss << "Endereco: " << m_endereco << endl;
  return ss.str();
}