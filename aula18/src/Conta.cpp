#include "Conta.h"
#include "ClientePF.h"
#include "Agencia.h"

int Conta::total_contas;

Conta::Conta() : titular(), agencia(), numero(0), saldo(0)
{
  this->total_contas += 1;
}

Conta::Conta(ClientePF titular, Agencia agencia, int numero, double saldo) 
  : titular(titular), 
    agencia(agencia), 
    numero(numero), 
    saldo(saldo)
{
  this->total_contas += 1;
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