#include "linked_list.hpp"
#include <iostream>

void menu() {
  std::cout <<
    "\n1. insertAtBeginning\n"
    "2. insertAtEnd\n"
    "3. insertAtMiddle\n"
    "4. deleteFromBeginning\n"
    "5. deleteAtEnd\n"
    "6. deleteAtMiddle\n"
    "7. search\n"
    "8. display\n"
  ;
}

int main() {
  SinglyLinkedList sll;
  int res;
  while (true) {
    menu();
    std::cin >> res;
    if (res == 1) {
      int data; std::cout << "Data: "; std::cin >> data;
      sll.insertAtBeginning(data);
    } else if (res == 2) {
      int data; std::cout << "Data: "; std::cin >> data;
      sll.insertAtEnd(data);
    } else if (res == 3) {
      int data; std::cout << "Data: "; std::cin >> data;
      int index; std::cout << "Index: "; std::cin >> index;
      sll.insertMiddle(data, index);
    } else if (res == 4) {
      sll.deleteFromBeginning();
    } else if (res == 5) {
      sll.deleteAtEnd();
    } else if (res == 6) {
      int index; std::cout << "Index: "; std::cin >> index;
      sll.deleteMiddle(index);
    } else if (res == 7) {
      int data; std::cout << "Data: "; std::cin >> data;
      Node* curr = sll.head;
      int i = 0;
      while (curr->next != nullptr && curr->data != data) {
        i++;
        std::cout << curr->data << " ";
        curr = curr->next;
      }
      std::cout << "Found at index " << i << "\n";
    } else if (res == 8) {
      Node* curr = sll.head;
      if (curr == nullptr) continue;
      while (curr != nullptr) {
        std::cout << curr->data << " ";
        curr = curr->next;
      }
    }
  }
}
