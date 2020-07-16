#include "Estabelecimento.h"
#include "App.h"
#include "Config.h"

int main(int argc, char const *argv[])
{
  // Estabelecimento("estoque.csv");
  App app(read_config());
  return app.run(argc, argv);
}
