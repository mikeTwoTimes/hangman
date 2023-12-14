#include <cctype>
#include "Display.h"
#include "File_In.h"
#include "Random.h"

std::string get_word(File_In& fin);
char get_guess(const std::string& correct, const std::vector<char>& wrong);
bool get_replay();

template<typename Char_List>
bool in_list(const Char_List& list, const char input);

void play(File_In& fin);

int main() {
  const int screen_size = 17;
  bool replay = true;
  File_In fin("words.txt");

  while (replay) {
    play(fin);
    replay = get_replay();

    Display::wipe_line(screen_size);
  }

  return 0;
}

std::string get_word(File_In& fin) {
  const int file_size = 682;
  const int line = Random::get().Int(1, file_size);
  std::string word = " ";

  for (int i = 0; i < line; i++) {
    fin.stream() >> word;
  }

  fin.stream().seekg(0, std::ios::beg);

  return word;
}

char get_guess(const std::string& correct, const std::vector<char>& wrong) {
  const int prompt_size = 16;
  std::string guess = " ";

  do {
    std::cout << "Guess a letter: ";
    std::getline(std::cin, guess);
    
    guess[0] = std::toupper(guess[0]);

    Display::wipe_buffer(guess.size() + prompt_size);
  } while (guess.size() != 1 || !std::isalpha(guess[0]) || 
	   in_list(correct, guess[0]) || in_list(wrong, guess[0]));

  std::cout << "\n";

  return guess[0];
}

bool get_replay() {
  const int prompt_size = 17;
  std::string replay = " ";

  do {
    std::cout << "Play again? y/n: ";
    std::getline(std::cin, replay);

    replay[0] = std::tolower(replay[0]);

    Display::wipe_buffer(replay.size() + prompt_size);
  } while (replay.size() != 1 || (replay[0] != 'n' && replay[0] != 'y'));

  std::cout << "\n";
  
  return replay[0] == 'y';
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
