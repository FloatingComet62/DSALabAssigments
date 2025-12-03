#include <iostream>
#include "bst.hpp"

Node* insertNode(Node* root, int val) {
  if (root == NULL) return new Node(val);
  if (val < root->data) root->left = insertNode(root->left, val);
  else root->right = insertNode(root->right, val);
  return root;
}

int maxDepth(Node* root) {
    if (root == NULL) return 0;
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    if (l > r) return l + 1;
    return r + 1;
}

int minDepth(Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    if (root->left == NULL) return minDepth(root->right) + 1;
    if (root->right == NULL) return minDepth(root->left) + 1;
    int l = minDepth(root->left);
    int r = minDepth(root->right);
    if (l < r) return l + 1;
    return r + 1;
}

int main() {
    Node* root = NULL;
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 70);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 60);
    root = insertNode(root, 80);
    std::cout << "Maximum depth: " << maxDepth(root) << "\n";
    std::cout << "Minimum depth: " << minDepth(root) << "\n";
    return 0;
}
