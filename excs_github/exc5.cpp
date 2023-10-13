#include <iostream>

using namespace std;

int main() {
    int espaco, espConvertido;

    cout << "Digite o espaco em metros:";
    cin >> espaco;

    //converter metro para centimetro.
    espConvertido = espaco * 100;
    cout << "O espaco em metros eh: " << espConvertido << "cm.";


}