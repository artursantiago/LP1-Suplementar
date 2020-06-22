#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

/* Show the list of the messages stored on the file in the same sequence */
void list(std::ifstream & input_file);

/* Add a new message(new line) in the end of the file */
void add(std::ifstream & input_file, std::ofstream & output_file, std::string message);

/* Show the correct ways to use the program */
void correct_usage(std::string file_name);

/* Maniuplates date and time */
std::string format_current_date(const std::string &format);
std::string get_current_date();
std::string get_current_time();

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

void list(std::ifstream & input_file) {
  std::string message;

  while (!input_file.eof()) {
    std::getline(input_file, message);

    // Get only messages and show them
    if (message.size() != 0 && message.at(0) == '-') {
      std::string new_message(message, 10);
      std::cout << "-" << new_message << std::endl;
    }
    
  }  
}

void add(std::ifstream & input_file, std::ofstream & output_file, std::string message) {
  bool has_date = false;
  bool is_empty = false;

  if (input_file.peek() == std::ifstream::traits_type::eof()) {
      is_empty = true;
  }

  while (!input_file.eof()) {
    std::string aux;
    getline(input_file, aux);
    if (aux == "# " + get_current_date()) {
      has_date = true;
      break;
    }
  }

  if (!has_date) {
    output_file << (is_empty ? "" : "\n") << "# " << get_current_date() << "\n" << std::endl;
  }
  output_file << "- " << get_current_time() << " " << message << std::endl;
}

void correct_usage(std::string file_name) {
  std::cout << "Command not found.\n" << std::endl
            << "Acceptable commands: " << std::endl 
            << " - List messages: " << file_name << " list" << std::endl
            << " - Add new message: " << file_name << " add <message> " << std::endl;
}

std::string format_current_date(const std::string &format) {
  std::time_t time = std::time(nullptr);
  char result[1024];

  std::strftime(result, sizeof(result), format.c_str(), std::localtime(&time));

  return std::string(result);
}

std::string get_current_date() { return format_current_date("%d/%m/%Y"); }

std::string get_current_time() { return format_current_date("%H:%M:%S"); }
