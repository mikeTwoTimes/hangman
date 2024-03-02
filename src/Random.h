#pragma once

#include <cstdlib>
#include <ctime>

class Random {
public:
  static Random& get();

  int Int(const int min, const int max);

private:
  Random();

  Random(const Random&) = delete;
  Random& operator=(const Random&) = delete;
};
