#pragma once

#include <iostream>
#include "Hangman.h"

namespace Display {
  void start();
  void one_wrong();
  void two_wrong();
  void three_wrong();
  void four_wrong();
  void five_wrong();
  void six_wrong();
  void wipe(const int line_count);
  void wipe_line();
  void print_correct(const std::string& correct);
  void print_wrong(const std::vector<char>& wrong);
  void print_state(const Hangman& game);
  void loss(const std::string& answer);
  void win();
}
