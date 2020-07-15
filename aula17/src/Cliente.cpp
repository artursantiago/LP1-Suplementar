#include "Cliente.h"

#include <string>

int Cliente::totalClientesPF;

Cliente::Cliente() : nome(""), cpf("")
{
  this->totalClientesPF += 1;
}

Cliente::Cliente(std::string nome, std::string cpf) : nome(nome), cpf(nome)
{
  this->totalClientesPF += 1;
}