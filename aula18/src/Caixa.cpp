#include "Caixa.h"

#include <string>

Caixa::Caixa() : preferencial(false)
{
}

Caixa::Caixa(std::string nome, bool preferencial) : Funcionario(nome), preferencial(preferencial)
{
}