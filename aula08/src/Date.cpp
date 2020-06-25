#include "../include/Date.h"

#include <iostream>
#include <sstream>

Date::Date() :
  year(0),
  month(0),
  day(0)
{  
}

bool Date::is_equal(const std::string &date) {
  return to_string() == date;;
}

void Date::set_from_string(const std::string &date) {
  char discard;
  std::stringstream stream(date);

  stream >> day;
  stream >> discard;
  stream >> month;
  stream >> discard;
  stream >> year;
}

std::string Date::to_string() {
  std::stringstream stream;
  stream << day;
  stream << "/";
  stream << month;
  stream << "/";
  stream << year;

  return stream.str();
}