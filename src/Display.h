#pragma once

#include <iostream>
#include "Hangman.h"

namespace Drawing {
  extern const char* gallows;
  extern const char* head;
  extern const char* body;
  extern const char* left_arm;
  extern const char* right_arm;
  extern const char* left_leg;
  extern const char* right_leg;
}

namespace Display {
  void wipe_line(const int line_count);
  void wipe_buffer(const std::size_t length);

  void print_correct(const std::string& correct);
  void print_wrong(const std::vector<char>& wrong);
  void print_state(const Hangman& game);

  void loss(const std::string& answer);
  void win();
}
