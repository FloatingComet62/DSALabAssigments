#include <iostream>
class Node {
public:
  int data;
  Node* next;

  Node(int data) {
    this->data = data;
  }
};

class SinglyLinkedList {
public:
  Node* head;
  SinglyLinkedList() {
    head = nullptr;
  }
  ~SinglyLinkedList() {
    if (head == nullptr) return;
    Node* curr = head;
    Node* next = nullptr;
    do {
      next = curr->next;
      delete curr;
      curr = next;
    } while(curr != nullptr);
  }

  void insertAtBeginning(int data) {
    Node* temp = new Node(data);
    temp->next = this->head;
    this->head = temp;
  }

  void deleteFromBeginning() {
    Node* target = this->head;
    this->head = this->head->next;
    delete target;
  }

  void insertAtEnd(int data) {
    Node* temp = new Node(data);
    if (this->head == nullptr) {
      this->head = temp;
      return;
    }
    Node* curr = head;
    while (curr->next != nullptr) curr = curr->next;
    curr->next = temp;
  }

  void deleteAtEnd() {
    if (this->head == nullptr) {
      return;
    }
    if (this->head->next == nullptr) {
      delete this->head;
      this->head = nullptr;
      return;
    }
    Node* curr = head;
    while (curr->next->next != nullptr) curr = curr->next;
    Node* target = curr->next;
    curr->next = nullptr;
    delete target;
  }

  void insertMiddle(int data, int index) {
    if (index == 0) return insertAtBeginning(data);

    Node* temp = new Node(data);
    Node* curr = this->head;
    while(index-- > 1 && curr != nullptr) curr = curr->next;
    if (curr == nullptr) {
      std::cout << "Index out of bounds\n";
      return;
    }

    Node* next = curr->next;
    curr->next = temp;
    temp->next = next;
  }

  void deleteMiddle(int index) {
    if (index == 0) return deleteFromBeginning();

    Node* curr = this->head;
    while(index-- > 1 && curr != nullptr) curr = curr->next;
    if (curr == nullptr) {
      std::cout << "Index out of bounds\n";
      return;
    }

    Node* target = curr->next;
    curr->next = nullptr;
    delete target;
  }
};
