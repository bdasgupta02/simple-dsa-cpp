#ifndef HashMapPair_H
#define HashMapPair_H
#include <utility>
#include <functional>
#include "SinglyLinkedNode.h"
#define hash std::hash
#define entry std::pair
#define create_entry std::make_pair

const int STEP_SIZE_PAIR = 500;

// Hashed singly linked node for HashMaps
namespace SimpleDSA
{
  template <typename K, typename V>
  class HashPair
  {
  private:
    entry<K, V> val;
    unsigned int hashint;

    unsigned int createHash(K &key)
    {
      return hash<K>{}(key) % size;
    }

  public:
    HashPair *next;
    int size;

    HashPair() { next = nullptr; }
    HashPair(K &k, V &v)
    {
      size = STEP_SIZE_PAIR;
      val = create_entry(k, v);
      hashint = createHash(k);
      next = nullptr;
    }
    HashPair(K &k, V &v, int customSize)
    {
      size = customSize;
      val = create_entry(k, v);
      hashint = createHash(k);
      next = nullptr;
    }

    unsigned int &getHash() { return hashint; }
    K &key() { return val.first; }
    V &value() { return val.second; }
  };
}

#endif