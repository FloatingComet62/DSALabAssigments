#include <iostream>
#include "bst.hpp"

Node* insertNode(Node* root, int val) {
  if (root == NULL) return new Node(val);
  if (val < root->data) root->left = insertNode(root->left, val);
  else root->right = insertNode(root->right, val);
  return root;
}

Node* inorderSuccessor(Node* root, Node* x) {
  Node* succ = NULL;
  while (root) {
    if (x->data >= root->data) {
      root = root->right;
      continue;
    }
    succ = root;
    root = root->left;
  }
  return succ;
}

int main() {
  Node* root = NULL;
  int a[] = {20,8,22,4,12,10,14};
  for (int i = 0; i < 7; i++) root = insertNode(root, a[i]);
  Node* x = root->left->right; 
  Node* s = inorderSuccessor(root, x);
  if (s) std::cout << s->data;
  else std::cout << "No successor";
  return 0;
}
