#include "File_In.h"

File_In::File_In(const char* file) : ins(file) {}

void File_In::guard() {
  if (this->ins.is_open()) {
    this->ins.close();
  }
}

void File_In::open(const char* file) {
  guard();
  this->ins.open(file);
}

std::ifstream& File_In::stream() { return this->ins; }

File_In::~File_In() { guard(); }
