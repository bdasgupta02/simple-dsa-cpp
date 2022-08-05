#ifndef Queue_H
#define Queue_H
#include <stdexcept>
#define invalid_argument std::invalid_argument

#define STEP 50

namespace SimpleDSA
{
  template <typename T>
  class Stack
  {
  private:
    int arraySize;
    int elementSize;
    T *arr;

    void extend()
    {
      T *temp = new T[arraySize + STEP];
      copy(arr, arr + arraySize, temp);
      delete[] arr;
      arr = temp;
      arraySize += STEP;
    }

  public:
    Stack();
    void push(T &element);
    T &peek();
    T pop();
    bool isEmpty();
    int size();
  };

  template <typename T>
  Stack<T>::Stack()
  {
    arraySize = STEP;
    elementSize = 0;
    arr = new T[STEP];
  }

  template <typename T>
  void Stack<T>::push(T &element)
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
  T &Stack<T>::peek()
  {
    return arr[elementSize - 1];
  }

  template <typename T>
  T Stack<T>::pop()
  {
    if (isEmpty())
      throw invalid_argument("Stack is empty");

    --elementSize;
    return arr[elementSize];
  }

  template <typename T>
  bool Stack<T>::isEmpty()
  {
    return elementSize < 1;
  }

  template <typename T>
  int Stack<T>::size()
  {
    return elementSize;
  }
}

#endif