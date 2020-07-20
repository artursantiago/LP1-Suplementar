#if !defined(FUNCIONARIO_H)
#define FUNCIONARIO_H

#include <string>

class Funcionario
{
protected:
  std::string nome;
  double salario;
  std::string cpf;
  std::string dataAdmissao;
  
public:
  Funcionario();
  Funcionario(std::string nome);

  std::string getNome() {
    return this->nome;
  }
  void setNome(std::string n) {
    this->nome = n;
  }
  double getSalario() {
    return this->salario;
  }
  void setSalario(double s) {
    this->salario = s;
  }
  std::string getCpf() {
    return this->cpf;
  }
  void setCpf(std::string c) {
    this->cpf = c;
  }
  std::string getDataAdmissao() {
    return this->dataAdmissao;
  }
  void setDataAdmissao(std::string da) {
    this->dataAdmissao = da;
  }
};

#endif // FUNCIONARIO_H
