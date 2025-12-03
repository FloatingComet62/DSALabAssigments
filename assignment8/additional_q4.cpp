#include <iostream>
#include <vector>
#include <queue>
#include "bst.hpp"

std::vector<int> rightView(Node* root) {
  std::vector<int> res;
  if (root == nullptr) return res;
  std::queue<Node*> q;
  q.push(root);
  while (!q.empty()) {
    int sz = q.size();
    for (int i = 0; i < sz; i++) {
      Node* cur = q.front(); q.pop();
      if(i == sz - 1) res.push_back(cur->data);
      if(cur->left) q.push(cur->left);
      if(cur->right) q.push(cur->right);
    }
  }
  return res;
}

int main() {
  int T;
  if (!(std::cin >> T)) return 0;
  while (T--) {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) std::cin >> arr[i];
    if (n == 0) {
      std::cout << "\n";
      continue;
    }
    std::vector<Node*> nodes(n, nullptr);
    for (int i = 0; i < n; i++) {
      if(arr[i] == -1) continue;
      nodes[i] = new Node(arr[i]);
    }
    for (int i = 0; i < n; i++) {
      if (nodes[i] == nullptr) continue;
      int li = 2*i + 1;
      int ri = 2*i + 2;
      if (li < n) nodes[i]->left = nodes[li];
      if (ri < n) nodes[i]->right = nodes[ri];
    }
    Node* root = nodes[0];
    std::vector<int> view = rightView(root);
    for (int i = 0; i < view.size(); i++) {
        if(i) std::cout << " ";
        std::cout << view[i];
    }
    std::cout << "\n";
    for (int i = 0; i < n; i++) {
      if(nodes[i] == nullptr) continue;
      delete nodes[i];
    }
  }
  return 0;
}
