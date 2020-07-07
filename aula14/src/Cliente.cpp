#include "Cliente.h"

#include <string>

Cliente::Cliente() : nome(""), cpf("")
{
}

Cliente::Cliente(std::string nome, std::string cpf) : nome(nome), cpf(nome)
{
}