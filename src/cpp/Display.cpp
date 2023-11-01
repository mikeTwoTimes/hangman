#include "Display.h"

void Display::wipe_line(const int line_count) {
  std::cout << "\r"; // Move cursor to the start of current line

  for (int i = 0; i < line_count; i++) {
    std::cout << "\033[K"; // Clear line
    std::cout << "\033[1A"; // Move cursor up one line
  }
}

void Display::wipe_input() {
  std::cout << "\033[1A\r";
  std::cout << "\033[K";
}

void Display::print_correct(const std::string& correct) {
  for (std::size_t i = 0; i < correct.size(); i++) {
    if (i < correct.size() - 1) {
      std::cout << correct[i] << " ";
    } else {
      std::cout << correct[i] << "\n";
    }
  }

  for (std::size_t i = 0; i < correct.size(); i++) {
    if (i < correct.size() - 1) {
      std::cout << "- ";
    } else {
      std::cout << "- [" << correct.size() << "]\n\n";
    }
  }
}

void Display::print_wrong(const std::vector<char>& wrong) {
  std::cout << "{ ";

  for (const char letter : wrong) {
    if (letter != wrong.back()) {
      std::cout << letter << ", ";
    } else {
      std::cout << letter << " ";
    }
  }

  std::cout << "}\n\n";
}

void Display::print_state(const Hangman& game) {
  switch (game.wrong_count()) {
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

  print_correct(game.correct());
  print_wrong(game.wrong());
}

void Display::loss(const std::string& answer) {
  std::cout << "Good try! The word was: " << answer << "\n\n";
}

void Display::win() { std::cout << "Good job! You saved the man!\n\n"; }
