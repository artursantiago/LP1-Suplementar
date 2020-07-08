#if !defined(CARRO_H)
#define CARRO_H

#include "Motor.h"

#include <string>

class Carro{

public:
  Carro(std::string tipo, std::string placa, int numPortas, std::string cor);
  Carro();

  std::string tipo;
  std::string placa;
  int numPortas;
  int velocidade;
  std::string cor;
  Motor motor;

  static int total_carros;

  void acelera(int velocidade);
  void freia(int velocidade);
  void liga_carro();
};


#endif // CARRO_H
