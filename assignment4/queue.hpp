#include <cstdlib>
#define QUEUE_CAPACITY 10

class Queue {
public:
  int length;
  int top;
  int bottom;
  int* data;
  Queue() {
    this->data = (int*)malloc(QUEUE_CAPACITY * sizeof(*data));
    this->top = -1;
    this->bottom = -1;
    this->length = 0;
  }

  bool isFull() {
    return this->length == QUEUE_CAPACITY;
  }
  void enqueue(int item) {
    if (isFull()) {
      return;
    }
    this->data[this->bottom] = item;
    this->bottom = (this->bottom + 1) % QUEUE_CAPACITY;
    this->length++;
  }

  bool isEmpty() {
    return this->length == 0;
  }
  int dequeue() {
    if (isEmpty()) {
      return 0;
    }
    int x = this->data[this->top];
    this->top = (this->top + 1) % QUEUE_CAPACITY;
    this->length--;
    return x;
  }

  int peek() {
    if (isEmpty()) {
      return 0;
    }
    return this->data[this->top];
  }
};
