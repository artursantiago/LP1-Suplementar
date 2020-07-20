#include "Seguranca.h"

#include <string>

Seguranca::Seguranca() : plantao(false)
{
}

Seguranca::Seguranca(std::string nome, bool plantao) : Funcionario(nome), plantao(plantao)
{
}