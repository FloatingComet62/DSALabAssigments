#include "doubly_linked_list.hpp"
#include <iostream>

int main() {
  DoublyLinkedList dll;
  dll.insertAtEnd('l');
  dll.insertAtEnd('e');
  dll.insertAtEnd('v');
  dll.insertAtEnd('e');
  dll.insertAtEnd('l');

  Node* head_curr = dll.head;
  Node* tail_curr = dll.tail;
  int palindrome = true;
  while (head_curr != tail_curr) {
    if (head_curr->data == tail_curr->data) {
      head_curr = head_curr->next;
      tail_curr = tail_curr->prev;
      continue;
    }
    palindrome = false;
    break;
  }
  if (palindrome) {
    std::cout << "is a palindrome\n";
  } else {
    std::cout << "is not a palindrome\n";
  }
}
