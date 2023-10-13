#include <iostream>
#include "vetor.h"

using std::cin;
using std::cout; 
using std::endl;
using std::string;

int main() {
  try {
    int inicio, fim;
    cin >> inicio >> fim;
    Vetor v(inicio, fim);
    char opcao;
    while (cin >> opcao) {
      int indice;
      string valor;
      if (opcao == 'a') {
        cin >> indice;
        cin >> valor;
        try {
          v.atribuir(indice, valor);
        } catch(IndiceInvalido e) {
          cout << "Não foi possível executar a operação: índice " << e.indice << " não pertence ao intervalo [" << e.inicio << ", " << e.fim << "].";
          return 1;
        }
      } else if (opcao == 'v') {
        cin >> indice;
        try {
          valor = v.valor(indice);
          cout << valor << endl;
        } catch(IndiceInvalido e) {
          cout << "Não foi possível executar a operação: índice " << e.indice << " não pertence ao intervalo [" << e.inicio << ", " << e.fim << "].";
          return 1;
        }
      } else if (opcao == 'f') {
        return 0;
      } else {
        cout << "Opção inválida!" << endl;
      }
    }
  } catch(IndiceNaoInicializado e) {
        cout << "Não foi possível executar a operação: índice " << e.indice << " não foi inicializado." << endl;
  } catch (IntervaloVazio e) {
        cout << "Não foi possível executar a operação: intervalo [" << e.inicio << ", " << e.fim << "] é vazio." << endl; 
        return 1;
      }
  return 0;

}