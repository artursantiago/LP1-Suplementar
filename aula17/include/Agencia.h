#if !defined(AGENCIA_H)
#define AGENCIA_H

#include <string>

class Agencia
{
public:
  Agencia();
  Agencia(int numero, std::string banco);

  int numero;
  std::string banco;
};

#endif // AGENCIA_H
