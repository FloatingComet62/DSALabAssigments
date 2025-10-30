#include "queue.hpp"
#include "../assignment3/stack.hpp"
#include <cassert>
#include <iostream>

// INCOMPLETE
int main() {
  Queue q;
  q.enqueue(5);
  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);
  q.enqueue(4);

  Stack s;

  Queue output;


  assert(output.dequeue() == 1);
  assert(output.dequeue() == 2);
  assert(output.dequeue() == 3);
  assert(output.dequeue() == 4);
  assert(output.dequeue() == 5);
}
