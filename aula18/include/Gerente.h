#if !defined(GERENTE_H)
#define GERENTE_H

#include "Funcionario.h"

class Gerente : public Funcionario
{
private:
  std::string setorGerenciado;
public:
  Gerente();
  Gerente(std::string nome, std::string setorGerenciado);

  std::string getSetorGerenciado() {
    return this->setorGerenciado;
  }
  void setSetorGerenciado(std::string s) {
    this->setorGerenciado = s;
  }

};

#endif // GERENTE_H
