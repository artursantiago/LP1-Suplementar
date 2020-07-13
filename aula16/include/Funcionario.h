#if !defined(FUNCIONARIO_H)
#define FUNCIONARIO_H

#include <string>

class Funcionario
{
private:
  std::string nome; 
  std::string departamento;
  double salario;
  std::string data_admissao;

public:
  Funcionario(); 
  Funcionario(std::string nome, std::string departamento, double salario, std::string data_admissao);


  std::string get_nome() {
    return nome;
  }

  void set_nome(std::string n) {
    nome = n;
  }

  std::string get_departamento() {
    return departamento;
  }

  void set_departamento(std::string d) {
    departamento = d;
  }

  double get_salario() {
    return salario;
  }

  void set_salario(double s) {
    salario = s;
  }

  std::string get_data_admissao() {
    return data_admissao;
  }

  void set_data_admissao(std::string d) {
    data_admissao = d;
  }

  };

#endif // FUNCIONARIO_H
