#include "../include/Diary.h"
#include "../include/Message.h"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

Diary::Diary(const std::string &filename) : 
  filename(filename),
  messages(nullptr), 
  messages_size(0), 
  messages_capacity(10)
{
  messages = new Message[messages_capacity];
  load();
}

Diary::~Diary() {
  delete[] messages;
}

void Diary::load() {
  std::string line;
  std::ifstream file(filename);

  if (!file.is_open() || file.fail()) {
    throw std::runtime_error("The file couldn't be opened.");
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
}

Message* Diary::search(const std::string& what) {
  for (size_t i = 0; i < messages_size; ++i) {
    if (messages[i].content.find(what, 0) != std::string::npos) {
      return &messages[i];
    }
  }
  return nullptr;
}

void Diary::add(const std::string &content) {
  Message m;
  m.set_date();
  m.set_time();
  m.content = content;

  messages[messages_size] = m;
  messages_size++;

  if (messages_size == messages_capacity) {
    increase_messages_capacity();
  }
}

void Diary::add(const Message &message) {
  messages[messages_size] = message;
  messages_size++;
  
  if (messages_size == messages_capacity) {
    increase_messages_capacity();
  }
}

void Diary::increase_messages_capacity() {
  messages_capacity *= 2;

  Message* aux_message = new Message[messages_capacity];
  std::copy(messages, messages+messages_size, aux_message);
  delete[] messages;
  messages = aux_message;
}

void Diary::write() {
  std::ofstream file(filename);

  for (size_t i = 0; i < messages_size; ++i) {
    if (!(i > 0 && messages[i-1].date.is_equal(messages[i].date))) {
      file << (i == 0 ? "" : "\n")<< "# " << messages[i].date.to_string() << std::endl;
    }
    file << "- " << messages[i].time.to_string() << " " << messages[i].content << std::endl;
  }
  
}
