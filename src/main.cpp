#include <cctype>
#include "Display.h"
#include "File_In.h"
#include "Random.h"

std::string read_word(File_In& fin, const int file_size);

char read_letter(const std::unordered_set<char>& history);
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

  fin.stream().seekg(0, std::ios::beg);

  return word;
}

char read_letter(const std::unordered_set<char>& history) {
  const int prompt_size = 16;
  std::string input = "";

  do {
    std::cout << "Guess a letter: ";
    std::getline(std::cin, input);
    
    input[0] = std::toupper(input[0]);

    Display::wipe_buffer(input.size() + prompt_size);
  } while (input.size() != 1 || !std::isalpha(input[0]) ||
	   history.count(input[0]));

  std::cout << "\n";

  return input[0];
}

bool play_again() {
  const int prompt_size = 17;
  std::string input = "";

  do {
    std::cout << "Play again? y/n: ";
    std::getline(std::cin, input);

    input[0] = std::tolower(input[0]);

    Display::wipe_buffer(input.size() + prompt_size);
  } while (input.size() != 1 || (input[0] != 'n' && input[0] != 'y'));

  std::cout << "\n";
  
  return input[0] == 'y';
}

void start_game(const std::string& word) {
  const int screen_size = 15;
  Hangman game(word);

  Display::print_state(game);

  while (!game.is_lost()) {
    game.guess(read_letter(game.history()));

    Display::wipe_line(screen_size);
    Display::print_state(game);

    if (game.is_won()) {
      break;
    }
  }

  (game.is_lost()) ? Display::loss(game.target()) : Display::win();
}

void play(const char* file, const int file_size) {
  const int screen_size = 17;
  File_In fin(file);
  bool replay = true;

  while (replay) {
    start_game(read_word(fin, file_size));
    replay = play_again();

    Display::wipe_line(screen_size);
  }
}
