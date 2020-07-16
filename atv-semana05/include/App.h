#if !defined(APP_H)
#define APP_H

#include "Estabelecimento.h"
#include "Cliente.h"

#include <vector>
#include <map>
#include <string>

class App
{
public:
  App(std::map<std::string, std::string> configs);
  ~App();

  /**/
  std::string format;
  Estabelecimento estabelecimento;
  Cliente cliente;

  int run(int argc, char const *argv[]);
  /**/
  void list();
  /**/
  void compra();
  /* Lista o conteúdo da sacola */
  void ver_sacola();

  /**/
  void carrega_saldo_cliente(bool proximo_cliente = false);
  bool proximo_cliente();
};

#endif // APP_H
