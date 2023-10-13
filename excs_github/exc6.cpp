#include <iostream>

using namespace std;

int main() {
    double r, a;
    double pi = 3.14;

    cout << "Digite o raio do circulo:" << endl;
    cin >> r;
    a = pi*(r*r);
    cout << "A area do circulo eh: " << a;
}