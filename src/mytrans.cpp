#include <cstdio>
#include <vector>
#include <iostream>

#include "mytrans.h"
#include "tokenizer.h"
#include "treenode.h"
#include "tree.h"
#include "algo.h"
#include "site_content_handle.h"

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

    site::site_content_handler handler{ "http://127.0.0.1/site/36kr/list" };
    const std::string * const parsed_content_of_url = handler.content();
    //*parsed_content_of_url = "this is the final urlthis is the final urlthis is the final url";
    std::cout << "url is " << *parsed_content_of_url << std::endl;

    /*
    char test[5] {
      'a', 'b', 'c', 'd', 'e',
    };
    const char * const test_ptr = (const char * const)test;
    test_ptr[0] = 'f';
    std::cout << test << std::endl;

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
    cout << "unsigned long size " << sizeof(unsigned long) << endl;

    cout << "wchar_t size: " << sizeof(wchar_t) << endl;
    char* hw = "huangwei";
    cout << "name size: " << sizeof(hw) << endl;

    // testing treenode
    string flurry{ "flurry" };
    TreeNode treeNodeRoot(&flurry);
    cout << ":::tree node root " << *(treeNodeRoot.getData())<< endl;

    string hello{ "hello" };
    string world{ "world" };
    string doodle { "doodle" };
    string edward{ "edward" };
    string amy{ "amy" };

    TreeNode node_hello { &hello };
    TreeNode node_world { &world };
    TreeNode node_doodle { &doodle };
    TreeNode node_edward { &edward };
    TreeNode node_amy { &amy };

    add_treenode(&treeNodeRoot, &node_hello);
    add_treenode(&treeNodeRoot, &node_world);
    add_treenode(&treeNodeRoot, &node_doodle);
    add_treenode(&treeNodeRoot, &node_edward);
    add_treenode(&treeNodeRoot, &node_amy);

    cout << "before loop down all tree node" << endl;
    loop_tree(&treeNodeRoot);
    cout << "preorder loop" << endl;
    preorder_loop_tree(&treeNodeRoot);
    cout << "root left " << *(treeNodeRoot.left->getData()) << endl;
    */

    //std::string google { "google" };
    //findLongestNonOverlappingStr(&google);

    //test_sleeping();
    //test_concurrency();

    test_mutex();

    return "hello world";
  }
}
