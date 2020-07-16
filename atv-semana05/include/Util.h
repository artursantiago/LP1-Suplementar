#if !defined(UTIL_H)
#define UTIL_H

#include <string>

class Util
{
public:

  static double stringToDouble(std::string value_s);
  static std::string doubleToString(double value_d, bool comAspas = false);
};

#endif // UTIL_H
