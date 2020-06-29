#include "../include/App.h"
#include "../include/Diary.h"

#include <iostream>
#include <string>

App::App(const std::string &filename) try : diary(filename)
{
} catch(const std::exception &e) {
  std::cerr << e.what() << std::endl;
  delete[] diary.messages;
  exit(1);
}

int App::run(int argc, char* argv[]){
  if(argc == 1){
    return show_usage(argv[0]);
  }

  std::string action = argv[1];

  if (action == "add") {
    if (argc == 2) {
      add();
    } else {
      add(argv[2]);
    }
  } else if (action == "list") {
    list_messages();
  } else {
    return show_usage(argv[0]);
  }

  return 0;
}

void App::add() {
  std::string message;
  std::cout << "Enter your message: " << std::endl;
  std::getline(std::cin, message);

  add(message);
}

void App::add(const std::string &message) {
  diary.add(message);
  diary.write();
}

void App::list_messages() {
  for (size_t i = 0; i < diary.messages_size; ++i) {
    if (!(i > 0 && diary.messages[i-1].date.is_equal(diary.messages[i].date))) {
      std::cout << (i == 0 ? "" : "\n")<< "# " << diary.messages[i].date.to_string() << std::endl;
    }
    std::cout << "- " << diary.messages[i].time.to_string() << " " << diary.messages[i].content << std::endl;
  }
}

int App::show_usage(const std::string &filename) {
  std::cout << "Command not found.\n" << std::endl
            << "Acceptable commands: " << std::endl 
            << " - List messages: " << filename << " list" << std::endl
            << " - Add new message: " << filename << " add <message> " << std::endl;
  return 1;
}