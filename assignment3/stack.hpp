#include <climits>
#include <cstdlib>
#include <iostream>

class Stack {
  int* items;
  int top;
  int capacity;

public:
  Stack() {
    top = -1;
    capacity = 10;
    items = (int*)malloc(capacity * sizeof(*items));
  }
  ~Stack() {
    free(items);
  }

  bool isEmpty() {
    return top == -1;
  }
  void resizeIfFull() {
    if (top < capacity - 1) return;
    capacity += 10;
    items = (int*)realloc(this->items, capacity * sizeof(*items));
  }
  void push(int item) {
    resizeIfFull();
    items[++top] = item;
  }
  int pop() {
    if (isEmpty()) {
      std::cout << "Stack is empty\n";
      return INT_MIN;
    }
    return items[top--];
  }
  int peek() {
    return items[top];
  }
};
