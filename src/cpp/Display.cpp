// ASCII art from: http://www.fssnip.net/mO/title/Hangman

#include "Display.h"

void Display::start() {
  std::cout << "____\n";
  std::cout << "|/  |\n";
  std::cout << "|\n";
  std::cout << "|\n";
  std::cout << "|\n";
  std::cout << "|\n";
  std::cout << "|\n";
  std::cout << "|_____\n\n";
}

void Display::one_wrong() {
  std::cout << "____\n";
  std::cout << "|/  |\n";
  std::cout << "|  (_)\n";
  std::cout << "|\n";
  std::cout << "|\n";
  std::cout << "|\n";
  std::cout << "|\n";
  std::cout << "|_____\n\n";
}

void Display::two_wrong() {
  std::cout << "____\n";
  std::cout << "|/  |\n";
  std::cout << "|  (_)\n";
  std::cout << "|   |\n";
  std::cout << "|   |\n";
  std::cout << "|\n";
  std::cout << "|\n";
  std::cout << "|_____\n\n";
}

void Display::three_wrong() {
  std::cout << "____\n";
  std::cout << "|/  |\n";
  std::cout << "|  (_)\n";
  std::cout << "|  \\|\n";
  std::cout << "|   |\n";
  std::cout << "|\n";
  std::cout << "|\n";
  std::cout << "|_____\n\n";
}

void Display::four_wrong() {
  std::cout << "____\n";
  std::cout << "|/  |\n";
  std::cout << "|  (_)\n";
  std::cout << "|  \\|/\n";
  std::cout << "|   |\n";
  std::cout << "|\n";
  std::cout << "|\n";
  std::cout << "|_____\n\n";
}

void Display::five_wrong() {
  std::cout << "____\n";
  std::cout << "|/  |\n";
  std::cout << "|  (_)\n";
  std::cout << "|  \\|/\n";
  std::cout << "|   |\n";
  std::cout << "|  /\n";
  std::cout << "|\n";
  std::cout << "|_____\n\n";
}

void Display::six_wrong() {
  std::cout << "____\n";
  std::cout << "|/  |\n";
  std::cout << "|  (_)\n";
  std::cout << "|  \\|/\n";
  std::cout << "|   |\n";
  std::cout << "|  / \\\n";
  std::cout << "|\n";
  std::cout << "|_____\n\n";
}

void Display::wipe_line() {
  std::cout << "\033[1A\r"; // Move cursor up one line
  std::cout << "\033[K"; // Clears line
}

void Display::wipe(const int line_count) {
  for (int i = 0; i < line_count; i++) {
    wipe_line();
  }
}

void Display::print_correct(const std::string& correct) {
  for (size_t i = 0; i < correct.size(); i++) {
    if (i < correct.size() - 1) {
      std::cout << correct[i] << " ";
    } else {
      std::cout << correct[i] << "\n";
    }
  }

  for (size_t i = 0; i < correct.size(); i++) {
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
  case 1:
    one_wrong();
    break;
  case 2:
    two_wrong();
    break;
  case 3:
    three_wrong();
    break;
  case 4:
    four_wrong();
    break;
  case 5:
    five_wrong();
    break;
  case 6:
    six_wrong();
    break;
  default:
    start();
  }

  print_correct(game.get_correct());
  print_wrong(game.get_wrong());
}

void Display::loss(const std::string& answer) {
  std::cout << "Good try! The word was: " << answer << "\n\n";
}

void Display::win() { std::cout << "Good job! You guessed the word!\n\n"; }
