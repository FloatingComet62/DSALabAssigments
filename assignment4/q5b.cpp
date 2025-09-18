#include "queue.hpp"
#include <iostream>

class Stack {
  Queue queue;
public:
  void push(int item) {
    if (isFull()) {
      return;
    }
    int length = queue.length;
    queue.enqueue(item);
    for (int i = 0; i < length; i++) {
      queue.enqueue(queue.dequeue());
    }
  }

  int pop() {
    if (isEmpty()) {
      return 0;
    }
    return queue.dequeue();
  }

  bool isEmpty() {
    return queue.isEmpty();
  }

  bool isFull() {
    return queue.isFull();
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
