#include <cassert>
#include "stack.hpp"

class SpecialStack {
  Stack stack;
  Stack minStack;
public:
  void push(int item) {
    stack.push(item);
    if (minStack.isEmpty() || item <= minStack.peek()) {
      minStack.push(item);
    } else {
      minStack.push(minStack.peek());
    }
  }
  void pop() {
    if (stack.isEmpty()) return;
    stack.pop();
    minStack.pop();
  }
  int peek() {
    return stack.peek();
  }

  int getMin() {
    if (minStack.isEmpty()) return -1;
    return minStack.peek();
  }
};

int main() {
  SpecialStack stack;
  stack.push(11);
  stack.push(10);
  stack.push(12);

  assert(stack.getMin() == 10);
  stack.pop();
  assert(stack.getMin() == 10);
  stack.pop();
  assert(stack.getMin() == 11);
}
