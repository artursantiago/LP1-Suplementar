#if !defined(CONFIG_H)
#define CONFIG_H

#include <unordered_map>
#include <string>

std::unordered_map<std::string, std::string> read_config();
std::unordered_map<std::string, std::string> create();

#endif // CONFIG_H
