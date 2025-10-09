#include "doubly_linked_list.hpp"

int main() {
  CircularDoublyLinkedList cdll;
  cdll.insertAtEnd(20);
  cdll.insertAtEnd(100);
  cdll.insertAtEnd(40);
  cdll.insertAtEnd(80);
  cdll.insertAtEnd(60);

  std::cout << cdll.head->data << " ";
  Node* curr = cdll.head->next;
  while (curr != cdll.head) {
    std::cout << curr->data << " ";
    curr = curr->next;
  }
  std::cout << curr->data << "\n";
}
