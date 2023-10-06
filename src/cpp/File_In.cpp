#include "File_In.h"

File_In::File_In(const std::string& file_name) : ins(file_name) {}

void File_In::guard() {
  if (ins.is_open()) {
    ins.close();
  }
}

void File_In::open(const std::string& file_name) {
  guard();
  ins.open(file_name);
}

std::ifstream& File_In::stream() { return this->ins; }

File_In::~File_In() { guard(); }
