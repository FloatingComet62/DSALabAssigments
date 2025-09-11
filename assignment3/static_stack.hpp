#include <climits>
#include <iostream>

constexpr int STATIC_STACK_SIZE = 3;
class StaticStack {
  int top;

public:
  int items[STATIC_STACK_SIZE];
  StaticStack() {
    top = -1;
  }

  bool isEmpty() {
    return this->top == -1;
  }
  bool isFull() {
    return this->top == STATIC_STACK_SIZE - 1;
  }
  void push(int item) {
    if (isFull()) {
      std::cout << "StaticStack is full\n";
      return;
    }
    this->items[++this->top] = item;
  }
  int pop() {
    if (isEmpty()) {
      std::cout << "StaticStack is empty\n";
      return INT_MIN;
    }
    return this->items[this->top--];
  }
  int peek() {
    return this->items[this->top];
  }
};
