#include "pizza.hpp"
#include <sstream>

using namespace std;

//Descricao da Pizza.
std::string Pizza::descricao() const {
  stringstream ss;
  ss << m_qtd << "X Pizza " << m_sabor << ", ";
  if (m_borda_recheada) {
    ss << m_pedacos << " pedacos e borda recheada.";
  } else {
    ss << m_pedacos << " pedacos e sem borda recheada.";
  }
  return ss.str();
}

Pizza::Pizza(const std::string& sabor,
             int pedacos,
             bool borda_recheada,
             int qtd,
             float valor_unitario) {
              
  m_sabor = sabor; 
  m_borda_recheada = borda_recheada; 
  m_pedacos = pedacos;
  m_qtd = qtd;
  m_valor_unitario = valor_unitario;
}