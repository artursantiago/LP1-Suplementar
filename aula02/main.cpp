#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
  std::string message = "";

  if (argc == 1 || (argc >= 2 && std::string(argv[1]).compare("add") != 0)) {
    std::cout << "CORRECT USE: " << argv[0] << " add <message> \nOR: " << argv[0] << " add \n";
    return 1;
  }

  if (argc > 2) {
    message.append(argv[2]);
    std::cout << "The message \"" << argv[2] << "\" was sucessfully stored!\n";
  } else {
    std::cout << "Type the message to be stored: ";
    getline(std::cin, message);
    std::cout << "The message was sucessfully stored!\n";
  }
  
  return 0;
}
