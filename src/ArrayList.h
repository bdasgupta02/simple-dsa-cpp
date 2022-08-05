#ifndef ArrayList_H
#define ArrayList_H
#include <stdexcept>
#include <algorithm>
#include <iostream>
#define invalid_argument std::invalid_argument
#define copy std::copy

namespace SimpleDSA
{
  template <typename T>
  class ArrayList
  {
  private:
    static const int step = 10;
    int arraySize;
    int elementSize;
    T *arr;

    void extend()
    {
      T *temp = new T[arraySize + step];
      copy(arr, arr + arraySize, temp);
      delete[] arr;
      arr = temp;
      arraySize += step;
    }

  public:
    ArrayList();
    int size();
    T get(int index);
    T remove(int index);
    T *getArr();
    void clear();
    void add(T element);
    void addAll(ArrayList<T> other);
    bool equals(ArrayList<T> other);
    bool isEmpty();
    int indexOf(T element);
  };

  template <typename T>
  ArrayList<T>::ArrayList()
  {
    arraySize = 10;
    elementSize = 0;
    arr = new T[step];
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
  void ArrayList<T>::add(T element)
  {
    if (elementSize < arraySize)
    {
      arr[elementSize] = element;
    }
    else
    {
      this->extend();
      arr[elementSize] = element;
    }
    ++elementSize;
  }

  template <typename T>
  T *ArrayList<T>::getArr()
  {
    return arr;
  }
}

#endif

// index of returns -1 if not found\
// Need new constructor with bracket array
// Fix get() null pointer issue if index exceeds e size