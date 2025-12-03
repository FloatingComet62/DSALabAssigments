#include <iostream>
#include "bst.hpp"

Node* recursiveSearch(Node* root, int key) {
  if (root == NULL || root->data == key) return root;
  if (key < root->data) return recursiveSearch(root->left, key);
  return recursiveSearch(root->right, key);
}

Node* iterativeSearch(Node* root, int key) {
  while (root != NULL) {
    if (root->data == key) return root;
    if (key < root->data) root = root->left;
    else root = root->right;
  }
  return NULL;
}

int main() {
  Node* root = new Node(50);
  root->left = new Node(30);
  root->right = new Node(70);
  root->left->left = new Node(20);
  root->left->right = new Node(40);
  root->right->left = new Node(60);
  root->right->right = new Node(80);

  int key1 = 60;
  Node* r1 = recursiveSearch(root, key1);
  std::cout << "Recursive Search for " << key1 << ": ";
  if (r1 != NULL) std::cout << "Found";
  else std::cout << "Not Found";
  std::cout << "\n";

  int key2 = 25;
  Node* r2 = iterativeSearch(root, key2);
  std::cout << "Iterative Search for " << key2 << ": ";
  if (r2 != NULL) std::cout << "Found";
  else std::cout << "Not Found";
  std::cout << "\n";
}
