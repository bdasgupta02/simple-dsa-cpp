#ifndef DoublyLinkedlist_H
#define DoublyLinkedlist_H

namespace SimpleDSA
{
  template <typename T>
  struct DoublyLinkedNode
  {
    T val;
    DoublyLinkedNode<T> next;
    DoublyLinkedNode<T> previous;
  };
}

#endif