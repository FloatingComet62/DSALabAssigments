#include <iostream>
#include "bst.hpp"

Node* findMin(Node* root) {
  if (root == NULL) return NULL;
  while (root->left != NULL)
      root = root->left;
  return root;
}

Node* findMax(Node* root) {
  if (root == NULL) return NULL;
  while (root->right != NULL)
      root = root->right;
  return root;
}

int main() {
  Node* root = new Node(50);
  root->left = new Node(30);
  root->right = new Node(70);
  root->left->left = new Node(20);
  root->left->right = new Node(40);
  root->right->left = new Node(60);
  root->right->right = new Node(80);

  Node* minm = findMin(root);
  std::cout << "Minimum element: ";
  if (minm != NULL) std::cout << minm->data;
  else std::cout << "None";
  std::cout << "\n";

  Node* maxm = findMax(root);
  std::cout << "Maximum element: ";
  if (maxm != NULL) std::cout << maxm->data;
  else std::cout << "None";
  std::cout << "\n";
}
