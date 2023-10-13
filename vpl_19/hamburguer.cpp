#include "hamburguer.hpp"
#include <sstream>

using namespace std;

//descricao
std::string Hamburguer::descricao() const {
  stringstream ss;

  if (m_artesanal) {
     ss << m_qtd << "X Hamburguer " << m_tipo << " artesanal.";
  } else {
     ss << m_qtd << "X Hamburguer " << m_tipo << " simples.";
  }
  return ss.str();
}

Hamburguer::Hamburguer(const std::string& tipo,
                       bool artesanal,
                       int qtd,
                       float valor_unitario) {
  m_tipo = tipo; 
  m_artesanal = artesanal; 
  m_qtd = qtd;
  m_valor_unitario = valor_unitario;
}