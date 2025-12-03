#include <vector>
#include <iostream>
#include <queue>
#include "bst.hpp"

std::vector<Node*> generateTreesRange(int start, int end) {
  std::vector<Node*> res;
  if (start > end) {
    res.push_back(nullptr);
    return res;
  }
  for (int rootVal = start; rootVal <= end; ++rootVal) {
    std::vector<Node*> leftTrees = generateTreesRange(start, rootVal - 1);
    std::vector<Node*> rightTrees = generateTreesRange(rootVal + 1, end);
    for (Node* L : leftTrees) {
      for (Node* R : rightTrees) {
        Node* root = new Node(rootVal);
        root->left = L;
        root->right = R;
        res.push_back(root);
      }
    }
  }
  return res;
}

std::vector<Node*> generateTrees(int n) {
    if (n == 0) return {};
    return generateTreesRange(1, n);
}

void printLevel(Node* root) {
  if (!root) {
    std::cout << "[]";
    return;
  }
  std::queue<Node*> q;
  q.push(root);

  while (!q.empty()) {
    Node* node = q.front(); q.pop();
    if (!node) {
        std::cout << "null";
        continue;
    }
    std::cout << node->data;
    q.push(node->left);
    q.push(node->right);
  }
  return;
}

void deleteTree(Node* root) {
  if (!root) return;
  deleteTree(root->left);
  deleteTree(root->right);
  delete root;
}

int main() {
  int n;
  if (!(std::cin >> n)) return 0;
  std::vector<Node*> trees = generateTrees(n);
  std::cout << "[";
  for (int i = 0; i < trees.size(); ++i) {
    printLevel(trees[i]);
    if (i + 1 < trees.size()) std::cout << ",";
  }
  std::cout << "]";
  for (Node* t : trees) deleteTree(t);
  return 0;
}
