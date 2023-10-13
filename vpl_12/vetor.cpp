#include "vetor.h"

using std::string;

// Vet
Vetor::Vetor(int inicio, int fim)
{
    if (fim < inicio) {
        throw IntervaloVazio{inicio, fim};
    }
    inicio_ = inicio;
    fim_ = fim;
    elementos_ = new string[fim - inicio + 1];
}

// Atribuicao
void Vetor::atribuir(int i, string valor)
{
    int dt = inicio_ + fim_ - inicio_;
    if (i < inicio_ || i > dt)
    {
        throw IndiceInvalido{inicio_, fim_, i};
    }
    int j = i - inicio_;
    elementos_[j] = valor;
}

// Value
string Vetor::valor(int i) const {
    int dt = inicio_ + fim_ - inicio_;
    if (i < inicio_ || i > dt) {
      throw IndiceInvalido{inicio_, fim_, i};
    }
    if(elementos_[i - inicio_] == "") {
       throw IndiceNaoInicializado{i};
    }
    int j = i - inicio_;
    return elementos_[j];
}

// DEl
Vetor::~Vetor() {
    delete [] elementos_;
}

