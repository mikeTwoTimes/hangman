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

void File_In::reset() {
  this->ins.clear();
  this->ins.seekg(0, std::ios::beg);
}

std::ifstream& File_In::stream() { return this->ins; }

File_In::~File_In() { guard(); }

bool File_In::error() const {
  return !this->ins;
}
