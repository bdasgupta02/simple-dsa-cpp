#ifndef HashMap_H
#define HashMap_H
#include <stdexcept>
#include <functional>
#include "SinglyLinkedNode.h"
#include "HashPair.h"
#include "ArrayList.h"
#define invalid_argument std::invalid_argument
#define hash std::hash

const int STEP_SIZE_MAP = 500;

namespace SimpleDSA
{
  template <typename K, typename V>
  class HashMap
  {
  private:
    int elementCount;
    ArrayList<HashPair<K, V>> array;
    unsigned int getHashFromKey(K &key);

  public:
    HashMap();
    bool add(HashPair<K, V> &pair);
    bool contains(HashPair<K, V> &pair);
    bool contains(K &key);
    HashPair<K, V> remove(HashPair<K, V> &pair);
    HashPair<K, V> remove(K &key);
    V &getValue(K &key);
    int size();
    bool isEmpty();
  };

  template <typename K, typename V>
  HashMap<K, V>::HashMap()
  {
    elementCount = 0;
    array = ArrayList<HashPair<K, V>>(STEP_SIZE_MAP);
  }

  template <typename K, typename V>
  unsigned int HashMap<K, V>::getHashFromKey(K &key)
  {
    return hash<K>{}(key) % STEP_SIZE_MAP;
  }

  template <typename K, typename V>
  bool HashMap<K, V>::add(HashPair<K, V> &pair)
  {
    unsigned int hashidx = pair.getHash();

    if (array[hashidx].next == nullptr)
    {
      array[hashidx].next = &pair;
      if (array[hashidx].next->key() == pair.key())
      {
        ++elementCount;
        return true;
      }
    }
    else
    {
      HashPair<K, V> *cache = &array[hashidx];
      while (cache->next)
      {
        cache = cache->next;
        if (cache->key() == pair.key())
        {
          throw invalid_argument("Cannot insert duplicate key into IntHashSet");
        }
      }
      cache->next = &pair;

      if (cache->next->key() == pair.key())
      {
        ++elementCount;
        return true;
      }
    }

    return false;
  }

  template <typename K, typename V>
  bool HashMap<K, V>::contains(HashPair<K, V> &pair)
  {
    unsigned int hashidx = pair.getHash();
    HashPair<K, V> *cache = &array[hashidx];

    while (cache->next != nullptr)
    {
      cache = cache->next;
      if (cache->key() == pair.key())
        return true;
    }

    return false;
  }

  template <typename K, typename V>
  bool HashMap<K, V>::contains(K &key)
  {
    unsigned int hashidx = getHashFromKey(key);
    HashPair<K, V> *cache = &array[hashidx];

    while (cache->next != nullptr)
    {
      cache = cache->next;
      if (cache->key() == key)
        return true;
    }

    return false;
  }

  template <typename K, typename V>
  HashPair<K, V> HashMap<K, V>::remove(HashPair<K, V> &pair)
  {
    unsigned int hashidx = pair.getHash();
    HashPair<K, V> *cache = &array[hashidx];
    HashPair<K, V> *prev = &array[hashidx];

    while (cache->next != nullptr)
    {
      prev = cache;
      cache = cache->next;
      if (cache->key() == pair.key())
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
        return pair;
      }
    }

    throw invalid_argument("Cannot find item for removal in HashMap");
  }

  template <typename K, typename V>
  HashPair<K, V> HashMap<K, V>::remove(K &key)
  {
    unsigned int hashidx = getHashFromKey(key);
    HashPair<K, V> *cache = &array[hashidx];
    HashPair<K, V> *prev = &array[hashidx];

    while (cache->next != nullptr)
    {
      prev = cache;
      cache = cache->next;
      if (cache->key() == key)
      {
        HashPair<K, V> popped = *cache;
        if (cache->next != nullptr)
        {
          prev->next = cache->next;
        }
        else
        {
          prev->next = nullptr;
        }
        --elementCount;
        return popped;
      }
    }

    throw invalid_argument("Cannot find item for removal in HashMap");
  }

  template <typename K, typename V>
  V &HashMap<K, V>::getValue(K &key)
  {
    unsigned int hashidx = getHashFromKey(key);
    HashPair<K, V> *cache = &array[hashidx];

    while (cache->next != nullptr)
    {
      cache = cache->next;
      if (cache->key() == key)
        return cache->value();
    }

    throw invalid_argument("Cannot find value based on key in HashMap");
  }

  template <typename K, typename V>
  int HashMap<K, V>::size() { return elementCount; }

  template <typename K, typename V>
  bool HashMap<K, V>::isEmpty() { return elementCount == 0; }
}

#endif