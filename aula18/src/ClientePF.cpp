#include "ClientePF.h"

#include <string>

int ClientePF::totalClientesPF;

ClientePF::ClientePF() : cpf("")
{
  this->totalClientesPF += 1;
}

ClientePF::ClientePF(std::string nome, std::string cpf) : Cliente(nome), cpf(nome)
{
  this->totalClientesPF += 1;
}