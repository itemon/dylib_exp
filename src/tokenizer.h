#ifndef MY_TRANS_TOKENIER
#define MY_TRANS_TOKENIER

#include <string>

class Tokenizer {
  private:
    std::string* name;

  public:
    Tokenizer(std::string* n);
    std::string* getName() const;
};

#endif
