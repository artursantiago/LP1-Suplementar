#if !defined(CONFIG_H)
#define CONFIG_H

#include <map>
#include <string>

std::map<std::string, std::string> read_config();
std::map<std::string, std::string> create();

#endif // CONFIG_H
