#include "queue.hpp"
#include <iostream>

int main() {
  Queue q;
  q.enqueue(4);
  q.enqueue(7);
  q.enqueue(11);
  q.enqueue(20);
  q.enqueue(5);
  q.enqueue(9);

  Queue q1, q2;
  int length = q.length;
  for (int i = 0; i < length; i+=2) {
    q1.enqueue(q.dequeue());
  }
  for (int i = 1; i < length; i+=2) {
    q2.enqueue(q.dequeue());
  }

  Queue output;
  for (int i = 1; i < length; i+=2) {
    output.enqueue(q1.dequeue());
    output.enqueue(q2.dequeue());
  }

  for (int i = output.top; i != output.bottom; i = (i + 1) % QUEUE_CAPACITY) {
    std::cout << output.data[i] << " ";
  }
  std::cout << std::endl;
}
