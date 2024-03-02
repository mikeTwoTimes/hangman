#include "Display.h"

const char* Drawing::gallows = "____\n"
                               "|/  |\n"
                               "|\n"
                               "|\n"
                               "|\n"
                               "|\n"
                               "|\n"
                               "|_____";

const char* Drawing::head = "____\n"
      	      	            "|/  |\n"
      	      	            "|  (_)\n"
                            "|\n"
                            "|\n"
                            "|\n"
                            "|\n"
                            "|_____";

const char* Drawing::body = "____\n"
                            "|/  |\n"
                            "|  (_)\n"
                            "|   |\n"
                            "|   |\n"
                            "|\n"
                            "|\n"
                            "|_____";

const char* Drawing::left_arm = "____\n"
                                "|/  |\n"
                                "|  (_)\n"
                                "|  \\|\n"
                                "|   |\n"
                                "|\n"
                                "|\n"
                                "|_____";

const char* Drawing::right_arm = "____\n"
                                 "|/  |\n"
                                 "|  (_)\n"
                                 "|  \\|/\n"
                                 "|   |\n"
                                 "|\n"
                                 "|\n"
                                 "|_____";

const char* Drawing::left_leg = "____\n"
                                "|/  |\n"
                                "|  (_)\n"
                                "|  \\|/\n"
                                "|   |\n"
                                "|  /\n"
                                "|\n"
                                "|_____";

const char* Drawing::right_leg = "____\n"
                                 "|/  |\n"
			         "|  (_)\n"
			         "|  \\|/\n"
                                 "|   |\n"
                                 "|  / \\\n"
                                 "|\n"
                                 "|_____";

void Display::wipe_line(const int line_count) {
  std::cout << "\r"; // Move cursor to the start of current line

  for (int i = 0; i < line_count; i++) {
    std::cout << "\033[K"; // Clear line
    std::cout << "\033[1A"; // Move cursor up one line
  }
}

void Display::wipe_buffer(const std::size_t length) {
  std::cout << "\033[1A" << "\033[" << length << "D"; // Move cursor to start of buf

  for (std::size_t i = 0; i < length; i++) {
    std::cout << " "; // Clear all input
  }

  std::cout << "\033[" << length << "D"; // Reset cursor
}

void Display::print_correct(const std::string& current) {
  for (const char correct : current) {
    std::cout << correct << " ";
  }

  std::cout << "\n";

  for (std::size_t i = 0; i < current.size(); i++) {
    std::cout << "- ";
  }

  std::cout << "[" << current.size() << "]\n\n";
}

void Display::print_wrong(const std::unordered_set<char>& history, const std::unordered_set<char>& answers, const int wrong) {
  std::cout << "{ ";

  for (const char letter : history) {
    if (!answers.count(letter)) {
      std::cout << letter << ", ";
    }
  }

  if (wrong > 0) {
    std::cout << "\033[2D";
  }

  std::cout << " }\n\n";
}

void Display::print_state(const Hangman& game) {
  switch (game.wrong()) {
  case 0:
    std::cout << Drawing::gallows << "\n\n";
    break;
  case 1:
    std::cout << Drawing::head << "\n\n";
    break;
  case 2:
    std::cout << Drawing::body << "\n\n";
    break;
  case 3:
    std::cout << Drawing::left_arm << "\n\n";
    break;
  case 4:
    std::cout << Drawing::right_arm << "\n\n";
    break;
  case 5:
    std::cout << Drawing::left_leg << "\n\n";
    break;
  case 6:
    std::cout << Drawing::right_leg << "\n\n";
    break;
  }

  print_correct(game.current());
  print_wrong(game.history(), game.answers(), game.wrong());
}

void Display::loss(const std::string& target) {
  std::cout << "Good try! The word was: " << target << "\n\n";
}

void Display::win() { std::cout << "Good job! You saved the man!\n\n"; }
