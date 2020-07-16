#include "Produto.h"

#include <string>
#include <sstream>
#include <iostream>

Produto::Produto() 
  : codigo(0), 
    nome(""),
    unidade_medida(""),
    preco(0)
{
}

Produto::Produto(int condigo, std::string nome, std::string unidade_medida, double preco)
  : codigo(codigo),
    nome(nome),
    unidade_medida(unidade_medida),
    preco(preco)
{
}