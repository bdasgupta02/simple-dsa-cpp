#ifndef IntHashSet_H
#define IntHashSet_H
#include <stdexcept>
#include "SinglyLinkedNode.h"
#include "ArrayList.h"
#define invalid_argument std::invalid_argument

#define SIZE 500

namespace SimpleDSA
{
  class IntHashSet
  {
  private:
    int elementCount;
    ArrayList<SinglyLinkedNode<int>> array;
    int getHash(int &el);

  public:
    IntHashSet();
    bool isEmpty();
    bool add(SinglyLinkedNode<int> &element);
    bool contains(int &value);
    int remove(int &value);
  };

  int IntHashSet::getHash(int &el)
  {
    return el % 50;
  }

  IntHashSet::IntHashSet()
  {
    elementCount = 0;
  }

  bool IntHashSet::isEmpty()
  {
    return elementCount == 0;
  }

  bool IntHashSet::add(SinglyLinkedNode<int> &element)
  {
    int hashidx = getHash(element.val);
    
    if (array[hashidx].next == nullptr)
    {
      array[hashidx].next = &element;
      if (array[hashidx].next->val == element.val)
        ++elementCount;
        return true;
    }
    else
    {
      SinglyLinkedNode<int> *cache = &array[hashidx];
      while (cache->next)
      {
        cache = cache->next;
        if (cache->val == element.val)
        {
          throw invalid_argument("Cannot insert duplicate element.val into IntHashSet");
        }
      }
      cache->next = &element;

      if (cache->next->val == element.val)
        ++elementCount;
        return true;
    }

    return false;
  }

  bool IntHashSet::contains(int &value)
  {
    int hashidx = getHash(value);
    SinglyLinkedNode<int> *cache = &array[hashidx];

    while (cache->next != nullptr)
    {
      cache = cache->next;
      if (cache->val == value)
        return true;
    }
    
    return false;
  }

  int IntHashSet::remove(int &value)
  {
    int hashidx = getHash(value);
    SinglyLinkedNode<int> *cache = &array[hashidx];
    SinglyLinkedNode<int> *prev = &array[hashidx];

    while (cache->next != nullptr)
    {
      prev = cache;
      cache = cache->next;
      if (cache->val == value)
      {
        if (cache->next != nullptr)
        {
          prev->next = cache->next;
        }
        else
        {
          prev->next = nullptr;
        }
        --elementCount;
        return value;
      }
    }

    throw invalid_argument("Cannot remove item from IntHashSet");
  }
}

#endif