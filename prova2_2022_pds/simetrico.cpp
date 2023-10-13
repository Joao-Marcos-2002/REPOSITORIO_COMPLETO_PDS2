// questao 2 - prova 2 de PDS.

class Operacao {
    public:
    virtual double executar(double x);
};

class Simetrico : public Operacao {
    public:
    double executar(double x) {
        return -x;
    }
}
