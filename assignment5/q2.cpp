#include "linked_list.hpp"

int main() {
  SinglyLinkedList sll;
  sll.insertAtEnd(1);
  sll.insertAtEnd(2);
  sll.insertAtEnd(1);
  sll.insertAtEnd(2);
  sll.insertAtEnd(1);
  sll.insertAtEnd(3);
  sll.insertAtEnd(1);

  int data;
  std::cout << "Data: ";
  std::cin >> data;

  int count = 0;
  Node* curr = sll.head;
  SinglyLinkedList excludedll;
  while (curr != nullptr) {
    if (curr->data == data) count++;
    else excludedll.insertAtEnd(curr->data);
    curr = curr->next;
  }
  std::cout << "Count: " << count << "\n";

  curr = excludedll.head;
  while (curr != nullptr) {
    std::cout << curr->data << " ";
    curr = curr->next;
  }
  std::cout << "\n";
}
