#include "linked_list.hpp"

Node* getIntersectionNode(Node* headA, Node* headB) {
  if (headA == nullptr || headB == nullptr) {
    return nullptr;
  }
  Node* a = headA;
  Node* b = headB;

  while (a != b) {
    if (a != nullptr) {
      a = a->next;
    } else {
      a = headB;
    }

    if (b != nullptr) {
      b = b->next;
    } else {
      b = headA;
    }
  }
  return a;
}

int main() {
  auto common = new Node(8);
  common->next = new Node(10);

  auto headA = new Node(3);
  headA->next = new Node(7);
  headA->next->next = common;

  auto headB = new Node(99);
  headB->next = new Node(1);
  headB->next->next = common;

  Node* inter = getIntersectionNode(headA, headB);

  if (inter != nullptr) {
    std::cout << inter->data << '\n';
  } else {
    std::cout << "null\n";
  }

  return 0;
}
