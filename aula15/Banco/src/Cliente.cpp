#include "Cliente.h"

#include <string>

int Cliente::total_clientes;

Cliente::Cliente() : nome(""), cpf("")
{
  this->total_clientes += 1;
}

Cliente::Cliente(std::string nome, std::string cpf) : nome(nome), cpf(nome)
{
  this->total_clientes += 1;
}