#ifndef Queue_H
#define Queue_H
#include <stdexcept>
#define invalid_argument std::invalid_argument

#define STEP 50

namespace SimpleDSA
{
  template <typename T>
  class Queue
  {
  private:
    int arraySize;
    int front;
    int back;
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
    Queue();
    void enqueue(T &element);
    T dequeue();
    T &peek();
    bool isEmpty();
  };

  template <typename T>
  Queue<T>::Queue()
  {
    arraySize = STEP;
    front = 0;
    back = 0;
    arr = new T[STEP];
  }

  template <typename T>
  void Queue<T>::enqueue(T &element)
  {
    if (back < arraySize)
    {
      arr[back] = element;
    }
    else
    {
      extend();
      arr[back] = element;
    }
    ++back;
  }

  template <typename T>
  T Queue<T>::dequeue() {
    if (isEmpty())
      throw invalid_argument("Queue is empty");
    
    T val = arr[front];
    ++front;
    return val;
  }

  template <typename T>
  T &Queue<T>::peek()
  {
    return arr[front];
  }

  template <typename T>
  bool Queue<T>::isEmpty()
  {
    return back == 0 || back - front == 0;
  }
}

#endif