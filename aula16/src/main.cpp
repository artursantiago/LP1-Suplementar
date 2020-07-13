#include "Empresa.h"
#include "Funcionario.h"

#include <iostream>

void list_funcionarios(Empresa &e);

int main(int argc, char const *argv[])
{
  Empresa empresa("Emprexa X", "42.318.949/0001-84");

  std::cout << "Quantos funcionários deseja adicionar? ";
  int qtd_funcionarios;
  std::cin >> qtd_funcionarios;

  for (size_t i = 1; i <= qtd_funcionarios; ++i) {
    std::string nome; 
    std::string departamento;
    double salario;
    std::string data_admissao;

    std::cout << "Qual o nome do " << i << "º funcionário? ";
    std::cin.ignore();
    std::getline(std::cin, nome);

    std::cout << "Qual o departamento do " << i << "º funcionário? ";
    std::getline(std::cin, departamento);

    std::cout << "Qual o salario do " << i << "º funcionário? ";
    std::cin >> salario;

    std::cout << "Qual a data de admissão do " << i << "º funcionário? ";
    std::cin.ignore();
    std::getline(std::cin, data_admissao);
    
    Funcionario funcionario(nome, departamento, salario, data_admissao);
    empresa.get_funcionarios().push_back(funcionario);
  }

  std::cout << "Qual departamernto deseja implementar o aumento de 10%? ";
  std::string departamento;
  std::getline(std::cin, departamento);

  empresa.aumenta_salario(departamento, 1.10);
  
  list_funcionarios(empresa);
  
  return 0;
}


void list_funcionarios(Empresa &e) {
  for (auto &&f : e.get_funcionarios()) {
    std::cout << std::endl;
    std::cout << "Nome: " << f.get_nome() << std::endl;
    std::cout << "Departamento: " << f.get_departamento() << std::endl;
    std::cout << "Salário: " << f.get_salario() << std::endl;
    std::cout << "Data de Admissão: " << f.get_data_admissao() << std::endl;
    std::cout << std::endl;
  }
}