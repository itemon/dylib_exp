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
  } else if (result < 0) {
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
