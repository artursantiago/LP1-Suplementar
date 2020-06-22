#include <iostream>
#include <fstream>
#include <string>

#include "../include/date_time.h"
#include "../include/diary.h"

/* Show the correct ways to use the program */
void correct_usage(std::string file_name);

int main(int argc, char const *argv[]) {
  std::ifstream input_file{"diary.md"};
  std::ofstream output_file{"diary.md", std::ios::app};

  if (!input_file.is_open() || !output_file.is_open()) {
    std::cerr << "File couldn't be opened." << std::endl;
    return 1;
  }
    
  switch (argc) {
    case 1:
      correct_usage(argv[0]);
      return 1; 

    case 2:
      if (std::string(argv[1]) == "add") {
        std::string message;
        std::cout << "Type the message to be stored: ";
        std::getline(std::cin, message);

        add(input_file, output_file, message);
        break;

      } else if (std::string(argv[1]) == "list") {
        list(input_file);
        break;
      } 
      correct_usage(argv[0]);
      return 1;

    case 3:
      if (std::string(argv[1]) == "add") {
        add(input_file, output_file, argv[2]);
      }
      correct_usage(argv[0]);
      return 1;
  }

  input_file.close();
  output_file.close();

  return 0;
}

void correct_usage(std::string file_name) {
  std::cout << "Command not found.\n" << std::endl
            << "Acceptable commands: " << std::endl 
            << " - List messages: " << file_name << " list" << std::endl
            << " - Add new message: " << file_name << " add <message> " << std::endl;
}
