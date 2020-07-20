#if !defined(CONTA_H)
#define CONTA_H

#include "ClientePF.h"
#include "Agencia.h"

class Conta
{
public:
  Conta();
  Conta(ClientePF titular, Agencia agencia, int numero, double saldo);

  ClientePF titular;
  Agencia agencia;
  int numero;
  double saldo;
  static int total_contas;

  void sacar(double valor);
  void depositar(double valor);
  void transferir(double valor, Conta& destinatario);
};

#endif // CONTA_H
