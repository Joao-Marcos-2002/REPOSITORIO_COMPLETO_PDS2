class Animal {
    public:
        virtual void fale() {
            cout << "BIXO!" << endl;
        };
};

class Gato : public Animal {
    public:
    void fale() override {
        cout << "Miau" << endl;
    }
};

class Cachorro : public Animal {
    public:
    void fale() override {
        cout << "au au" << endl;
    }
};
