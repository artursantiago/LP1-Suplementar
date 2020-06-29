#include "../include/Time.h"
#include <string>
#include <sstream>

Time::Time() :
  hour(0),
  minute(0),
  second(0)
{  
}

void Time::set_from_string(const std::string &time) {
  char discard;
  std::stringstream stream(time);

  stream >> hour;
  stream >> discard;
  stream >> minute;
  stream >> discard;
  stream >> second;

}

std::string Time::to_string() {
  std::stringstream stream;
  stream << (hour < 10 ? "0" : "") << hour << ":";
  stream << (minute < 10 ? "0" : "") << minute << ":";
  stream << (second < 10 ? "0" : "") << second;

  return stream.str();
}