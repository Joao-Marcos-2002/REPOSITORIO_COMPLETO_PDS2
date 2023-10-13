int main() {
  ifstream fin("arquivo.txt"); 
  MeuConjunto<int> c;
  int x;
  while (fin >> x) {  
    try {
      c.insert(x);
    } catch (MeuConjunto<int>::ExcecaoElementoRepetido exc) {
      cout << exc.elemento << " já pertence ao conjunto!" << endl;
    } 
  }
   return 0;
}

