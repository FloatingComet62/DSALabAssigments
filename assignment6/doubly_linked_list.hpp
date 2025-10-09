#include <iostream>
class Node {
public:
  Node* prev;
  int data;
  Node* next;

  Node(int data) {
    this->data = data;
  }
};

class DoublyLinkedList {
public:
  Node* head;
  Node* tail;
  DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
  }
  ~DoublyLinkedList() {
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
    if (this->head != nullptr) this->head->prev = temp;
    temp->next = this->head;
    this->head = temp;
    if (this->tail == nullptr) this->tail = temp;
  }

  void insertAtEnd(int data) {
    Node* temp = new Node(data);
    if (this->tail != nullptr) this->tail->next = temp;
    temp->prev = this->tail;
    this->tail = temp;
    if (this->head == nullptr) this->head = temp;
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
    temp->prev = curr;
    temp->next = next;
    if (next != nullptr) next->prev = temp;
    else this->tail = temp;
  }
};

class CircularDoublyLinkedList {
public:
  Node* head;
  CircularDoublyLinkedList() {
    head = nullptr;
  }
  ~CircularDoublyLinkedList() {
    if (head == nullptr) return;
    Node* curr = head;
    Node* next = nullptr;
    do {
      next = curr->next;
      delete curr;
      curr = next;
    } while(curr != nullptr && curr != head);
  }
  void insertAtEnd(int data) {
    Node* temp = new Node(data);
    if (this->head == nullptr) {
      temp->prev = temp;
      temp->next = temp;
      this->head = temp;
      return;
    }
    Node* curr = this->head;
    while (curr->next != this->head) curr = curr->next;
    curr->next = temp;
    temp->prev = curr;
    temp->next = this->head;
    this->head->prev = temp;
  }
};
