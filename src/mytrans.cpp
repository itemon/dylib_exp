#include <cstdio>
#include <vector>
#include <iostream>
#include "mytrans.h"
#include "tokenizer.h"

// export as c symbol
extern "C" {
  const char* mytrans_proceed(const char* lang) {
    std::string uniname("hello world");
    Tokenizer t(&uniname);

    std::cout << "tokenizer name: " << *(t.getName()) << std::endl;

    std::vector<int> states = { 1, 2, 3, 4 };
    printf("how many items: %lu\n", states.size());
    return "hello world";
  }
}
