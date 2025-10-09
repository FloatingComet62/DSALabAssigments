#include "doubly_linked_list.hpp"

int simple_solution(const CircularDoublyLinkedList& cdll) {
  Node* curr = cdll.head;
  while (curr != nullptr && curr->next != cdll.head) curr = curr->next;

  if (curr == nullptr) return false;
  return true;
}

int main() {
  CircularDoublyLinkedList cdll;
  cdll.insertAtEnd(2);
  cdll.insertAtEnd(4);
  cdll.insertAtEnd(6);
  cdll.insertAtEnd(7);
  cdll.insertAtEnd(5);

  if (simple_solution(cdll)) {
    std::cout << "first is circular\n";
  } else {
    std::cout << "first is not circular\n";
  }

  // manually make it not circular
  cdll.head->prev->next = nullptr;
  cdll.head->prev = nullptr;

  if (simple_solution(cdll)) {
    std::cout << "second is circular\n";
  } else {
    std::cout << "second is not circular\n";
  }
}
