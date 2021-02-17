#ifndef TREENODE_
#define TREENODE_

#include <string>

class TreeNode {
  public:
    TreeNode(std::string&& data);
    TreeNode(std::string* data);
    ~TreeNode();
    std::string* getData() const;

    TreeNode* left;
    TreeNode* right;

  private:
    std::string* data;
};

#endif
