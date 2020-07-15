#include "Agencia.h"

#include <string>

Agencia::Agencia() : numero(0), banco("")
{
}

Agencia::Agencia(int numero, std::string banco) : numero(numero), banco(banco) 
{
}