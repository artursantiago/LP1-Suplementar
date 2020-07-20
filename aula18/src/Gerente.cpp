#include "Gerente.h"

#include <string>

Gerente::Gerente() : setorGerenciado("")
{
}

Gerente::Gerente(std::string nome, std::string setSetorGerenciado) : Funcionario(nome), setorGerenciado(setorGerenciado)
{
}