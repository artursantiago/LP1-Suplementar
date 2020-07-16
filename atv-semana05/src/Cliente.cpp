#include "Cliente.h"
#include "Estabelecimento.h"
#include "Util.h"

#include <string>
#include <fstream>

size_t Cliente::total_clientes;

Cliente::Cliente(double saldo) : saldo(saldo), id(total_clientes+1)
{
  total_clientes += 1;
}

Cliente::~Cliente()
{
}

void Cliente::compra(Produto* produto, int quantidade /*= 1*/) {
  if (produto->preco * quantidade > this->saldo) {
    throw std::domain_error("Saldo insuficiente para realizar a compra. Seu saldo é " + Util::doubleToString(this->saldo));
  }

  // Se já foi comprado alguma unidade do produto, apenas incrementa no caixa
  for (auto &&item_comprado : this->sacola) {
    if (item_comprado.first == produto->codigo) {
      item_comprado.second++;
      return;
    }
  }
  this->sacola.insert({produto->codigo, quantidade});
}

void Cliente::registro(Estabelecimento& e) {
  if (this->sacola.size() == 0) {
    return;
  }

  double total;
  std::ofstream file("cliente_" + std::to_string(this->id) + ".csv");
  file << "PRODUTO,QUANTIDADE,PREÇO" << std::endl; 
  
  for (auto &&item : this->sacola) {
    file << e.get_produto_by_codigo(item.first)->nome << ","
         << item.second << ","
         << Util::doubleToString(e.get_produto_by_codigo(item.first)->preco, true) << std::endl;

    total += (item.second * e.get_produto_by_codigo(item.first)->preco);
  }
  file << "TOTAL,," << Util::doubleToString(total,true) << std::endl; 

  file.close();
}