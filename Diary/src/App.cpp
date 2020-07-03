#include "../include/App.h"
#include "../include/Diary.h"
#include "../include/Config.h"

#include <iostream>
#include <locale>
#include <sstream>
#include <string>
#include <unordered_map> 

App::App(std::unordered_map<std::string, std::string> configs) : diary(configs.find("path")->second)
{
  format = configs.find("default_format")->second;
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
      add(std::string(argv[2]));
    }
  } else if (action == "list") {
    if (argc > 2) {
      format = argv[2];
    } 
      list_messages();
  } else if (action == "search") {
      if (argc == 2) {
        show_usage(argv[0]);
      } else {
        try {
          search(argv[2]);
        } catch(const std::exception& e) {
          std::cerr << e.what() << std::endl;
          return 1;
      }
    }

  } else if(action == "interactive") {
    return interactive_menu();
  } else {
    return show_usage(argv[0]);
  }
  return 0;
}

void App::add(bool interactive /*=false*/) {
  std::string content;
  std::cout << "Enter your message: ";

  if (interactive == true) {
    // Ignore the interactive menu
    std::cin.ignore();
  }

  std::getline(std::cin, content);

  add(content);
}

void App::add(const std::string &content) {
  diary.add(content);
}

void App::list_messages() {

  for (Message message : diary.messages) {
    std::string formated_message(format);
    std::string index_list;

    while ( formated_message.find("%") != std::string::npos && 
            index_list.find(formated_message.find("%")) == std::string::npos &&
            formated_message.find("%") != formated_message.length()-1) {
      size_t match_index = formated_message.find("%");
      index_list.push_back(match_index);
      
      if (formated_message[match_index + 1] == 'd') {
        formated_message.replace(match_index, 2, message.date.to_string());
      } else if (formated_message[match_index + 1] == 't') {
        formated_message.replace(match_index, 2, message.time.to_string());
      } else if (formated_message[match_index + 1] == 'm') {
        formated_message.replace(match_index, 2, message.content);
      }
    }
    
    std::cout << formated_message << std::endl;
  }
}

void App::list_messages(const std::vector<Message*>& messages) {

  for (Message* message : messages) {
    std::string formated_message(format);
    std::string index_list;

    while ( formated_message.find("%") != std::string::npos && 
            index_list.find(formated_message.find("%")) == std::string::npos &&
            formated_message.find("%") != formated_message.length()-1) {
      size_t match_index = formated_message.find("%");
      index_list.push_back(match_index);
      
      if (formated_message[match_index + 1] == 'd') {
        formated_message.replace(match_index, 2, message->date.to_string());
      } else if (formated_message[match_index + 1] == 't') {
        formated_message.replace(match_index, 2, message->time.to_string());
      } else if (formated_message[match_index + 1] == 'm') {
        formated_message.replace(match_index, 2, message->content);
      }
    }
    
    std::cout << formated_message << std::endl;
  }
}

void App::search(const std::string& what) {
 std::vector<Message*> match_messages = diary.search(what);
  
  if (match_messages.empty()) {
    throw std::logic_error("Message not found.");
  }

  list_messages(match_messages);
}

int App::show_usage(const std::string &filename) {
  std::cout << "Command not found.\n" << std::endl
            << "Acceptable commands: " << std::endl 
            << " - List messages: " << filename << " list <format>" << std::endl
            << " - Add new message: " << filename << " add <message> " << std::endl
            << " - Search for message containing substring: " << filename << " search <substring> " << std::endl
            << " - Open interactive mode: " << filename << " interactive" << std::endl;
  return 1;
}

int App::interactive_menu() {
  std::string menu;
  menu.append("\n---------------------------\n");
  menu.append("#        Diary 1.0        #\n");
  menu.append("---------------------------\n");
  menu.append("\nSelect your action:\n");
  menu.append("\t[1] List messages\n");
  menu.append("\t[2] Add new message\n");
  menu.append("\t[3] Quit\n");
  menu.append("--> ");

  char action;
  while (action != '3') {
    std::cout << menu;
    std::cin >> action;
    std::cout << std::endl;

    switch (action) {
      case '1':
        list_messages();
        break;
      case '2':
        add(true);
        break;
      case '3':
        break;
      default:
        std::cout << "Invalid Action. Please try again." << std::endl;
        break;
    }
  }
  std::cout << "See ya!" << std::endl;
  return 0;
}