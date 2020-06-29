#include "../include/Message.h"
#include "../include/Util.h"

#include <string>

void Message::set_date() {
  date.set_from_string(get_current_date());
}

void Message::set_time() {
  time.set_from_string(get_current_time());
}
