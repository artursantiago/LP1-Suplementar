#if !defined(DATE_TIME_H)
#define DATE_TIME_H

#include <string>

/* Returns a "time" value with the given format */
std::string format_current_date(const std::string &format);

std::string get_current_date();

std::string get_current_time();


#endif // DATE_TIME_H
