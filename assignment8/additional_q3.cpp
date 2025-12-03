#include <iostream>
#include <vector>
#include "bst.hpp"

int maxDepth(Node* root) {
  if (root == nullptr) return 0;

  int l = maxDepth(root->left);
  int r = maxDepth(root->right);

  if (l > r) return l + 1;
  else return r + 1;
}

int main() {
  int T;
  std::cin >> T;

  while (T--) {
    int n;
    std::cin >> n;

    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) std::cin >> arr[i];

    if (n == 0) {
      std::cout << 0 << "\n";
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
    std::cout << maxDepth(root) << "\n";

    for (int i = 0; i < n; i++) {
      if (nodes[i] == nullptr) continue;
      delete nodes[i];
    }
  }

  return 0;
}
