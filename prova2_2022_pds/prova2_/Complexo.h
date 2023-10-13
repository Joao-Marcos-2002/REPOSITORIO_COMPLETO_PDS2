class Complexo {

struct ExcecaoDivisaoPorZero {}

 public:
  // Cria o número complexo a + bi.
  Complexo(double a, double b);

  // Retorna a parte real do número complexo.
  double real();

  // Retorna a parte imaginária do número complexo.
  double imag();

  // Retorna o simétrico do número complexo.
  Complexo simetrico();

  // Retorna o inverso multiplicativo do número complexo.
  Complexo inverso();



Complexo operator+(Complexo y);
Complexo operator*(Complexo y);
Complexo operator/(Complexo y);
Complexo operator-();
Complexo operator-(Complexo y);




private:
  double real_; // Parte real.
  double imag_; // Parte imaginária. 


}