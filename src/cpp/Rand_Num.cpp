#include "Rand_Num.h"

Rand_Num::Rand_Num() { std::srand(std::time(0)); }

Rand_Num& Rand_Num::get() {
  static Rand_Num instance;

  return instance;
}

int Rand_Num::gen_int(const int min, const int max) {
  return (std::rand() % (max - min + 1)) + min;
}
