#include "linked_list.hpp"

Node* reverseKGroup(Node* head, int k) {
  Node* curr = head;
  int count = 0;

  while (curr != nullptr && count < k) {
    curr = curr->next;
    count++;
  }

  if (count < k) {
    return head;
  }

  curr = head;
  Node* prev = nullptr;
  Node* next = nullptr;
  count = 0;

  while (curr != nullptr && count < k) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
    count++;
  }

  if (next != nullptr) {
    head->next = reverseKGroup(next, k);
  }

  return prev;
}

int main() {
  auto head = new Node(1);
  head->next = new Node(2);
  head->next->next = new Node(3);
  head->next->next->next = new Node(4);
  head->next->next->next->next = new Node(5);

  int k = 2;
  Node* res = reverseKGroup(head, k);

  while (res != nullptr) {
    std::cout << res->data << " ";
    res = res->next;
  }
  return 0;
}
