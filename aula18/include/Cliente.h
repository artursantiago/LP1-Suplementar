#if !defined(CLIENTE_H)
#define CLIENTE_H

#include <string>

class Cliente
{
protected:
  std::string nome;
  
public:
  Cliente();
  Cliente(std::string nome);

  std::string getNome() {
    return this->nome;
  }
  void setNome(std::string n) {
    this->nome = n;
  }
};

#endif // CLIENTE_H
