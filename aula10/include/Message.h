#if !defined(MESSAGE_H)
#define MESSAGE_H

#include "Date.h"
#include "Time.h"
#include <string>

struct Message
{
  // Message(const std::string &content);

  Date date;
  Time time;
  std::string content;

  void set_date();
  void set_time();
};


#endif // MESSAGE_H
