#include <cstdio>
#include <vector>
#include <iostream>

#include "mytrans.h"
#include "tokenizer.h"
#include "treenode.h"
#include "tree.h"

using std::string;
using std::cout;
using std::endl;

void show_ref(string&& s) {
  cout << "rvalue ref passed in(" << s << ")" << endl;
}

void show_ref(string& s) {
  cout << "lvalue ref passed in(" << s << ")" << endl;
}

void fwd(string&& s) {
  cout << "#using forward" << endl;
  show_ref(std::forward<string>(s));
  cout << "#plain forward call" << endl;
  show_ref(s);
}

typedef struct _TestHandle {
} TestHandle;

// export as c symbol
extern "C" {
  const char* mytrans_proceed(const char* lang) {
    std::string uniname("hello world");
    Tokenizer t(&uniname);

    std::cout << "tokenizer name: " << *(t.getName()) << std::endl;

    std::vector<int> states = { 1, 2, 3, 4 };
    printf("how many items: %lu\n", states.size());

    string apple{"apple"};
    string& apple_ref = apple;
    //show_ref(std::move(apple_ref));
    //show_ref("apple");

    fwd(std::move(apple_ref));

    cout << "TestHandle* size " << sizeof(TestHandle*) << endl;
    cout << "string* size " << sizeof(string*) << endl;
    cout << "char* size " << sizeof(char* ) << endl;

    cout << "wchar_t size: " << sizeof(wchar_t) << endl;
    char* hw = "huangwei";
    cout << "name size: " << sizeof(hw) << endl;

    // testing treenode
    string *tree_node_data = new string("flurry");
    TreeNode treeNodeRoot(std::move(tree_node_data));
    cout << ":::tree node root " << *(treeNodeRoot.getData())<< endl;

    std::vector<string*> names {
      new string("cindy"),
      new string("amy"),
      new string("dinder"),
      new string("pop"),
      new string("ok"),
      new string("quit"),
    };

    return "hello world";
  }
}
