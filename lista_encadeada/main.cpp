#include <iostream>
#include <string>

using namespace std;

struct aluno {
    int matricula;
    string nome;
    int nota;
    aluno *proximo;
    aluno *anterior;
};

int main() {
    aluno *i, *a, *p;
    
    a = new aluno;
    i = a;
    a->matricula = 100;
    a->nome="João";
    a->nota=85;
    a->proximo=NULL;
    p=a;

    a = new aluno;
    p->proximo=a;
    a->matricula = 102;
    a->nome = "Maria";
    a->nota = 90;
    a->proximo = NULL;
    p=a;
 
    p=i;
    while(p != NULL) {
        cout << p->matricula << " / "
            << p->nome << " / "
            << p->nota << endl;

        p=p->proximo;
    }
    return 0;
}
