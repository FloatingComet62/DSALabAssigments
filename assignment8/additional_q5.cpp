#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include "bst.hpp"

Node* buildTreeRec(
  const std::vector<int>& preorder, int pL, int pR,
  const std::vector<int>& inorder, int iL, int iR,
  const std::unordered_map<int,int>& idx
) {
  if (pL > pR) return nullptr;
  int rootVal = preorder[pL];
  Node* root = new Node(rootVal);
  int inRootIndex = idx.at(rootVal);
  int leftSize = inRootIndex - iL;
  root->left = buildTreeRec(
    preorder, pL+1, pL+leftSize,
    inorder, iL, inRootIndex-1,
    idx
  );
  root->right = buildTreeRec(
    preorder, pL+leftSize+1, pR,
    inorder, inRootIndex+1, iR,
    idx
  );
  return root;
}

Node* buildTree(
    const std::vector<int>& preorder,
    const std::vector<int>& inorder
){
  int n = preorder.size();
  std::unordered_map<int,int> idx;
  for(int i = 0; i < n; i++) idx[inorder[i]] = i;
  return buildTreeRec(preorder, 0, n-1, inorder, 0, n-1, idx);
}

void printLevelOrder(Node* root) {
  if (!root) return;
  std::queue<Node*> q;
  q.push(root);
  bool first = true;
  while (!q.empty()) {
    Node* cur = q.front(); q.pop();
    if (!first) std::cout << " ";
    first = false;
    std::cout << cur->data;
    if (cur->left) q.push(cur->left);
    if (cur->right) q.push(cur->right);
  }
  std::cout << "\n";
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
  std::vector<int> preorder(n), inorder(n);
  for (int i = 0; i < n; i++) std::cin >> preorder[i];
  for (int i = 0; i < n; i++) std::cin >> inorder[i];
  Node* root = buildTree(preorder, inorder);
  printLevelOrder(root);
  deleteTree(root);
  return 0;
}
