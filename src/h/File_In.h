#pragma once

#include <fstream>
#include <string>

class File_In {
public:
  File_In(const std::string& file_name);
  void open(const std::string& file_name);
  std::ifstream& stream();
  ~File_In();

private:
  std::ifstream ins;

  void guard();
  File_In(const File_In&) = delete;
  File_In& operator=(const File_In&) = delete;
};
