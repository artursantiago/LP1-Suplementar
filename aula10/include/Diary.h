#if !defined(DIARY_H)
#define DIARY_H

#include "Message.h"

#include  <string>

struct Diary
{
  Diary(const std::string &filename);
  ~Diary();

  std::string filename;
  Message* messages;
  size_t messages_size;
  size_t messages_capacity;

  Message* search(const std::string& what);
  void load();

  void add(const std::string &content);
  void add(const Message &message);
  void increase_messages_capacity();
  void write();
};


#endif // DIARY_H
