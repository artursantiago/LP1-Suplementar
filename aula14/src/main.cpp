#include "Conta.h"
#include "Cliente.h"
#include "Agencia.h"

#include <iostream>

int main(int argc, char const *argv[])
{
  Agencia agencia(11111, "Nubank");

  Cliente cliente1("Artur Melo", "00000000000");
  Cliente cliente2("Samuel Gomes", "99999999999");

  Conta conta_cliente1(cliente1, agencia, 12345, 10500);
  Conta conta_cliente2(cliente2, agencia, 12345, 100500);

  std::cout << conta_cliente1.titular.nome <<" está sacando dinheiro. Seu saldo anterior era " << conta_cliente1.saldo << std::endl;
  conta_cliente1.sacar(1250);
  std::cout << "Seu novo saldo é " << conta_cliente1.saldo << std::endl;
  
  std::cout << conta_cliente1.titular.nome <<" está depositando dinheiro. Seu saldo anterior era " << conta_cliente1.saldo << std::endl;
  conta_cliente1.depositar(2550);
  std::cout << "Seu novo saldo é " << conta_cliente1.saldo << std::endl;

  std::cout << conta_cliente2.titular.nome <<" está transferindo dinheiro para " << conta_cliente1.titular.nome << std::endl 
            << "O saldo anterior de " << conta_cliente2.titular.nome << "era " << conta_cliente2.saldo << std::endl
            << "O saldo anterior de " << conta_cliente1.titular.nome << "era " << conta_cliente1.saldo << std::endl;
  conta_cliente2.transferir(10000, conta_cliente1);
  std::cout << "O saldo atual de " << conta_cliente2.titular.nome << "é " << conta_cliente2.saldo << std::endl
            << "O saldo atual de " << conta_cliente1.titular.nome << "é " << conta_cliente1.saldo << std::endl;

  return 0;
}
