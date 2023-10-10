#include <cctype>
#include <limits>
#include "Display.h"
#include "File_In.h"
#include "Rand_Num.h"

std::string get_word();

template<typename T>
bool in_list(const T& char_list, const char input);

char get_guess(const std::string& correct, const std::vector<char>& wrong);
char get_replay();
void play();

int main() {
  const int screen_size = 16;
  char replay = 'y';

  while (replay == 'y') {
    play();
    replay = get_replay();

    if (replay == 'y') {
      Display::wipe(screen_size);
    }
  }
}

std::string get_word() {
  const int line = Rand_Num::get().gen_int(1, 849);
  File_In fin("words.txt");
  std::string word;

  for (int i = 0; i < line; i++) {
    fin.stream() >> word;
  }

  return word;
}

template<typename T>
bool in_list(const T& char_list, const char input) {
  bool found = false;

  for (const char item : char_list) {
    if (item == input) {
      found = true;
      break;
    }
  }

  return found;
}

char get_guess(const std::string& correct, const std::vector<char>& wrong) {
  char guess = '0';

  do {
    std::cout << "Guess a letter: ";
    std::cin.get(guess);   // .get() will read newline characters. 
                           // did this so user couldnt break display.
    if (guess != '\n') {
      // Good grief
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      guess = std::toupper(guess);
    }
    
    if (!std::isalpha(guess) || in_list(correct, guess) || in_list(wrong, guess)) {
      Display::wipe_line(); // Clears line if bad input
    }
  } while (!std::isalpha(guess) || in_list(correct, guess) || in_list(wrong, guess));

  return guess;
}

char get_replay() {
  char replay = '0';

  do {
    std::cout << "Play again? y/n: ";
    std::cin.get(replay);

    if (replay != '\n') {
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      replay = std::tolower(replay);
    }

    if (replay != 'n') {
      Display::wipe_line();
    }
  } while (replay != 'n' && replay != 'y');

  return replay;
}

void play() {
  const int screen_size = 15;
  Hangman game(get_word());

  Display::print_state(game);

  while (!game.is_lost()) {
    game.set_guess(get_guess(game.get_correct(), game.get_wrong()));
    game.update_state();

    Display::wipe(screen_size);
    Display::print_state(game);

    if (game.is_won()) {
      break;
    }
  }

  if (game.is_lost()) {
    Display::loss(game.get_answer());
  } else {
    Display::win();
  }
}
