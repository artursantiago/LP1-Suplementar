#include <iostream>
#include <fstream>
#include <string>

/* Show the list of the messages stored on the file in the same sequence */
void list(std::ifstream & input_file);

/* Add a new message(new line) in the end of the file */
void add(std::ifstream & input_file, std::ofstream & output_file, std::string message);

/* Show the correct ways to use the program */
void correct_usage(std::string file_name);

int main(int argc, char const *argv[]) {
  std::ifstream input_file{"diary.txt"}; // cin --
  std::ofstream output_file{"diary.txt", std::ios::app}; //cout

  if (!input_file.is_open() || !input_file.is_open()) {
    std::cerr << "File couldn't be opened.";
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

    } else if (std::string(argv[1]) == "list") {
      list(input_file);
    }
    break;

  case 3:
    if (std::string(argv[1]) != "add") {
      correct_usage(argv[0]);
      return 1;
    }

    add(input_file, output_file, argv[2]);

    break;
  }

  input_file.close();
  output_file.close();

  return 0;
}


void list(std::ifstream & input_file) {

  std::string message = "";

  while (!input_file.eof()) {
    std::getline(input_file, message);
    if (message.size() == 0) {
      continue;
    }
    std::cout << message << std::endl;
  }  
}

void add(std::ifstream & input_file, std::ofstream & output_file, std::string message) {
    char c;

    /* If the user manipulates the file manually, the end of file could not be the \n */
    input_file.seekg(-1, std::ios_base::end);
    input_file.get(c);
    if (c != '\n') {
      output_file << "\n" << message << std::endl;
    } else {
      output_file << message << std::endl;
    }
}

void correct_usage(std::string file_name) {
  std::cout << "Command not found.\n" << std::endl
            << "Acceptable commands: " << std::endl 
            << " - List messages: " << file_name << " list" << std::endl
            << " - Add new message: " << file_name << " add <message> " << std::endl;
}
