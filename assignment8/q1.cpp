#include "bst.hpp"
#include <iostream>

void printPreOrder(Node* root) {
  if (root == nullptr) return;
  std::cout << root->data << " ";
  printPreOrder(root->left);
  printPreOrder(root->right);
}
void printInOrder(Node* root) {
  if (root == nullptr) return;
  printInOrder(root->left);
  std::cout << root->data << " ";
  printInOrder(root->right);
}
void printPostOrder(Node* root) {
  if (root == nullptr) return;
  printPostOrder(root->left);
  printPostOrder(root->right);
  std::cout << root->data << " ";
}

//        5
//   3        7
//  2 4      6 8
// 1            9
//               10
int main() {
  Node root(5);
  {
    Node one(1);
    Node two(2);
    Node three(3);
    Node four(4);
    two.left = &one;
    three.left = &two;
    three.right = &four;

    root.left = &three;
  }
  {
    Node six(6);
    Node seven(7);
    Node eight(8);
    Node nine(9);
    Node ten(10);
    seven.left = &six;
    nine.right = &ten;
    eight.right = &nine;
    seven.right = &eight;
    root.right = &seven;
  }

  printInOrder(&root); std::cout << "\n";
  printPreOrder(&root); std::cout << "\n";
  printPostOrder(&root); std::cout << "\n";
}
