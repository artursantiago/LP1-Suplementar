#if !defined(APP_H)
#define APP_H

#include "Diary.h"

#include <string>
#include <unordered_map>

struct App
{
  Diary diary;
  std::string format;

  App(std::unordered_map<std::string, std::string> configs);
  int run(int argc, char* argv[]);

  void add(bool interactive = false);
  void add(const std::string &content);
  void list_messages();
  void list_messages(const std::vector<Message*>& messages);
  void search(const std::string& what);
  int show_usage(const std::string &filename);
  int interactive_menu();
};

#endif // APP_H
