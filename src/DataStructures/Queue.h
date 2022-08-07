#ifndef Queue_H
#define Queue_H
#include <stdexcept>
#define invalid_argument std::invalid_argument

#define STEP_QUEUE 50

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
      T *temp = new T[arraySize + STEP_QUEUE];
      copy(arr, arr + arraySize, temp);
      delete[] arr;
      arr = temp;
      arraySize += STEP_QUEUE;
    }

  public:
    Queue();
    void enqueue(T &element);
    T dequeue();
    T &peek();
    bool isEmpty();
    int size();
  };

  template <typename T>
  Queue<T>::Queue()
  {
    arraySize = STEP_QUEUE;
    front = 0;
    back = 0;
    arr = new T[STEP_QUEUE];
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

  template <typename T>
  int Queue<T>::size()
  {
    return back - front;
  }
}

#endif