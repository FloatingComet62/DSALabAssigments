#include "linked_list.hpp"

int main() {
  SinglyLinkedList sll;
  sll.insertAtEnd(1);
  sll.insertAtEnd(2);
  sll.insertAtEnd(3);
  sll.insertAtEnd(4);
  sll.insertAtEnd(5);

  int n = 0;
  Node* curr = sll.head;
  while (curr != nullptr) {
    n++;
    curr = curr->next;
  }

  int mid = n/2;
  curr = sll.head;
  while (mid-- > 0) curr = curr->next;

  std::cout << curr->data << "\n";
}
