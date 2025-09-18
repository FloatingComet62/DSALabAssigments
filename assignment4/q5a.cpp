#include "queue.hpp"
#include <iostream>

class Stack {
  Queue* in_queue;
  Queue* data_queue;
public:
  Stack() {
    in_queue = new Queue();
    data_queue = new Queue();
  }

  void push(int item) {
    if (isFull()) {
      return;
    }
    in_queue->enqueue(item);
    while (!data_queue->isEmpty()) in_queue->enqueue(data_queue->dequeue());

    long temp = (long)in_queue;
    in_queue = data_queue;
    data_queue = (Queue*)temp;
  }

  int pop() {
    if (isEmpty()) {
      return 0;
    }
    return data_queue->dequeue();
  }

  bool isEmpty() {
    return data_queue->isEmpty();
  }
  bool isFull() {
    return data_queue->isFull();
  }
};

int main() {
  Stack s;
  s.push(1);
  s.push(2);
  s.push(3);
  std::cout << s.pop() << " should be 3\n";
  std::cout << s.pop() << " should be 2\n";
  std::cout << s.pop() << " should be 1\n";
}
