#if !defined(DIARY_H)
#define DIARY_H

#include <string>
#include <date_time.h>
#include <message.h>
#include <vector>

struct Diary {
  std::vector<std::string> dates;
  std::vector<Message> messages;

  bool has_date(std::string *other_date);
};


/* Show the list of the messages stored on the file in the same sequence */
void list(std::ifstream & input_file);

/* Add a new message(new line) in the end of the file */
void add(std::ifstream & input_file, std::ofstream & output_file, std::string message);

/* Reads the file and store the content into a Diary struct. 
 * Must be called when the program starts.
 */
void read_store(std::ifstream & input_file, Diary *diary);

#endif // DIARY_H
