#if !defined(MESSAGE_H)
#define MESSAGE_H

#include <string>

struct Message {
  std::string date;
  std::string time;
  std::string content;
  
  bool is_after(Message &other_message);
  bool is_before(Message &other_message);
};


#endif // MESSAGE_H
