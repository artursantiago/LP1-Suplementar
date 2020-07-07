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
};

#endif // CLIENTE_H
