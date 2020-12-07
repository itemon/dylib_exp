#include <cstdio>
#include <vector>
#include <iostream>
#include "mytrans.h"

// export as c symbol
extern "C" {
  const char* mytrans_proceed(const char* lang) {
    std::vector<int> states = { 1, 2, 3, 4 };
    printf("how many items: %lu\n", states.size());
    return "hello world";
  }
}
