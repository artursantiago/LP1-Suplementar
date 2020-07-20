#include "Funcionario.h"

#include <string>

Funcionario::Funcionario() : nome(""), salario(0), cpf(""), dataAdmissao("")
{
}

Funcionario::Funcionario(std::string nome) : nome(nome), salario(0), cpf(""), dataAdmissao("")
{
}