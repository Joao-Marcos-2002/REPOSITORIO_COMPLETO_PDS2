class Operacao {
    public:
        virtual double executar(double x);
}

void Mapear(list<double>& l; Operacao* op) {
    // Primeira forma;
    for (auto& item : l) {
        item = op->executar(item);
    }

    // Segunda forma:
    for (auto it = l.begin(); it != l.end(); it++) {
        it = op->executar(item);
    }
}
