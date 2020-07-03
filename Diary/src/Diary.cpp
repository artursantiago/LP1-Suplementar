#include "../include/Diary.h"
#include "../include/Message.h"

#include <string>
#include <fstream>
#include <sstream>

Diary::Diary(const std::string &filename) : filename(filename)
{
  load();
}

Diary::~Diary() {
  write();
}

void Diary::load() {
  std::string line;
  std::ifstream file(filename);

  if (!file.is_open() || file.fail()) {
    std::ofstream file_out(filename);
    file_out.close();
    return;
  }
  
  std::string date;
  char discard;
  while (!file.eof()) {
    std::getline(file, line);
    std::stringstream stream(line);
    Message message;

    stream >> discard;    
    if (discard == '#') {
      stream >> date;
    } else if (discard == '-') {
      std::string time;
      stream >> time;

      /*For some reason the conditional allows a blank line, so it's necessary verify if the next string is empty*/
      if (time.empty()) {
        continue;
      }

      message.time.set_from_string(time);
      message.date.set_from_string(date);

      getline(stream, message.content);
      message.content.erase(0,1);
      
      add(message);
    }
  }

  file.close();
}

std::vector<Message*> Diary::search(const std::string& what) {
  std::vector<Message*> match_messages;

  for (size_t i = 0; i < messages.size(); ++i) {
    if (messages[i].content.find(what, 0) != std::string::npos) {
      match_messages.push_back(&messages[i]);
    }
  }

  return match_messages;
}

void Diary::add(const std::string &content) {
  Message m;
  m.set_date();
  m.set_time();
  m.content = content;

  add(m);
}

void Diary::add(const Message &message) {
  messages.push_back(message);
}

void Diary::write() {
  std::ofstream file(filename);

  for (size_t i = 0; i < messages.size(); ++i) {
    if (!(i > 0 && messages[i-1].date.is_equal(messages[i].date))) {
      file << (i == 0 ? "" : "\n")<< "# " << messages[i].date.to_string() << std::endl;
    }
    file << "- " << messages[i].time.to_string() << " " << messages[i].content << std::endl;
  }

  file.close();
}
