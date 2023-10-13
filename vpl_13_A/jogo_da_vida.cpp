#include "jogo_da_vida.h"

using namespace std;

JogoDaVida::JogoDaVida(int l, int c) {
  vivas_ = vector<vector<bool>>(l, vector<bool>(c, false));
}

//viva
bool JogoDaVida::viva(int i, int j) {
  return vivas_[i][j];
}

//Matar
void JogoDaVida::Matar(int i, int j) {
  vivas_[i][j] = false;
}

//Reviver
void JogoDaVida::Reviver(int i, int j) {
  vivas_[i][j] = true;
}

//numDeVizinhas
int JogoDaVida::NumeroDeVizinhasVivas(int x, int y) {
  int linhas = vivas_.size(); 

  //Pega da primeira posicao
  int colunas = vivas_[0].size();

  int c = 0;
  for (int i = -1; i <= 1; ++i) {
    for (int j = -1; j <= 1; ++j) {

    //caso linha e coluna = 0:
      if (i == 0 && j == 0) {
        continue;  
      }

      int m = (x + i + linhas) % linhas;      
      int n = (y + j + colunas) % colunas;    

      if (vivas_[m][n]) {
        c++;
      }
    }
  }

  return c;
}

void JogoDaVida::ExecutarProximaIteracao() {
  int linhas = vivas_.size();
  int colunas = vivas_[0].size();
  vector<vector<bool>> proxIteracao(linhas, vector<bool>(colunas, false));

  for (int i = 0; i < linhas; i++) {
    for (int j = 0; j < colunas; j++) {

      bool estaViva = vivas_[i][j];
      int numVivas = NumeroDeVizinhasVivas(i, j);

      //Verifica se esta viva:
      if (estaViva) {
        if (numVivas < 2 || numVivas > 3) {
          proxIteracao[i][j] = false;  
        } else {
          proxIteracao[i][j] = true;   
        }
      } else {
        if (numVivas == 3) {
          proxIteracao[i][j] = true;   
        } else {
          proxIteracao[i][j] = false;  
        }
      }
    }
  }

  
  vivas_ = proxIteracao;
  //proximaIteracao no jogo da vida.
}
