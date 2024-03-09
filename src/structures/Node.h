#ifndef NODE_H
#define NODE_H

template <typename T>
class Node
{
private:
  T data;
  Node<T> *next;

public:
  Node(const T &data);

  T getData() const;

  Node<T> *getNext() const;

  void setNext(Node<T> *nextNode);
};

#include "Node.cpp"

#endif
