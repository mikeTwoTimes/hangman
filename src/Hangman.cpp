#include "Hangman.h"

const int Hangman::s_max_wrong = 6;

Hangman::Hangman(const std::string& word)
  : m_target(word), m_answers(word.begin(), word.end()),
    m_current(word.size(), ' '), m_wrong(0) {}

void Hangman::update_current(const char letter) {
  for (std::size_t i = 0; i < this->m_current.size(); i++) {
    if (letter == this->m_target[i]) {
      this->m_current[i] = letter;
    }
  }
}

void Hangman::guess(const std::string input) {
  if(input.size() > 1) {
    if(input == this->m_target) {
      this->m_current = this->m_target;
    } else {
      this->m_wrong++;
    }
  } else {
    if (this->m_answers.count(input.at(0))) {
      this->update_current(input.at(0));
    } else {
      this->m_wrong++;
    }
    this->m_history.insert(input.at(0));
  }
}

const std::string& Hangman::target() const { return this->m_target; }

const std::string& Hangman::current() const { return this->m_current; }

const std::unordered_set<char>& Hangman::answers() const {
  return this->m_answers;
}

const std::unordered_set<char>& Hangman::history() const {
  return this->m_history;
}

int Hangman::wrong() const { return this->m_wrong; }

bool Hangman::is_won() const { return this->m_current == this->m_target; }

bool Hangman::is_lost() const { return this->m_wrong == s_max_wrong; }
