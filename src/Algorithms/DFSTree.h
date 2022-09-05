#ifndef DFSTree_H
#define DFSTree_H
#include <src/DataStructures/BinaryTreeNode.h>

namespace SimpleDSA {
  template<typename T>
  BinaryTreeNode<T> *dfs(BinaryTreeNode<T> root, T val)
  {
    if (root == nullptr) return nullptr;
    if (root->val == T) return root;
    
    BinaryTreeNode<T> *left = dfs(root->left, val);
    return left == nullptr ? dfs(root->right, val) : left;
  }
}

#endif