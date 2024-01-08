#pragma once

#include <string>
#include <vector>

class Hangman {
public:
  Hangman(const std::string& answer);
  void set_guess(const char guess);
  void update_state();

  const std::string& answer() const;
  const std::string& correct() const;
  const std::vector<char>& wrong() const;
  std::size_t wrong_count() const;
  
  bool is_won() const;
  bool is_lost() const;
  
private:
  const std::string m_answer;
  std::string m_correct;
  char m_guess;
  std::vector<char> m_wrong;

  void update_correct();
  void update_wrong();

  bool is_correct() const;

  Hangman() = delete;
  Hangman(const Hangman&) = delete;
  Hangman& operator=(const Hangman&) = delete;
};
