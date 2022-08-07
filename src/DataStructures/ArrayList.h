#ifndef ArrayList_H
#define ArrayList_H
#include <stdexcept>
#include <algorithm>
#define invalid_argument std::invalid_argument
#define copy std::copy

const int LIST_STEP = 50;

namespace SimpleDSA
{
  template <typename T>
  class ArrayList
  {
  private:
    int arraySize;
    int elementSize;
    T *arr;

    void extend()
    {
      T *temp = new T[arraySize + LIST_STEP];
      copy(arr, arr + arraySize, temp);
      delete[] arr;
      arr = temp;
      arraySize += LIST_STEP;
    }

  public:
    ArrayList();
    ArrayList(int initialSize);
    int size();
    T get(int index);
    T remove(int index);
    void clear();
    void add(T &element);
    void addAll(ArrayList<T> &other);
    bool valuesEquals(ArrayList<T> &other);
    bool isEmpty();
    int indexOf(T &element);
    T& operator [] (unsigned int i);
    void set(unsigned int i, T &element);
  };

  template <typename T>
  ArrayList<T>::ArrayList()
  {
    arraySize = LIST_STEP;
    elementSize = 0;
    arr = new T[LIST_STEP];
  }

  template <typename T>
  ArrayList<T>::ArrayList(int initialSize)
  {
    arraySize = initialSize;
    elementSize = 0;
    arr = new T[initialSize];
  }

  template <typename T>
  int ArrayList<T>::size()
  {
    return elementSize;
  }

  template <typename T>
  T ArrayList<T>::get(int index)
  {
    if (index >= elementSize)
      throw invalid_argument("Index exceeds list size");

    return arr[index];
  }

  template <typename T>
  T ArrayList<T>::remove(int index)
  {
    if (index >= elementSize)
      throw invalid_argument("Index exceeds list size");

    T atIdx = arr[index];
    copy(arr + index, arr + elementSize, arr + index - 1);
    --elementSize;
    return atIdx;
  }

  template <typename T>
  void ArrayList<T>::clear()
  {
    elementSize = 0;
  }

  template <typename T>
  void ArrayList<T>::add(T &element)
  {
    if (elementSize < arraySize)
    {
      arr[elementSize] = element;
    }
    else
    {
      extend();
      arr[elementSize] = element;
    }
    ++elementSize;
  }

  template <typename T>
  void ArrayList<T>::addAll(ArrayList<T> &other)
  {
    int arrSize = other.size();
    for (int i = 0; i < arrSize; ++i)
    {
      int val = other.get(i);
      add(val);
    }
  }

  template <typename T>
  bool ArrayList<T>::valuesEquals(ArrayList<T> &other)
  {
    if (elementSize != other.elementSize)
      return false;
    for (int i = 0; i < elementSize; ++i)
    {
      if (arr[i] != other.arr[i])
        return false;
    }
    return true;
  }

  template <typename T>
  bool ArrayList<T>::isEmpty()
  {
    return elementSize == 0;
  }

  template <typename T>
  int ArrayList<T>::indexOf(T &element)
  {
    for (int i = 0; i < size(); ++i)
    {
      if (arr[i] == element)
        return i;
    }
    return -1;
  }

  template <typename T>
  T& ArrayList<T>::operator [] (unsigned int i)
  {
    return arr[i];
  }

  template <typename T>
  void ArrayList<T>::set(unsigned int i, T &element)
  {
    arr[i] = element;
  }
}

#endif