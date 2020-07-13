#if !defined(EMPRESA_H)
#define EMPRESA_H

#include "Funcionario.h"

#include <string>
#include <vector>

class Empresa
{
private:
  std::string nome;
  std::string cnpj;
  std::vector<Funcionario> funcionarios;

public:
  Empresa();
  Empresa(std::string nome, std::string cnpj);

  void aumenta_salario(std::string departamento, double aumento);

  std::string get_nome() {
    return nome;
  }

  void set_nome(std::string n) {
    nome = n;
  }

  std::string get_cnpj() {
    return cnpj;
  }

  void set_cnpj(std::string c) {
    cnpj = c;
  }

  std::vector<Funcionario> &get_funcionarios() {
    return funcionarios;
  }

  void set_funcionarios(std::vector<Funcionario> f) {
    funcionarios = f;
  }

};

#endif // EMPRESA_H
