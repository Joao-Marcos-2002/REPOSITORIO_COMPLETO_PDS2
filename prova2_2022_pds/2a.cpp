template<typename Tipo>
class MeuConjunto : public std::set<Tipo> {
public: 
  bool pertence(Tipo k) {

    return this->count(k) > 0;
  }
};

