int main() {
   Complexo x(a, b);
   try {
      double a, b;
      cin >> a >> b;
      x = x.inverso();
      cout << x.real() << " + " << x.imag() << endl;
   } catch (ExcecaoDivisaoPorZero) {
      cout << "Erro de divisão por zero!" << endl;
   } 
   return 0;
}

