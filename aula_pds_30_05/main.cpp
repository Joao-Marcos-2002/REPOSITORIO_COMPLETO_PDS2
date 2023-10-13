#include <iostream>
#include <assert.h>

using namespace std;

struct ParametrosInvalidos
{
    int num;
    int den;
};

// Precondicao: a e b maiores do que zero.
int dividir(int a, int b)
{
    assert(a >= 0);
    assert(b > 0);

  /**  UMA FORMA DE TRATAR A EXCESSAO com: throw
    if(b <= 0) {
        string tipo_erro("Erro de divisão por zero");
        throw tipo_erro;
    }    **/

    if(a < 0) {
        throw a;
    }
    int q = 0;

    while (a >= b)
    {
        a = a - b;
        q++;
    }
    assert(q >= 0);
    return q;
}

int main()
{
    try
    {
        int x, y;
        cin >> x >> y;
        int d = dividir(x, y);
        cout << d << endl;
    } catch(ParametrosInvalidos e) {
        cout << "Não é possivel dividir" << e.num << " por " << e.den << endl;
        exit(1);
    }
    catch(int e) {
        cout << e << "não é um numerador válido" << endl;
        exit(1);
    }
     catch(string s) {
        cout << s << endl;
        exit(1);
    } catch(...) {
        cout << "Erro desconhecido!" << endl;
        exit(1);
    }
    return 0;
}
