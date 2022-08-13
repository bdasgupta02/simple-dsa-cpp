#ifndef BST_H
#define BST_H
#include <iostream>
#include <string>
#include <stdexcept>
#include "BinaryTreeNode.h"
#define invalid_argument std::invalid_argument

namespace SimpleDSA
{
  /**
   * @brief Supports any type that supports comparison and equality operators
   *
   * @tparam T Any type that supports comparison operators
   */
  template <typename T>
  class BST
  {
  private:
    void addRecursive(BinaryTreeNode<T> *node, BinaryTreeNode<T> &newNode)
    {
      if (newNode.val > node->val)
      {
        if (node->right == nullptr)
          node->right = &newNode;
        else
          addRecursive(node->right, newNode);
      }
      else
      {
        if (node->left == nullptr)
          node->left = &newNode;
        else
          addRecursive(node->left, newNode);
      }
    }

    T &searchRecursive(BinaryTreeNode<T> *node, T &t)
    {
      if (node == nullptr)
        throw invalid_argument("Cannot find node in BST");
      else if (t == node->val)
        return t;

      if (t > node->val)
        return searchRecursive(node->right, t);
      else
        return searchRecursive(node->left, t);
    }

  public:
    BinaryTreeNode<T> *head;

    BST() {}
    BST(BinaryTreeNode<T> &newHead)
    {
      head = &newHead;
    }

    void add(BinaryTreeNode<T> &node)
    {
      addRecursive(head, node);
    }

    BinaryTreeNode<T> *getHead()
    {
      return head;
    }

    T &search(T &t)
    {
      return searchRecursive(head, t);
    }

    // T remove(T &t)
    // {
    // }
  };
}

#endif