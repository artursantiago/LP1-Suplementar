#include "App.h"
#include "Estabelecimento.h"
#include "Cliente.h"
#include "Produto.h"
#include "Util.h"

#include <iostream>
#include <sstream>
#include <map>

App::App(std::map<std::string, std::string> configs) : estabelecimento(configs.find("path")->second), cliente(0)
{
  this->format = configs.find("default_format")->second;
  this->carrega_saldo_cliente();
}

App::~App()
{
}

int App::run(int argc, char const *argv[]) {
  std::string menu;
  menu.append("\n---------------------------------------\n");
  menu.append("#           Supermercado 1.0          #\n");
  menu.append("---------------------------------------\n");
  menu.append("\nSelecione uma ação:\n");
  menu.append("\t[1] Listar produtos disponíveis\n");
  menu.append("\t[2] Comprar um porduto\n");
  menu.append("\t[3] Ver sua sacola\n");
  menu.append("\t[4] Quit\n");
  menu.append("--> ");

  char action;
  bool sair = false;
  while (!sair) {
    std::cout << menu;
    std::cin >> action;
    std::cout << std::endl;

    switch (action) {
      case '1':
        this->list();
        break;
      case '2':
        this->compra();
        break;
      case '3':
        this->ver_sacola();
        break;
      case '4':
        this->cliente.registro(this->estabelecimento);

        std::cout << "Obrigado! Volte Sempre." << std::endl;
        sair = !proximo_cliente();
        break;
      default:
        std::cout << "Invalid Action. Please try again." << std::endl;
        break;
    }
  }
  return 0;
}

void App::list() {
    for (auto &&item : this->estabelecimento.estoque) {
      if (item.second == 0) {
        continue;
      }

      Produto* produto = this->estabelecimento.get_produto_by_codigo(item.first);

      std::string formated_message(this->format);
      std::string index_list;

      while ( formated_message.find("%") != std::string::npos && 
              index_list.find(formated_message.find("%")) == std::string::npos &&
              formated_message.find("%") != formated_message.length()-1) {
        size_t match_index = formated_message.find("%");
        index_list.push_back(match_index);
        
        if (formated_message[match_index + 1] == 'c') {
          formated_message.replace(match_index, 2, std::to_string(produto->codigo));
        } else if (formated_message[match_index + 1] == 'n') {
          formated_message.replace(match_index, 2, produto->nome);
        } else if (formated_message[match_index + 1] == 'p') {
          formated_message.replace(match_index, 2, Util::doubleToString(produto->preco));
        } else if (formated_message[match_index + 1] == 'u') {
          formated_message.replace(match_index, 2, produto->unidade_medida);
        }
      }
    
      std::cout << formated_message << std::endl;
    }
}

void App::compra() {
  int codigo;
  std::cout << "Informe o código do produto: ";
  // Ignora o texto do menu
  std::cin.ignore();
  std::cin >> codigo;

  Produto* p = this->estabelecimento.get_produto_by_codigo(codigo);
  if (p == nullptr) {
    std::cout << "Não foi possível encontrar um produto com o código informado." << std::endl;
    return;
  }

  try {
    this->cliente.compra(p);
    this->estabelecimento.venda(p->codigo);
  } catch(const std::exception& e) {
    std::cerr << e.what() << std::endl;
    return;
  }

  std::cout << "A venda do produto " << this->estabelecimento.get_produto_by_codigo(codigo)->nome << " foi realizada com sucesso!" << std::endl;
}

void App::ver_sacola() {

  if (this->cliente.sacola.size() == 0) {
    std::cout << "Sua sacola está vazia!" << std::endl; 
    return;
  }

  double total;

  std::cout << "________________SACOLA_________________" << std::endl; 
  
  for (auto &&item : this->cliente.sacola) {
    std::cout << this->estabelecimento.get_produto_by_codigo(item.first)->nome 
              << " - " << "x" << item.second
              << " - " << Util::doubleToString(this->estabelecimento.get_produto_by_codigo(item.first)->preco) << std::endl;
    total += (item.second * this->estabelecimento.get_produto_by_codigo(item.first)->preco);
  }
  std::cout << "_______________________________________" << std::endl; 
  std::cout << "TOTAL: " << Util::doubleToString(total) << std::endl; 
}

void App::carrega_saldo_cliente(bool proximo_cliente /*= false*/) {
  std::cout << "Bem Vindo ao Supermercado 1.0!" << std::endl;
  std::cout << "Informe o seu saldo para continuar(Ex: R$xx,xx): R$";
  std::string saldo;

  if (proximo_cliente) {
    std::cin.ignore();
  }

  std::getline(std::cin, saldo); 

  while (saldo.find(",") == std::string::npos || saldo.length()-1 - saldo.find(",") < 2) {
    std::cout << "Formato inválido! Por favor, informe o seu saldo novamente(Ex: R$xx,xx): R$";
    std::getline(std::cin, saldo); 
  }
  

  saldo.replace(saldo.find(","), 1, ".");
  std::stringstream stream(saldo);
  stream >> this->cliente.saldo;
}

bool App::proximo_cliente() {
  std::cout << "Próximo Cliente? [S]Sim [N]Não" << std::endl;
  std::cout << "R: ";

  char action;
  std::cin >> action;

  if (action == 'S') {
    Cliente novo_cliente(0);
    this->cliente = novo_cliente;
    this->carrega_saldo_cliente(true);
    return true;
  }
  else if (action == 'N') {
    return false;
  }
  else {
    std::cout << "Resposta inválida. Tente Novamente" << std::endl;
    return proximo_cliente();  
  }

}