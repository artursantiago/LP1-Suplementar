#include "Conta.h"
#include "Cliente.h"
#include "Agencia.h"

Conta::Conta() : titular(), agencia(), numero(0), saldo(0)
{
}

Conta::Conta(Cliente titular, Agencia agencia, int numero, double saldo) 
  : titular(titular), 
    agencia(agencia), 
    numero(numero), 
    saldo(saldo)
{
}

void Conta::sacar(double valor) {
  this->saldo -= valor;
}

void Conta::depositar(double valor) {
  this->saldo += valor;
}

void Conta::transferir(double valor, Conta& destinatario) {
  this->saldo -= valor;
  destinatario.depositar(valor);
}