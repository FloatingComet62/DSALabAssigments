#include "stack.hpp"
#include <iostream>
#include <string>

int main() {
  Stack stack;
  std::string message;
  std::cout << "> ";
  std::cin >> message;

  for (const auto& item : message) {
    stack.push(item);
  }

  while (!stack.isEmpty()) {
    std::cout << (char)stack.pop();
  }
  std::cout << std::endl;
}
