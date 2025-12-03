#include <iostream>
#include "bst.hpp"

Node* insertBST(Node* root, int x) {
  if (root == nullptr) return new Node(x);
  if (x < root->data) root->left = insertBST(root->left, x);
  else root->right = insertBST(root->right, x);
  return root;
}

std::pair<Node*,Node*> bstToDLL(Node* root) {
  if (root == nullptr) return {nullptr, nullptr};
  std::pair<Node*,Node*> leftPair = bstToDLL(root->left);
  std::pair<Node*,Node*> rightPair = bstToDLL(root->right);
  Node* head = root;
  Node* tail = root;
  if (leftPair.first) {
    head = leftPair.first;
    leftPair.second->right = root;
    root->left = leftPair.second;
  } else {
    root->left = nullptr;
  }
  if (rightPair.first) {
    tail = rightPair.second;
    root->right = rightPair.first;
    rightPair.first->left = root;
  } else {
    root->right = nullptr;
  }
  return {head, tail};
}

Node* mergeDLLs(Node* a, Node* b) {
  if (a == nullptr) return b;
  if (b == nullptr) return a;

  Node* head = nullptr;
  Node* tail = nullptr;
  Node* p = a;
  Node* q = b;
  if (p->data <= q->data) {
    head = p;
    p = p->right;
  } else {
    head = q;
    q = q->right;
  }

  tail = head;
  tail->left = nullptr;
  while (p && q) {
    if (p->data <= q->data) {
      tail->right = p;
      p->left = tail;
      tail = p;
      p = p->right;
      continue;
    }
    tail->right = q;
    q->left = tail;
    tail = q;
    q = q->right;
  }
  while (p) {
    tail->right = p;
    p->left = tail;
    tail = p;
    p = p->right;
  }
  while (q) {
    tail->right = q;
    q->left = tail;
    tail = q;
    q = q->right;
  }
  return head;
}

void printDLL(Node* head) {
    Node* cur = head;
    while(cur){
        std::cout << cur->data;
        if (cur->right) std::cout << " <-> ";
        cur = cur->right;
    }
    std::cout << " <-> null\n";
}

int main() {
  int n1;
  if (!(std::cin >> n1)) return 0;
  Node* root1 = nullptr;
  for (int i = 0; i < n1; i++) {
    int x; std::cin >> x;
    root1 = insertBST(root1, x);
  }
  int n2; std::cin >> n2;
  Node* root2 = nullptr;
  for (int i = 0; i < n2; i++) {
    int x; std::cin >> x;
    root2 = insertBST(root2, x);
  }
  std::pair<Node*,Node*> p1 = bstToDLL(root1);
  std::pair<Node*,Node*> p2 = bstToDLL(root2);
  Node* head1 = p1.first;
  Node* head2 = p2.first;
  Node* merged = mergeDLLs(head1, head2);
  printDLL(merged);
  return 0;
}
