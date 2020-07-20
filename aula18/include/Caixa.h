#if !defined(CAIXA_H)
#define CAIXA_H

#include "Funcionario.h"

class Caixa : public Funcionario
{
private:
  bool preferencial;
public:
  Caixa();
  Caixa(std::string nome, bool preferencial);

  bool isPreferencial() {
    return this->preferencial;
  }
  void setPreferencial(bool p) {
    this->preferencial = p;
  }
};

#endif // CAIXA_H
