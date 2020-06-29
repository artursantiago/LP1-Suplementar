#if !defined(DATE_H)
#define DATE_H

#include <string>

struct Date
{
  Date();

  unsigned day;
  unsigned month;
  unsigned year;
  
  bool is_equal(Date &date);
  void set_from_string(const std::string &date);
  std::string to_string();
};


#endif // DATE_H
