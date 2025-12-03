#include <iostream>
#include "../assignment5/linked_list.hpp"

void printCircular(Node* head) {
  if (!head) {
  std::cout << "Empty\n";
  return;
  }
  Node* cur = head;
  bool first = true;
  while (first || cur != head) {
    first = false;
    std::cout << cur->data;
    cur = cur->next;
    if (cur != head) std::cout << "->";
  }
  std::cout <<"\n";
}

std::pair<Node*,Node*> splitCircular(Node* head) {
  if (!head) return { nullptr, nullptr };
  if (head->next == head) return { head, nullptr };
  Node* slow = head;
  Node* fast = head;
  while (fast->next != head && fast->next->next != head) {
    slow = slow->next;
    fast = fast->next->next;
  }
  if (fast->next->next == head) fast = fast->next;
  Node* head1 = head;
  Node* head2 = slow->next;
  slow->next = head1;
  fast->next = head2;
  return { head1, head2 };
}

int main(){
    Node* n1 = new Node(10);
    Node* n2 = new Node(4);
    Node* n3 = new Node(9);

    n1->next = n2;
    n2->next = n3;
    n3->next = n1;

    Node* head = n1;
    auto halves = splitCircular(head);
    printCircular(halves.first);
    printCircular(halves.second);
    return 0;
}
