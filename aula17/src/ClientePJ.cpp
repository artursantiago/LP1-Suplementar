#include "ClientePJ.h"

#include <string>

int ClientePJ::totalClientesPJ;

ClientePJ::ClientePJ() : razaoSocial(""), cnpj("")
{
  this->totalClientesPJ += 1;
}

ClientePJ::ClientePJ(std::string razaoSocial, std::string cnpj) : razaoSocial(razaoSocial), cnpj(razaoSocial)
{
  this->totalClientesPJ += 1;
}