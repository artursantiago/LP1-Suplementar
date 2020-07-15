#if !defined(CLIENTEPJ_H)
#define CLIENTEPJ_H

#include <string>

class ClientePJ
{
public:
  ClientePJ();
  ClientePJ(std::string razaoSocial, std::string cnpj);

  std::string razaoSocial;
  std::string cnpj;
  static int totalClientesPJ;

  std::string getRazaoSocial() {
    return this->razaoSocial;
  }
  void setRazaoSocial(std::string rs) {
    this->razaoSocial = rs;
  }
  std::string getCnpj() {
    return this->cnpj;
  }
  void setCnpj(std::string c) {
    this->cnpj = c;
  }
};

#endif // CLIENTEPJ_H
