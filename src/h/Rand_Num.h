#pragma once

#include <cstdlib>
#include <ctime>

class Rand_Num {
public:
  static Rand_Num& get();
  int gen_int(const int min, const int max);

private:
  Rand_Num();
  Rand_Num(const Rand_Num&) = delete;
  Rand_Num& operator=(const Rand_Num&) = delete;
};
