#include "Hangman.h"

Hangman::Hangman(const std::string& word)
  : m_answer(word), m_correct(word.size(), ' '), m_guess('0') {
  const size_t max_wrong = 6;

  this->m_wrong.reserve(max_wrong);
}

const std::string& Hangman::get_answer() const { return this->m_answer; }

const std::string& Hangman::get_correct() const { return this->m_correct; }

const std::vector<char>& Hangman::get_wrong() const { return this->m_wrong; }

size_t Hangman::wrong_count() const { return this->m_wrong.size(); }

void Hangman::set_guess(const char guess) { this->m_guess = guess; }

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

void Hangman::update_correct() {
  for (size_t i = 0; i < this->m_correct.size(); i++) {
    if (this->m_guess == this->m_answer[i]) {
      this->m_correct[i] = this->m_guess;
    }
  }
}

void Hangman::update_wrong() { this->m_wrong.emplace_back(this->m_guess); }

void Hangman::update_state() { (is_correct()) ? update_correct() : update_wrong(); }

bool Hangman::is_won() const { return this->m_correct == this->m_answer; }

bool Hangman::is_lost() const {
  return this->m_wrong.size() == this->m_wrong.capacity();
}
