#if !defined(DIARY_H)
#define DIARY_H

#include "Message.h"

#include <vector>
#include <string>

struct Diary
{
  Diary(const std::string &filename);
  ~Diary();

  std::string filename;
  std::vector<Message> messages;

  std::vector<Message*> search(const std::string& what);
  void load();

  void add(const std::string &content);
  void add(const Message &message);
  void write();
};


#endif // DIARY_H
