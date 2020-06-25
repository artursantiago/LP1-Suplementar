#include "../include/Diary.h"
#include "../include/Message.h"

#include <string>
#include <fstream>
#include <iostream>

Diary::Diary(const std::string &filename) : 
  filename(filename),
  messages(nullptr), 
  messages_size(0), 
  messages_capacity(10)
{
  messages = new Message[messages_capacity];
}

Diary::~Diary() {
  delete[] messages;
}

void Diary::add(const std::string &content) {
  if (messages_size >= messages_capacity){
    Message* aux_message = new Message[messages_size*2];
    std::copy(messages, messages+messages_size, aux_message);
    delete[] messages;
    messages = aux_message;
  }

  Message m;
  m.set_date();
  m.set_time();
  m.content = content;

  messages[messages_size] = m;
  messages_size++;
}

void Diary::write() {
}
