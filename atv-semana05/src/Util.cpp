#include "Util.h"

#include <string>
#include <sstream>

double Util::stringToDouble(std::string value_s) {
  char discard;
  std::string aux;
  double value_d;

  std::stringstream stream(value_s);
  stream >> discard >> discard >> discard;

  std::getline(stream, aux);

  aux.erase(0, 1);
  aux.erase(aux.length()-1);
  aux.replace(aux.find(","), 1, ".");

  std::stringstream().swap(stream);
  stream << aux;
  stream >> value_d;
  return value_d;
}

std::string Util::doubleToString(double value_d, bool comAspas /*= false*/) {
  std::stringstream stream;
  stream << (comAspas ? "\"R$ " : "R$") << value_d << (comAspas ? "\"" : "");

  std::string value_s = stream.str();
  
  size_t pos = value_s.find(".");
  
  if (pos == std::string::npos) {
    value_s.replace(value_s.length() - (comAspas ? 1 : 0), 0, ",00");
    return value_s;
  }

  value_s.replace(pos, 1, ",");

  // Retira-se 2 do tamanho caso comAspas = true (aumenta o tamanho da string)
  if (value_s.length()-1 - (comAspas ? 1 : 0) - pos < 2) {
    value_s.replace(value_s.length() - (comAspas ? 1 : 0), 0, "0");
  }
  
  return value_s;
}