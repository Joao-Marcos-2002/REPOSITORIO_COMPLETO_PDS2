#include "venda.hpp"

#include <iomanip>
#include <iostream>

using namespace std;

Venda::~Venda() {

  for (auto x : m_pedidos) {
    delete x;
  } 
  
}

void Venda::adicionaPedido(Pedido* p) {
  m_pedidos.push_back(p);
}

void Venda::imprimeRelatorio() const {

  int contador_de_pedidos = 0;
  float tot_vendas = 0.0;

  //duas casas decimais.
  cout << std::setprecision(2);
  cout << std::fixed;
  for (auto pedido : m_pedidos) { 
    cout << "Pedido " << ++contador_de_pedidos << endl;
    cout << pedido->resumo();
    tot_vendas += pedido->calculaTotal();  
  }
  cout << "Relatorio de Vendas" << endl;
  cout << "Total de vendas: R$ " << tot_vendas << endl;
  cout << "Total de pedidos: " << contador_de_pedidos << endl;  
}