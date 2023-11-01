#include <cctype>
#include <limits>
#include "Display.h"
#include "File_In.h"
#include "Random.h"

std::string get_word(File_In& fin);
char get_guess(const std::string& correct, const std::vector<char>& wrong);
char get_replay();

template<typename Char_List>
bool in_list(const Char_List& list, const char input);

void play(File_In& fin);

int main() {
  const int screen_size = 17;
  char replay = 'y';
  File_In fin("words.txt");

  while (replay == 'y') {
    play(fin);
    replay = get_replay();

    if (replay == 'y') {
      Display::wipe_line(screen_size);
    }
  }
}

std::string get_word(File_In& fin) {
  const int line = Random::get().Int(1, 682); // Picks a random line from the file
  std::string word;

  for (int i = 0; i < line; i++) {
    fin.stream() >> word;  // Reads file until the line number
  }

  fin.stream().seekg(0, std::ios::beg); // Resets stream position to beginning of file

  return word;
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
      Display::wipe_input(); // Clears line if bad input
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

    if (replay != 'n' && replay != 'y') {
      Display::wipe_input();
    }
  } while (replay != 'n' && replay != 'y');

  return replay;
}

template<typename Char_List>
bool in_list(const Char_List& list, const char input) {
  bool found = false;

  for (const char item : list) {
    if (item == input) {
      found = true;
      break;
    }
  }

  return found;
}

void play(File_In& fin) {
  const int screen_size = 15;
  Hangman game(get_word(fin));

  Display::print_state(game);

  while (!game.is_lost()) {
    game.set_guess(get_guess(game.correct(), game.wrong()));
    game.update_state();

    Display::wipe_line(screen_size);
    Display::print_state(game);

    if (game.is_won()) {
      break;
    }
  }

  (game.is_lost()) ? Display::loss(game.answer()) : Display::win();
}
