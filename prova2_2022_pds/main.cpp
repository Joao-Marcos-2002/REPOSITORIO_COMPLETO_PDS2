class Operacao {
    public:
      virtual double executar(double x) = 0;
};

class Operacao : public Operacao {
    public:
        double executar(double x) {
            return x * x;
        }
}
