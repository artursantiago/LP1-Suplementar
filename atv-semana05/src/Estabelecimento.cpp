#include "Estabelecimento.h"
#include "Util.h"

#include <string>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <iostream>

Estabelecimento::Estabelecimento(std::string estoque_filename) : estoque_filename(estoque_filename)
{
  try {
    this->load();
  } catch(const std::exception& e) {
    std::cerr << e.what() << '\n';
    exit(1);
  }
}

Estabelecimento::~Estabelecimento()
{
  this->registro_caixa();
  this->update_estoque();
}

Produto* Estabelecimento::get_produto_by_codigo(int codigo) {
  for (size_t i = 0; i < this->produtos.size(); i++) {
    if (this->produtos[i].codigo == codigo) {
      return &this->produtos[i];
    }  
  }
  return nullptr;
}

void Estabelecimento::venda(int codigo) {
  for (auto &&item : this->estoque) {
    if (item.first == codigo) {
      if (item.second == 0) {
        throw std::domain_error("O produto " + this->get_produto_by_codigo(codigo)->nome + " não está mais disponível!");
      }
      item.second--;

      // Se já foi vendida alguma unidade do produto, apenas incrementa no caixa
      for (auto &&item_vendido : this->caixa) {
        if (item_vendido.first == item.first) {
          item_vendido.second++;
          return;
        }
      }
      // Se é a primeira unidade do produto a ser vendida, insere um novo pair no caixa
      this->caixa.insert({item.first, 1});
    }
  }
  
}

void Estabelecimento::registro_caixa() {
  if (this->caixa.size() == 0) {
    return;
  }

  std::ofstream file("caixa.csv");
  double total;

  file << "COD,PRODUTO,PREÇO,QUANTIDADE" << std::endl; 
  for (auto &&item : this->caixa) {
    file << this->get_produto_by_codigo(item.first)->codigo << "," 
         << this->get_produto_by_codigo(item.first)->nome << "," 
         << Util::doubleToString(this->get_produto_by_codigo(item.first)->preco, true) << ","
         << item.second << std::endl;
    total += (item.second * this->get_produto_by_codigo(item.first)->preco);
  }

  file << "TOTAL,," <<  Util::doubleToString(total, true) << "," << std::endl; 
  
  file.close();
}

void Estabelecimento::load() {
  std::ifstream file(this->estoque_filename);

  if (!file.is_open() || file.fail()) {
    throw std::runtime_error("O arquivo não existe no caminho especificado em \"supermercado.config\".");
    return;
  }
  
  std::string line;
  while (!file.eof()) {
    Produto produto;
    int quantidade;

    std::getline(file, line);

    // Pula para a próxima linha caso a linha não comece com um número(Cabeçalho)
    if (!isdigit(line[0])) {
      continue;
    }

    std::string delimiter = ",";
    size_t pos = 0;
    std::stringstream stream;
    size_t coluna = 1;
    while ((pos = line.find(delimiter)) != std::string::npos) {
      //Quando encontra a vírgula dentro do preço do produto
      if (pos != 0 && isdigit(line[pos+1]) && isdigit(line[pos-1])) {
        pos += 4;
      }

      stream << line.substr(0, pos);
      
      switch (coluna) {
        case 1:
          stream >> produto.codigo;
          break;
        case 2:
          produto.nome = stream.str();
          break;
        case 3:
          produto.unidade_medida = stream.str();
          break;
        case 4:
          produto.preco = Util::stringToDouble(stream.str());
          break;
      }

      line.erase(0, pos + delimiter.length());
      coluna++;
      std::stringstream().swap(stream);

      if (coluna == 5) {
        stream << line;
        stream >> quantidade;
      }
    }

    this->produtos.push_back(produto);
    this->estoque.insert({produto.codigo, quantidade});
  }

  file.close();
}

void Estabelecimento::update_estoque() {
  std::ofstream file(this->estoque_filename);

  file << "COD,PRODUTO,UNIDADE DE MEDIDA,PREÇO,QUANTIDADE" << std::endl; 
  for (auto &&item : this->estoque) {
    file << this->get_produto_by_codigo(item.first)->codigo << "," 
         << this->get_produto_by_codigo(item.first)->nome << "," 
         << this->get_produto_by_codigo(item.first)->unidade_medida << "," 
         << Util::doubleToString(this->get_produto_by_codigo(item.first)->preco, true) << ","
         << item.second << std::endl;
  }
  
  file.close();
}