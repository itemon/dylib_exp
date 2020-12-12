#include <cstdio>
#include <vector>
#include <iostream>
#include "mytrans.h"
#include "tokenizer.h"

using std::string;
using std::cout;
using std::endl;

void show_ref(string&& s) {
  cout << "rvalue ref" << endl;
}

void show_ref(string& s) {
  cout << "ref" << endl;
}

// export as c symbol
extern "C" {
  const char* mytrans_proceed(const char* lang) {
    std::string uniname("hello world");
    Tokenizer t(&uniname);

    std::cout << "tokenizer name: " << *(t.getName()) << std::endl;

    std::vector<int> states = { 1, 2, 3, 4 };
    printf("how many items: %lu\n", states.size());

    std::string bob = "bob";
    std::vector<std::string> people;

    people.push_back(bob);

    std::cout << &bob << ":" << &people[0] << std::endl;

    string&& s = "aaa";
    show_ref(s);

    show_ref("hello");

    string jack{"jack"};
    string& jack2 = jack;
    string&& jack1 = std::move(jack2);
    show_ref(jack1);
    cout << "jack is " << jack << endl;

    return "hello world";
  }
}
