#include "queue.hpp"
#include <iostream>
#include <string>

int main() {
  Queue q;
  std::string response;
  while (true) {
    std::cout << "> ";
    while (response.size() == 0) {
      std::getline(std::cin, response);
    }
    if (response == "enqueue") {
      int item;
      std::cout << "Item: ";
      std::cin >> item;
      q.enqueue(item);
    } else if (response == "dequeue") {
      std::cout << q.dequeue() << "\n";
    } else if (response == "is_empty") {
      std::cout << q.isEmpty() << "\n";
    } else if (response == "is_full") {
      std::cout << q.isFull() << "\n";
    } else if (response == "display") {
      for (int i = q.top; i != q.bottom; i = (i + 1) % QUEUE_CAPACITY) {
        std::cout << q.data[i] << " ";
      }
      std::cout << std::endl;
    } else if (response == "peek") {
      std::cout << q.peek() << "\n";
    } else if (response == "quit") {
      break;
    } else {
      std::cout << "Invalid input\n";
    }
    response.clear();
  }
}
