#include "dicionario.h"

using namespace std;

Dicionario::Dicionario() {
    elementos_ = {};
}

int Dicionario::tamanho() {
    return elementos_.size();
}

bool Dicionario::pertence(string chave) {
    for (auto it = elementos_.begin(); it != elementos_.end(); it++) {
        if(it.chave == chave) {
            return true;
        } else {
            return false;
        }
    }
}

// Considerando que tem elemento no dicionario:
string Dicionario::menor() {
   string menor = elementos_[0];

    for (auto it = elementos_.begin(); it != elementos_.end(); it++) {
        if (it < menor) {
            menor = it;
        }
    }
    return menor;
}

string Dicionario::valor(string chave) {
    return chave;
}

void Dicionario::Inserir(string chave, string valor) {
    elementos_.push_back(chave, valor);
}

void Dicionario::Remover(string chave) {
    for(auto it = elementos_.begin(); it != elementos_.end(); it++) {
        if (it.chave == chave) {
            it.erase();
        }
    }
}

void Dicionario::Alterar(string chave, string valor) {
    for (auto it = elementos_.begin(); it != elementos_.end(); it++) {
        if(it.chave == chave) {
            it.valor = valor;
        }
    }
}

