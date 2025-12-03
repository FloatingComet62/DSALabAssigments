#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include "bst.hpp"

Node* buildRec(
  const std::vector<int>& inorder, int iL, int iR,
  const std::vector<int>& postorder, int pL, int pR,
  const std::unordered_map<int,int>& idx
){
  if (iL > iR) return nullptr;
  int rootVal = postorder[pR];
  Node* root = new Node(rootVal);
  int inRoot = idx.at(rootVal);
  int leftSize = inRoot - iL;
  root->left = buildRec(
    inorder, iL, inRoot-1,
    postorder, pL, pL+leftSize-1,
    idx
  );
  root->right = buildRec(
    inorder, inRoot+1, iR,
    postorder, pL+leftSize, pR-1,
    idx
  );
  return root;
}

Node* buildTree(
  const std::vector<int>& inorder,
  const std::vector<int>& postorder
){
  int n = inorder.size();
  if (n == 0) return nullptr;
  std::unordered_map<int,int> idx;
  for (int i = 0; i < n; i++) idx[inorder[i]] = i;
  return buildRec(inorder, 0, n-1, postorder, 0, n-1, idx);
}

void printLevelOrder(Node* root) {
  if(!root) return;
  std::queue<Node*> q;
  q.push(root);
  bool first = true;
  while(!q.empty()) {
    Node* cur = q.front(); q.pop();
    if(!first) std::cout << " ";
    first = false;
    std::cout << cur->data;
    if(cur->left) q.push(cur->left);
    if(cur->right) q.push(cur->right);
  }
  std::cout << "\n";
}

void deleteTree(Node* root) {
  if(!root) return;
  deleteTree(root->left);
  deleteTree(root->right);
  delete root;
}

int main() {
  int n;
  if (!(std::cin >> n)) return 0;
  std::vector<int> inorder(n), postorder(n);
  for (int i = 0; i < n; i++) std::cin >> inorder[i];
  for (int i = 0; i < n; i++) std::cin >> postorder[i];
  Node* root = buildTree(inorder, postorder);
  printLevelOrder(root);
  deleteTree(root);
  return 0;
}
