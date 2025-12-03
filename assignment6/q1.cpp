#include <iostream>
#include "doubly_linked_list.hpp"

int main() {
  DoublyLinkedList dlist;
  CircularDoublyLinkedList clist;
  int choice, type, val, key;
  std::cout << "Choose List Type:\n1. Doubly Linked List\n2. Circular Linked List\nEnter choice: ";
  std::cin >> type;
  do {
    std::cout << "\n=== Menu ===\n";
    std::cout << "1. Insert at Beginning\n2. Insert at End\n";
    std::cout << "3. Delete Node\n4. Search Node\n5. Display\n6. Exit\n";
    std::cout << "Enter choice: ";
    std::cin >> choice;
    switch (choice) {
    case 1:
      std::cout << "Enter value: ";
      std::cin >> val;
      if (type == 1) dlist.insertAtBeginning(val);
      else std::cout << "Not applicable for Circular List.\n";
      break;
    case 2:
      std::cout << "Enter value: ";
      std::cin >> val;
      if (type == 1) dlist.insertAtEnd(val);
      else clist.insertAtEnd(val);
      break;
    case 3:
      std::cout << "Enter value to delete: ";
      std::cin >> key;
      if (type == 1) dlist.deleteNode(key);
      else clist.deleteNode(key);
      break;
    case 4:
      std::cout << "Enter value to search: ";
      std::cin >> key;
      if (type == 1) dlist.search(key);
      else clist.search(key);
      break;
    case 5:
      if (type == 1) dlist.display();
      else clist.display();
      break;
    case 6:
      std::cout << "Exiting program...\n";
      break;
    default:
      std::cout << "Invalid choice!\n";
    }
  } while (choice != 8);
  return 0;
}
