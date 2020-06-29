#if !defined(APP_H)
#define APP_H

#include "Diary.h"

#include <string>

struct App
{
  Diary diary;

  App(const std::string &filename);
  
  int run(int argc, char* argv[]);
  void add();
  void add(const std::string &message);
  void list_messages();
  int show_usage(const std::string &filename);
   
};



#endif // APP_H
