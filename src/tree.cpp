#include <iostream>
#include <stack>
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

/**
 * preorder loop tree
 * without using recursive algorithm
 */
void preorder_loop_tree(TreeNode* root) {
  /*
  const std::string* data = root->getData();
  std::cout << "[preorder]loop data " << *data << std::endl;
  */
  using TreeStack = std::stack<TreeNode*>;

  TreeStack tree_cache;
  TreeNode* cur = root;

  while (!tree_cache.empty() || cur) {
    if (!cur) {
      cur = tree_cache.top();
      tree_cache.pop();
      std::cout << "[preorder]cur " << *(cur->getData()) << std::endl;
      cur = cur->right;
    } else {
      tree_cache.push(cur);
      cur = cur->left;
    }
  }
}
