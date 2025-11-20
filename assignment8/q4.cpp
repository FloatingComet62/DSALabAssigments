#include "bst.hpp"
#include "../assignment3/stack.hpp"
#include <climits>
#include <iostream>

void printInOrder(Node* root) {
  if (root == nullptr) return;
  printInOrder(root->left);
  std::cout << root->data << " ";
  printInOrder(root->right);
}

bool checkBST(Stack* s, Node* root, bool is_left) {
  if (root == nullptr) return true;
  if (s->peek() < root->data && is_left) return false;
  if (s->peek() > root->data && !is_left) return false;
  s->push(root->data);
  bool l = checkBST(s, root->left, true);
  if (!l) {
    s->pop();
    return false;
  }
  bool r = checkBST(s, root->right, false);
  if (!r) {
    s->pop();
    return false;
  }
  s->pop();
  return true;
}

bool isValidBST(Node* root) {
  Stack s;
  s.push(root->data);
  bool l = checkBST(&s, root->left, true);
  if (!l) {
    s.pop();
    return false;
  }
  bool r = checkBST(&s, root->right, false);
  if (!r) {
    s.pop();
    return false;
  }
  s.pop();
  return true;
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

  std::cout << isValidBST(&root) << "\n";
}
