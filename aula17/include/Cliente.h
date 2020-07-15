#if !defined(CLIENTE_H)
#define CLIENTE_H

#include <string>

class Cliente
{
public:
  Cliente();
  Cliente(std::string nome, std::string cpf);

  std::string nome;
  std::string cpf;
  static int totalClientesPF;

  std::string getNome() {
    return this->nome;
  }
  void setNome(std::string n) {
    this->nome = n;
  }
  std::string getCpf() {
    return this->cpf;
  }
  void setCpf(std::string c) {
    this->cpf = c;
  }
};

#endif // CLIENTE_H
