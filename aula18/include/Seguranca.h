#if !defined(SEGURANCA_H)
#define SEGURANCA_H

#include "Funcionario.h"

class Seguranca : public Funcionario
{
private:
  bool plantao;

public:
  Seguranca();
  Seguranca(std::string nome, bool plantao);

  bool isPlantao() {
    return this->plantao;
  }
  void setPlantao(bool p) {
    this->plantao = p;
  }
};

#endif // SEGURANCA_H
