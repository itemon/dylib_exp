#include "treenode.h"
#include <iostream>

TreeNode::TreeNode(std::string* d) {
  data = d;
}

TreeNode::TreeNode(std::string&& d) {
  data = &d;
}

TreeNode::~TreeNode() {
  std::cout << "delete treenode data " << (*data) << std::endl;
  delete data;
}

std::string* TreeNode::getData() const {
  return data;
}
