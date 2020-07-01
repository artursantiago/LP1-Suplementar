#include "../include/Date.h"

#include <iostream>
#include <sstream>

Date::Date() :
  year(0),
  month(0),
  day(0)
{  
}

bool Date::is_equal(Date &date) {
  return to_string() == date.to_string();
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
  stream << (day < 10 ? "0" : "") << day << "/";
  stream << (month < 10 ? "0" : "") << month << "/";
  stream << year;

  return stream.str();
}
