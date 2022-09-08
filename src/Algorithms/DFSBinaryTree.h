#ifndef DFSBinaryTree_H
#define DFSBinaryTree_H
#include <src/DataStructures/BinaryTreeNode.h>
#include <algorithm>

namespace SimpleDSA {
  template<typename T>
  BinaryTreeNode<T> *dfs(BinaryTreeNode<T> root, T val)
  {
    if (root == nullptr) return nullptr;
    if (root->val == T) return root;
    
    BinaryTreeNode<T> *left = dfs(root->left, val);
    return left == nullptr ? dfs(root->right, val) : left;
  }

  template<typename T>
  int calcDepth(BinaryTreeNode<T> *node) {
    if (node == nullptr) return 0;
    return std::max(calcDepth(node->left), calcDepth(node->right)) + 1;
  }
}

#endif