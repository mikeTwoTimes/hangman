#include "Random.h"

Random::Random() { std::srand(std::time(0)); }

Random& Random::get() {
  static Random instance;

  return instance;
}

int Random::Int(const int min, const int max) {
  return (std::rand() % (max - min + 1)) + min;
}
