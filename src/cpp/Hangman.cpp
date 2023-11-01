#include "Hangman.h"

Hangman::Hangman(const std::string& word)
  : m_answer(word), m_correct(word.size(), ' '), m_guess('0') {
  const std::size_t max_wrong = 6;

  this->m_wrong.reserve(max_wrong);
}

void Hangman::set_guess(const char guess) { this->m_guess = guess; }

void Hangman::update_correct() {
  for (std::size_t i = 0; i < this->m_correct.size(); i++) {
    if (this->m_guess == this->m_answer[i]) {
      this->m_correct[i] = this->m_guess;
    }
  }
}

void Hangman::update_wrong() { this->m_wrong.emplace_back(this->m_guess); }

void Hangman::update_state() { (is_correct()) ? update_correct() : update_wrong(); }

const std::string& Hangman::answer() const { return this->m_answer; }

const std::string& Hangman::correct() const { return this->m_correct; }

const std::vector<char>& Hangman::wrong() const { return this->m_wrong; }

std::size_t Hangman::wrong_count() const { return this->m_wrong.size(); }

bool Hangman::is_won() const { return this->m_correct == this->m_answer; }

bool Hangman::is_lost() const {
  return this->m_wrong.size() == this->m_wrong.capacity();
}

bool Hangman::is_correct() const {
  bool correct = false;

  for (const char letter : this->m_answer) {
    if (this->m_guess == letter) {
      correct = true;
      break;
    }
  }

  return correct;
}
