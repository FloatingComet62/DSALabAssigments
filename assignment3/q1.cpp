#include "static_stack.hpp"

int main() {
  StaticStack stack;
  while (true) {
    std::string response;
    std::cout << "> ";
    std::cin >> response;
    if (response == "q") {
      break;
    } else if (response == "push") {
      int item;
      std::cout << "Item to push > ";
      std::cin >> item;
      stack.push(item);
    } else if (response == "pop") {
      std::cout << "Popped item: " << stack.pop() << "\n";
    } else if (response == "is_empty") {
      std::cout << stack.isEmpty() << "\n";
    } else if (response == "is_full") {
      std::cout << stack.isFull() << "\n";
    } else if (response == "display") {
      for (int i = 0; i < STATIC_STACK_SIZE; i++) {
        std::cout << "Item " << i + 1 << ": " << stack.items[i] << "\n";
      }
    } else if (response == "peek") {
      std::cout << "Peek: " << stack.peek() << "\n";
    } else  {
      std::cout << "Invalid Command\n";
    }
  }
}
