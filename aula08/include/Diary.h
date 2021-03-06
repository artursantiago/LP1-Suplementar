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

  void add(const std::string &content);
  void write();
};


#endif // DIARY_H
