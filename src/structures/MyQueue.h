#ifndef MYQUEUE_H
#define MYQUEUE_H
#include "Node.h"

template <typename T>
class MyQueue
{
private:
  Node<T> *head;

public:
  MyQueue();

  void pull();

  void push(const T &item);

  bool isEmpty() const;

  T peek() const;
};

#include "MyQueue.cpp"

#endif
