#include "google_password.h"

#include <iostream>

using std::cout;
using std::endl;

void GooglePassword::insert(const string& url,
                            const string& login,
                            const string& password) {
    if (validPassword(password)) {
        Usuario usuario{login, password};
        passwords_.insert({url, usuario});
    }
}

void GooglePassword::remove(const string& url) {
    passwords_.erase(url);
}


 /**
   * Este metodo nao pode inserir novas credenciais, apenas atualizar as
   * ja existentes. Alem disso, o login e/ou senha do usuario so podem ser
   * atualizados se a senha armazenada no sistema for igual a old_password.
   * Nao esqueca de verificar se o novo password tambem e valido.
   */
void GooglePassword::update(const string& url,
                            const string& login,
                            const string& old_password,
                            const string& new_password) {




    if (validPassword(new_password)) {
        //busca caixa de memoria com essa url passada.
        auto it = passwords_.find(url);

        if (it != passwords_.end()) {
            if (it->second.password == old_password) {
                it->second.login = login;
                it->second.password = new_password;
            }
        }
    }
}

void GooglePassword::printPasswords() {
   int tam = passwords_.size();

    cout << tam << endl;
    for (const auto& [url, usuario] : passwords_) {
        cout << url << ": " << usuario.login << " and " << usuario.password << endl;
    }
}

bool GooglePassword::validPassword(const string& password) const {
    if (password.size() < 6)  return false;
    if (password.size() > 50) return false;
    for (const auto& c : password) {
        if (c == ' ') {
            return false;
        }
    }


    //se for '123456'
    return (password.find("123456") == string::npos);
}