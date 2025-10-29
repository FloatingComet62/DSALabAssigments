#include "linked_list.hpp"

void rev(SinglyLinkedList* sll) {
  if (sll->head == nullptr) return;
  if (sll->head->next == nullptr) return;
  if (sll->head->next->next == nullptr) {
    Node* second = sll->head->next;
    second->next = sll->head;
    sll->head->next = nullptr;
    sll->head = second;
    return;
  }

  Node* a = sll->head;
  Node* b = a->next;
  Node* c = b->next;

  a->next = nullptr;
  while (c != nullptr) {
    b->next = a;
    a = b;
    b = c;
    c = c->next;
  }
  b->next = a;
  
  sll->head = b;
}

int main() {
  SinglyLinkedList sll;
  sll.insertAtEnd(1);
  sll.insertAtEnd(2);
  sll.insertAtEnd(3);
  sll.insertAtEnd(4);

  rev(&sll);

  Node* curr = sll.head;
  while (curr != nullptr) {
    std::cout << curr->data << " ";
    curr = curr->next;
  }
  std::cout << "\n";
}
