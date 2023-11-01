#pragma once

#include <iostream>
#include "Hangman.h"

namespace Display {
  void wipe_line(const int line_count);
  void wipe_input();

  void print_correct(const std::string& correct);
  void print_wrong(const std::vector<char>& wrong);
  void print_state(const Hangman& game);

  void loss(const std::string& answer);
  void win();
}

// ASCII art from: http://www.fssnip.net/mO/title/Hangman

namespace Drawing {
  const std::string gallows = "____\n"
                              "|/  |\n"
                              "|\n"
                              "|\n"
                              "|\n"
                              "|\n"
                              "|\n"
                              "|_____";

  const std::string head = "____\n"
      	      	      	   "|/  |\n"
      	      	      	   "|  (_)\n"
                           "|\n"
                           "|\n"
                           "|\n"
                           "|\n"
                           "|_____";

  const std::string body = "____\n"
                           "|/  |\n"
                           "|  (_)\n"
                           "|   |\n"
                           "|   |\n"
                           "|\n"
                           "|\n"
                           "|_____";

  const std::string left_arm = "____\n"
                               "|/  |\n"
                               "|  (_)\n"
                               "|  \\|\n"
                               "|   |\n"
                               "|\n"
                               "|\n"
                               "|_____";

  const std::string right_arm = "____\n"
                                "|/  |\n"
                                "|  (_)\n"
                                "|  \\|/\n"
                                "|   |\n"
                                "|\n"
                                "|\n"
                                "|_____";

  const std::string left_leg = "____\n"
                               "|/  |\n"
                               "|  (_)\n"
                               "|  \\|/\n"
                               "|   |\n"
                               "|  /\n"
                               "|\n"
                               "|_____";

  const std::string right_leg = "____\n"
                                "|/  |\n"
			        "|  (_)\n"
			        "|  \\|/\n"
                                "|   |\n"
                                "|  / \\\n"
                                "|\n"
                                "|_____";
}
