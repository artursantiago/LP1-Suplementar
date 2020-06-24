#if !defined(DIARY_H)
#define DIARY_H

#include "Message.h"

#include  <string>

struct Diary
{
  Diary(const std::string &filename);

  std::string filename;
  Message* messages;
  size_t messages_size;
  size_t messages_capacity;

  /*Add new message to the Diary object */
  void add(const std::string &message);

  /*Stores all information of the diaries in use in their files*/
  void write();
};


#endif // DIARY_H
