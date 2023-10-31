#include <cctype>
#include <limits>
#include "Display.h"
#include "File_In.h"
<<<<<<< HEAD
#include "Rand_Num.h"

std::string get_word();
=======
#include "Random.h"

std::string get_word();
char get_guess(const std::string& correct, const std::vector<char>& wrong);
char get_replay();
>>>>>>> 76750ce (I did that)

template<typename Char_List>
bool in_list(const Char_List& list, const char input);

<<<<<<< HEAD
char get_guess(const std::string& correct, const std::vector<char>& wrong);
char get_replay();
void play();

int main() {
  const int screen_size = 16;
=======
void play();

int main() {
  const int screen_size = 17;
>>>>>>> 76750ce (I did that)
  char replay = 'y';

  while (replay == 'y') {
    play();
    replay = get_replay();

    if (replay == 'y') {
<<<<<<< HEAD
      Display::wipe(screen_size);
=======
      Display::wipe_line(screen_size);
>>>>>>> 76750ce (I did that)
    }
  }
}

std::string get_word() {
<<<<<<< HEAD
  const int line = Rand_Num::get().gen_int(1, 849);
=======
  const int line = Random::get().Int(1, 849);
>>>>>>> 76750ce (I did that)
  File_In fin("words.txt");
  std::string word;

  for (int i = 0; i < line; i++) {
    fin.stream() >> word;
  }

  return word;
}

<<<<<<< HEAD
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

=======
>>>>>>> 76750ce (I did that)
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
<<<<<<< HEAD
      Display::wipe_line(); // Clears line if bad input
=======
      Display::wipe_input(); // Clears line if bad input
>>>>>>> 76750ce (I did that)
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

<<<<<<< HEAD
    if (replay != 'n') {
      Display::wipe_line();
=======
    if (replay != 'n' && replay != 'y') {
      Display::wipe_input();
>>>>>>> 76750ce (I did that)
    }
  } while (replay != 'n' && replay != 'y');

  return replay;
}

<<<<<<< HEAD
=======
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

>>>>>>> 76750ce (I did that)
void play() {
  const int screen_size = 15;
  Hangman game(get_word());

  Display::print_state(game);

  while (!game.is_lost()) {
<<<<<<< HEAD
    game.set_guess(get_guess(game.get_correct(), game.get_wrong()));
    game.update_state();

    Display::wipe(screen_size);
=======
    game.set_guess(get_guess(game.correct(), game.wrong()));
    game.update_state();

    Display::wipe_line(screen_size);
>>>>>>> 76750ce (I did that)
    Display::print_state(game);

    if (game.is_won()) {
      break;
    }
  }

<<<<<<< HEAD
  if (game.is_lost()) {
    Display::loss(game.get_answer());
  } else {
    Display::win();
  }
=======
  (game.is_lost()) ? Display::loss(game.answer()) : Display::win();
>>>>>>> 76750ce (I did that)
}
