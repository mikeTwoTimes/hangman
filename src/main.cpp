#include <cctype>
#include <algorithm>
#include "Display.h"
#include "File_In.h"
#include "Random.h"

std::string read_word(File_In& fin, const int file_size);

std::string read_input();
bool play_again();

void start_game(const std::string& word);
void play(const char* file, const int file_size);

int main() {
  const char* file = "words.dat";
  const int file_size = 682;

  play(file, file_size);
  
  return 0;
}

std::string read_word(File_In& fin, const int file_size) {
  const int line = Random::get().Int(1, file_size);
  std::string word = "";

  for (int i = 0; i < line; i++) {
    fin.stream() >> word;
  }

  fin.reset();

  return word;
}

std::string read_input() {
  std::string input = "";
  std::cout << "Ghess a letter or a word: ";
  std::cin >> input;
  std::transform(input.begin(), input.end(), input.begin(), ::toupper);
  return input;
}

bool play_again() {
  std::string input;
  do {
    std::cout << "Play again? y/n: ";
    std::cin >> input;
    std::transform(input.begin(), input.end(), input.begin(), ::tolower);
  } while (input.size() != 1 || (input.at(0) != 'n' && input.at(0) != 'y'));

  std::cout << "\n";
  
  return input.at(0) == 'y';
}

void start_game(const std::string& word) {
  const int screen_size = 15;
  Hangman game(word);

  Display::print_state(game);

  while (!game.is_lost()) {
    game.guess(read_input());

    Display::wipe_line(screen_size);
    Display::print_state(game);

    if (game.is_won()) {
      break;
    }
  }

  (game.is_lost()) ? Display::loss(game.target()) : Display::win();
}

void play(const char* file, const int file_size) {
  File_In fin(file);
  bool replay = true;

  if (fin.error()) {
    std::cerr << "Error: '" << file << "' not found, exiting program.\n";
    return;
  }

  while (replay) {
    start_game(read_word(fin, file_size));
    replay = play_again();
  }
}
