#if !defined(PRODUTO_H)
#define PRODUTO_H

#include <string>

class Produto
{
public:
  Produto();
  Produto(int codigo, std::string nome, std::string unidade_medida, double preco);

  int codigo;
  std::string nome;
  std::string unidade_medida;
  double preco;
};

#endif // PRODUTO_H
