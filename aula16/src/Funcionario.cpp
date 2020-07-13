#include "Funcionario.h"

#include <string>

Funcionario::Funcionario()
{
}

Funcionario::Funcionario(std::string nome, std::string departamento, double salario, std::string data_admissao)
  : nome(nome),
    departamento(departamento),
    salario(salario),
    data_admissao(data_admissao)
{
}