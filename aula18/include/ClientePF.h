#if !defined(CLIENTEPF_H)
#define CLIENTEPF_H

#include "Cliente.h"

#include <string>

class ClientePF : public Cliente
{
public:
  ClientePF();
  ClientePF(std::string nome, std::string cpf);

  std::string cpf;
  static int totalClientesPF;

  std::string getCpf() {
    return this->cpf;
  }
  void setCpf(std::string c) {
    this->cpf = c;
  }
};

#endif // CLIENTEPF_H
