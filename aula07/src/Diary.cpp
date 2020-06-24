#include "../include/Diary.h"
#include "../include/Message.h"

#include <string>
#include <fstream>

Diary::Diary(const std::string &filename) : filename(filename),
  messages_size(0), messages_capacity(10), messages(nullptr)
{
  messages = new Message[messages_capacity];
}

void Diary::add(const std::string &content) {
  if (messages_size >= messages_capacity){
    Message* aux_message = new Message[messages_size*2];
    std::copy(messages, messages+messages_size, aux_message);
    delete[] messages;
    messages = aux_message;
  }

  messages[messages_size].content = content;
  messages_size++;
}

void Diary::write() {

}
