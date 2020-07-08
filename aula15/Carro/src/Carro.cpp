#include "Carro.h"

#include <string>

int Carro::total_carros;

Carro::Carro(std::string tipo, std::string placa, int numPortas, std::string cor) 
  : tipo(tipo), 
    placa(placa), 
    numPortas(numPortas), 
    cor(cor)
{
  this->total_carros += 1;
}

Carro::Carro() : cor("Branco")
{
  this->total_carros += 1;
}

void Carro::acelera(int velocidade) {
  this->velocidade += velocidade;
}

void Carro::freia(int velocidade) {
  this->velocidade -= velocidade;
}

void Carro::liga_carro() {
  this->motor.partida();
}
