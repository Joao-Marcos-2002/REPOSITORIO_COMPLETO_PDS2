struct ExcecaoElementoRepetido {
    Tipo elemento;
}

template<typename Tipo>
class MeuConjunto : public std::set<Tipo> {
    public:
        void insert(Tipo k) {
          if (pertence(k)) {
            throw ExcecaoElementoRepetido(k);
          }
          set<Tipo>::insert(k);

          //pode retornar assim
          this->insert(k);
        }
};