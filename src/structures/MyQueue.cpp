template <typename T>
MyQueue<T>::MyQueue() : head(nullptr) {}

template <typename T>
void MyQueue<T>::pull()
{
  if (head != nullptr)
  {
    Node<T> *temp = head;
    head = head->getNext();
    delete temp;
  }
}

template <typename T>
void MyQueue<T>::push(const T &item)
{
  Node<T> *newNode = new Node<T>(item);
  if (head == nullptr)
  {
    head = newNode;
  }
  else
  {
    Node<T> *temp = head;
    while (temp->getNext() != nullptr)
    {
      temp = temp->getNext();
    }
    temp->setNext(newNode);
  }
}

template <typename T>
bool MyQueue<T>::isEmpty() const
{
  return head == nullptr;
}

template <typename T>
T MyQueue<T>::peek() const
{
  if (head != nullptr)
  {
    return head->getData();
  }
  return T();
}
