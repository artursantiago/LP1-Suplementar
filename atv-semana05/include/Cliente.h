#if !defined(CLIENTE_H)
#define CLIENTE_H 

#include "Produto.h"
#include "Estabelecimento.h"

#include <string>
#include <map>

class Cliente
{
public:
  Cliente(double saldo);
  ~Cliente();

  static size_t total_clientes;

  double saldo;
  int id;

  /* Cod.Produto <--> Quantidade */
  std::map<int, int> sacola;

  /* Efetua a compra de um produto caso o cliente tenha saldo suficiente */
  void compra(Produto* Produto, int quantidade = 1);
  void registro(Estabelecimento& e);
};

#endif // CLIENTE_H
