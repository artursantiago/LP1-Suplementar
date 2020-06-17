#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
  std::string message = "";

  std::ofstream output_file{"output.txt"};

  if (argc == 1 || (argc >= 2 && std::string(argv[1]) != "add")) {
    std::cout << "CORRECT USE: " << argv[0] << " add <message> \nOR: " << argv[0] << " add \n";
    return 1;
  }
  
  if (argc > 2) {
    message = argv[2];
  } else {
    std::cout << "Type the message to be stored: ";
    getline(std::cin, message);
  }
  
  output_file << message;
  output_file.close();

  std::cout << "The message was sucessfully stored!\n";

  return 0;
}
