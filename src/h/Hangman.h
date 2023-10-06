#pragma once

#include <string>
#include <vector>

class Hangman {
public:
  Hangman(const std::string& answer);
  const std::string& get_answer() const;
  const std::string& get_correct() const;
  const std::vector<char>& get_wrong() const;
  size_t wrong_count() const;
  void set_guess(const char guess);
  void update_state();
  bool is_won() const;
  bool is_lost() const;
  
private:
  const std::string m_answer;
  std::string m_correct;
  char m_guess;
  std::vector<char> m_wrong;

  bool is_correct() const;
  void update_correct();
  void update_wrong();
  Hangman() = delete;
  Hangman(const Hangman&) = delete;
  Hangman& operator=(const Hangman&) = delete;
};
