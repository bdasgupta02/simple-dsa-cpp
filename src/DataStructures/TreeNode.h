#ifndef TreeNode_H
#define TreeNode_H

namespace SimpleDSA
{
  template <typename T>
  struct TreeNode
  {
    T val;
    TreeNode<T> *connected;

    TreeNode() {
      connected = new T[10];
    }
    
    TreeNode(T &x)
    {
      val = x;
      connected = new T[10];
    }
  };
}

#endif