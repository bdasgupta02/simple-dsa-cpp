#ifndef SinglyLinkedlist_H
#define SinglyLinkedlist_H
#include <limits.h>

namespace SimpleDSA
{
  template <typename T>
  struct SinglyLinkedNode
  {
    T val;
    SinglyLinkedNode *next;

    SinglyLinkedNode()
    {
      val = INT_MAX;
      next = nullptr;
    }

    SinglyLinkedNode(T &x)
    {
      val = x;
      next = nullptr;
    }
  };
}

#endif