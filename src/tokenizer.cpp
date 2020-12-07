
#include "tokenizer.h"

Tokenizer::Tokenizer(std::string* n) : name(n) {
}

std::string* Tokenizer::getName() const {
  return name;
}

