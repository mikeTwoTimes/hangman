#pragma once

#include <string>
#include <unordered_set>

class Hangman {
public:
  Hangman(const std::string& word);
  void guess(const std::string input);

  const std::string& target() const;
  const std::string& current() const;
  const std::unordered_set<char>& answers() const;
  const std::unordered_set<char>& history() const;
  int wrong() const;
  
  bool is_won() const;
  bool is_lost() const;
  
private:
  static const int s_max_wrong;
  const std::string& m_target;
  const std::unordered_set<char> m_answers;
  std::unordered_set<char> m_history;
  std::string m_current;
  int m_wrong;

  void update_current(const char letter);

  Hangman() = delete;
  Hangman(const Hangman&) = delete;
  Hangman& operator=(const Hangman&) = delete;
};
