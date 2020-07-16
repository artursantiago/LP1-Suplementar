#include "Config.h"

#include <fstream>
#include <sstream>
#include <string> 
#include <map> 

std::map<std::string, std::string> read_config() {
  std::ifstream config_file("supermercado.config");
  std::map<std::string, std::string> configs;

  if (!config_file.is_open()) {
    return create();
  }

  std::string line;
  char discard;
  std::string key;
  std::string value;

  while(!config_file.eof()) {
    std::getline(config_file, line);
    std::stringstream stream(line);

    stream >> key;
    stream >> discard;
    std::getline(stream, value);
    value.erase(0, 1);

    configs.insert({key, value});
  }
  return configs;
}

std::map<std::string, std::string> create() {
  std::ofstream config_file("supermercado.config");

  config_file << "path = estoque.csv" << std::endl;
  config_file << "default_format = [%c] %n %p/%u" << std::endl;

  return std::map<std::string, std::string>
  {
    {"path", "estoque.csv"},
    {"default_format", "[%c] %n %p/%u"}
  };
}
