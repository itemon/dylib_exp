#include <iostream>
#include "tree.h"

void add_treenode(TreeNode* node, TreeNode* data) {
  // build up tree
  if (node == nullptr) {
    return;
  }
  std::string* d = data->getData();
  int result = node->getData()->compare(*d);
  if (result == 0){
    return;
  } else if (result > 0) {
    if (node->left == nullptr) {
      node->left = data;
    } else {
      add_treenode(node->left, data);
    }
  } else {
    if (node->right == nullptr) {
      node->right = data;
    } else {
      add_treenode(node->right, data);
    }
  }
}

void loop_tree(TreeNode* treenode) {
  const std::string* data = treenode->getData();
  std::cout << "loop data " << *data << std::endl;
  if (treenode->left) {
    loop_tree(treenode->left);
  }
  if (treenode->right) {
    loop_tree(treenode->right);
  }
}
