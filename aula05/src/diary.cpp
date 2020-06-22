#include "../include/diary.h"
#include <string>
#include <iostream>
#include <fstream>

void list(Diary diary) {
  // for(Message message: diary.messages) {
  //     std::cout << "-" << message.content << std::endl;
  // }
}

void add(std::ofstream & output_file, Diary diary, std::string message) {
  // bool has_date = false;
  // bool is_empty = false;

  // if (input_file.peek() == std::ifstream::traits_type::eof()) {
  //     is_empty = true;
  // }

  // while (!input_file.eof()) {
  //   std::string aux;
  //   getline(input_file, aux);
  //   if (aux == "# " + get_current_date()) {
  //     has_date = true;
  //     break;
  //   }
  // }

  // if (!has_date) {
  //   output_file << (is_empty ? "" : "\n") << "# " << get_current_date() << "\n" << std::endl;
  // }
  // output_file << "- " << get_current_time() << " " << message << std::endl;
}

void read_store(std::ifstream & input_file, Diary diary) {
  // Message message;
  // std::string diary_line;

  // while (!input_file.eof()) {
  //   std::getline(input_file, diary_line);

  //   // Get only messages and show them
  //   if (content.size() != 0 && content.at(0) == '-') {
  //     std::string new_message(content, 10);
  //     std::cout << "-" << new_message << std::endl;
  //   }
    
  // }
}