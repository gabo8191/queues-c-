#include <iostream>
#include "../structures/MyQueue.h"

int main()
{
  MyQueue<int> queue;
  queue.push(500);
  queue.push(50);
  queue.push(10);
  queue.push(5);
  queue.push(100);

  while (!queue.isEmpty())
  {
    std::cout << queue.peek() << std::endl;
    queue.pull();
  }

  return 0;
}

// To compile and run:
// cd presenter
// g++ presenter.cpp -o presenter
// ./presenter
