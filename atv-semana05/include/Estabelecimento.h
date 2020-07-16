#if !defined(ESTABELECIMENTO_H)
#define ESTABELECIMENTO_H

#include "Produto.h"

#include <vector>
#include <map>

class Estabelecimento
{
private:
  std::string estoque_filename;

public:
  Estabelecimento(std::string estoque_filename);
  ~Estabelecimento();

  /** Cód. Produto <--> Quantidade */
  std::map<int, int> estoque;

  /** Cód. Produto <--> Quantidade */
  std::map<int, int> caixa;

  /** Lista de todos os produtos disponíveis e não disponíveis.*/
  std::vector<Produto> produtos;

  /** */
  Produto* get_produto_by_codigo(int codigo);

  /** */
  void venda(int codigo);

  /** */
  void registro_caixa();

  /** 
   * Carrega o estabelecimento com as informações
   * do arquivo de estoque
   */
  void load();

  /** */
  void update_estoque();
};

#endif // ESTABELECIMENTO_H
