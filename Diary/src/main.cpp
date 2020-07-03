#include "../include/App.h"
#include "../include/Config.h"

#include <string>
#include <unordered_map> 
#include <iostream> 

int main(int argc, char *argv[]){
  // std::unordered_map<std::string, std::string> configs = read_config();
  
  App app(read_config());
  return app.run(argc, argv);
}
