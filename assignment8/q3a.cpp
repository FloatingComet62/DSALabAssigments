#include "bst.hpp"
#include <iostream>

void printInOrder(Node* root) {
  if (root == nullptr) return;
  printInOrder(root->left);
  std::cout << root->data << " ";
  printInOrder(root->right);
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
  Node* curr = &root;
  Node data_node(data);
  while (true) {
    if (curr->data == data) {
      std::cout << "Duplicates are not allowed\n";
      return 1;
    }
    else if (curr->data > data) {
      if (curr->left == nullptr) {
        curr->left = &data_node;
        break;
      }
      curr = curr->left;
    } else {
      if (curr->right == nullptr) {
        curr->right = &data_node;
        break;
      }
      curr = curr->right;
    }
  }

  printInOrder(&root);
}
