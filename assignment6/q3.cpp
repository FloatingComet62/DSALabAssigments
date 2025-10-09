#include "doubly_linked_list.hpp"

int main() {
  DoublyLinkedList dll;
  dll.insertAtEnd(20);
  dll.insertAtEnd(100);
  dll.insertAtEnd(40);
  dll.insertAtEnd(80);
  dll.insertAtEnd(60);

  CircularDoublyLinkedList cdll;
  cdll.insertAtEnd(20);
  cdll.insertAtEnd(100);
  cdll.insertAtEnd(40);
  cdll.insertAtEnd(80);
  cdll.insertAtEnd(60);

  Node* curr = dll.head;
  int dll_size = 0;
  while (curr != nullptr) {
    curr = curr->next;
    dll_size++;
  }
  std::cout << "Size of dll: " << dll_size << "\n";

  curr = cdll.head;
  int cdll_size = 0;
  while ((cdll_size != 0 && curr != cdll.head) || cdll_size == 0) {
    curr = curr->next;
    cdll_size++;
  }
  std::cout << "Size of cdll: " << cdll_size << "\n";
}
