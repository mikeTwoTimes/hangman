#include "File_In.h"

<<<<<<< HEAD
File_In::File_In(const std::string& file_name) : ins(file_name) {}

void File_In::guard() {
  if (ins.is_open()) {
    ins.close();
  }
}

void File_In::open(const std::string& file_name) {
  guard();
  ins.open(file_name);
=======
File_In::File_In(const char* file) : ins(file) {}

void File_In::open(const char* file) {
  guard();
  this->ins.open(file);
>>>>>>> 76750ce (I did that)
}

std::ifstream& File_In::stream() { return this->ins; }

<<<<<<< HEAD
=======
void File_In::guard() {
  if (this->ins.is_open()) {
    this->ins.close();
  }
}

>>>>>>> 76750ce (I did that)
File_In::~File_In() { guard(); }
