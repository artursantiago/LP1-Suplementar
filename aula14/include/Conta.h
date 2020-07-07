#if !defined(CONTA_H)
#define CONTA_H

#include "Cliente.h"
#include "Agencia.h"

class Conta
{
public:
  Conta();
  Conta(Cliente titular, Agencia agencia, int numero, double saldo);

  Cliente titular;
  Agencia agencia;
  int numero;
  double saldo;

  void sacar(double valor);
  void depositar(double valor);
  void transferir(double valor, Conta& destinatario);
};

#endif // CONTA_H
