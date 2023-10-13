#include "japonesa.hpp"
#include <sstream>

using namespace std;

//Descricao: Comida Japonesa.
std::string Japonesa::descricao() const {

  stringstream ss;
  ss << m_qtd << "X Comida japonesa - " << m_combinado << ", ";
  ss << m_sushis << " sushis, ";
  ss << m_temakis << " temakis e ";
  ss << m_hots << " hots.";
  return ss.str();
}


// Dados - Comida Japonesa.
Japonesa::Japonesa(const std::string& combinado,
                   int sushis,
                   int temakis,
                   int hots,
                   int qtd,
                   float valor_unitario) {
  m_combinado = combinado;
  m_sushis = sushis;
  m_temakis = temakis; 
  m_valor_unitario = valor_unitario;
  m_qtd = qtd;
  m_hots = hots;
}