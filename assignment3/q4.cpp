#include "stack.hpp"
#include <string>

bool isOperator(char item) {
  return item == '+' || item == '-' || item == '*' || item == '/';
}

bool isNotOperand(char item) {
  return item == '(' || item == ')' || isOperator(item);
}

int getPriority(char op) {
  if (op == '/') return 4;
  if (op == '*') return 3;
  if (op == '+') return 1;
  if (op == '-') return 1;
  return 0;
}

int main() {
  std::string message;
  std::cout << "> ";
  std::getline(std::cin, message);

  std::string expr = "(" + message + ")";

  std::string output;
  Stack stack;
  for (const auto& item : expr) {
    if (item == ' ') continue;
    if (!isNotOperand(item)) {
      output.push_back(item);
      continue;
    }
    if (item == ')') {
      char closing = 0;
      while (closing != '(') {
        closing = stack.pop();
        if (closing != '(') {
          output.push_back(closing);
        }
      }
      continue;
    }
    if (isOperator(item) && isOperator(stack.peek())) {
      int item_priority = getPriority(item);
      int top_priority = getPriority(stack.peek());
      if (item_priority > top_priority) {
        stack.push(item);
        continue;
      }

      while(getPriority(stack.peek()) >= item_priority) {
        output.push_back(stack.pop());
      }
    }
    stack.push(item);
  }
  std::cout << output << "\n";
}

// (A + B) * C - D / E + F
// AB+C*DE/-F+
