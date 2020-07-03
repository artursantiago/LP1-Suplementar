#include "../include/Config.h"

#include <fstream>
#include <sstream>
#include <string> 
#include <unordered_map> 

std::unordered_map<std::string, std::string> read_config() {
  std::ifstream config_file("diary.config");
  std::unordered_map<std::string, std::string> configs;

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

std::unordered_map<std::string, std::string> create() {
  std::ofstream config_file("diary.config");

  config_file << "path = diary.md" << std::endl;
  config_file << "default_format = [%d %t] %m" << std::endl;

  return std::unordered_map<std::string, std::string>
  {
    {"path", "diary.md"},
    {"default_format", "[%d %t] %md"}
  };
}
