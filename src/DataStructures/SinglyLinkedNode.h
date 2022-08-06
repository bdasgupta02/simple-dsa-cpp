#ifndef SinglyLinkedlist_H
#define SinglyLinkedlist_H

namespace SimpleDSA
{
  template <typename T>
  struct SinglyLinkedNode
  {
    T val;
    SinglyLinkedNode<T> next;
  };
}

#endif