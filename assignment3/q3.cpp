#include "stack.hpp"
#include <iostream>
#include <string>

int main() {
  std::string message;
  std::cout << "> ";
  std::cin >> message;

  Stack stack;
  for (const auto& item : message) {
    if (item == '(' || item == '[' || item == '{') {
      stack.push(item);
      continue;
    }
    if (item != ')' && item != ']' && item != '}') continue;
    char closing = stack.pop();
    if (closing == '(' && item == ')') {
      continue;
    }
    if (closing == '[' && item == ']') {
      continue;
    }
    if (closing == '{' && item == '}') {
      continue;
    }
    std::cout << "Unbalanced parentheses\n";
    return 1;
  }
  if (!stack.isEmpty()) {
    std::cout << "Unbalanced parentheses\n";
    return 1;
  }
  std::cout << "Balanced parentheses\n";
  return 0;
}
