#include "Empresa.h"
#include "Funcionario.h"

#include <string>

Empresa::Empresa()
{
}

Empresa::Empresa(std::string nome, std::string cnpj) : nome(nome), cnpj(cnpj)
{
}

void Empresa::aumenta_salario(std::string departamento, double aumento) {
  for (auto &&f : this->funcionarios) {
    if (f.get_departamento() == departamento) {
      f.set_salario(f.get_salario()*aumento);
    }
  }
}