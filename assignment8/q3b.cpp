#include "bst.hpp"
#include <iostream>

void printInOrder(Node* root) {
  if (root == nullptr) return;
  printInOrder(root->left);
  std::cout << root->data << " ";
  printInOrder(root->right);
}

void deleteNode(Node* node, Node* parent, Node& root) {
  int child_on_right = 1;
  if (parent->left == node) child_on_right = 0;

  int number_of_children = 0;
  if (node->left != nullptr) number_of_children++;
  if (node->right != nullptr) number_of_children++;

  if (number_of_children == 0) {
    if (child_on_right) parent->right = nullptr;
    else parent->left = nullptr;
    delete node;
    return;
  }
  if (number_of_children == 1) {
    Node* child;
    if (node->left != nullptr) child = node->left;
    else child = node->right;
    if (child_on_right) parent->right = child;
    else parent->left = child;
    delete node;
    return;
  }

  Node* successor_parent;
  Node* successor = node->right;
  while (successor->left != nullptr) {
    successor_parent = successor;
    successor = successor->left;
  }

  if (successor->right != nullptr) {
    if (successor_parent == nullptr) {
      successor->left = node->left;
      root = *successor;
      delete node;
      return;
    }
    successor_parent->left = successor->right;
  }

  node->data ^= successor->data;
  successor->data ^= node->data;
  node->data ^= successor->data;

  delete successor;
}

//        50
//   30          70
//  20 40      60 80
// 10              90
//                  100
int main() {
  Node root(50);
  {
    Node one(10);
    Node two(20);
    Node three(30);
    Node four(40);
    two.left = &one;
    three.left = &two;
    three.right = &four;

    root.left = &three;
  }
  {
    Node six(60);
    Node seven(70);
    Node eight(80);
    Node nine(90);
    Node ten(100);
    seven.left = &six;
    nine.right = &ten;
    eight.right = &nine;
    seven.right = &eight;
    root.right = &seven;
  }
  
  int data; std::cout << "> "; std::cin >> data;
  Node* prev = nullptr;
  Node* curr = &root;
  Node data_node(data);
  while (true) {
    if (curr->data == data) {
      deleteNode(curr, prev, root);
    }
    else if (curr->data > data) {
      if (curr->left == nullptr) {
        std::cout << "Item not found";
        return 1;
      }
      prev = curr;
      curr = curr->left;
    } else {
      if (curr->right == nullptr) {
        std::cout << "Item not found";
        return 1;
      }
      prev = curr;
      curr = curr->right;
    }
  }

  printInOrder(&root);
}
