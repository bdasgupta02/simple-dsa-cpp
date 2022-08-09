#ifndef BinaryTreeNode_H
#define BinaryTreeNode_H

namespace SimpleDSA
{
  template <typename T>
  struct BinaryTreeNode
  {
    T val;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode() 
    {
      left = nullptr;
      right = nullptr;
    }

    BinaryTreeNode(T &t)
    {
      val = t;
      left = nullptr;
      right = nullptr;
    }
  };
}

#endif