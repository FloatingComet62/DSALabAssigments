#include "queue.hpp"
#include <cassert>

int main() {
  Queue q;
  q.enqueue(11);
  q.enqueue(5);
  q.enqueue(4);
  q.enqueue(21);

  int i = 0;
  while(i++ < 4) {
    int a = q.dequeue();
    int b = q.dequeue();
    if (a > b) { q.enqueue(b); q.enqueue(a); }
    else { q.enqueue(a); q.enqueue(b); }
  }

  assert(q.dequeue() == 4);
  assert(q.dequeue() == 5);
  assert(q.dequeue() == 11);
  assert(q.dequeue() == 21);
}
