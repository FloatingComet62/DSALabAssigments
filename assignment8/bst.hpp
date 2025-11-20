#include <cstdlib>
class Node {
public:
  Node* left;
  int data;
  Node* right;
  Node(int data) {
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
  }
};

