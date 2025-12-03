#include <iostream>
#include <vector>

class DNode {
public:
  int data;
  DNode* prev;
  DNode* next;
  DNode(int v){ data=v; }
};

DNode* buildList(const std::vector<int>& vals) {
  if (vals.empty()) return nullptr;
  DNode* head = new DNode(vals[0]);
  DNode* cur = head;
  for(int i = 1; i < vals.size(); i++) {
    DNode* n = new DNode(vals[i]);
    cur->next = n;
    n->prev = cur;
    cur = n;
  }
  return head;
}

void printDLL(DNode* head) {
  DNode* cur = head;
  bool first = true;
  while (cur) {
    if (!first) std::cout << " <-> ";
    first = false;
    std::cout << cur->data;
    cur = cur->next;
  }
  std::cout<<"\n";
}

DNode* reverseInGroups(DNode* head, int k) {
  if (!head || k <= 1) return head;
  DNode* curr = head;
  DNode* newHead = nullptr;
  DNode* prevGroupTail = nullptr;
  while (curr) {
    DNode* groupStart = curr;
    int count = 1;
    while (count < k && curr->next) {
      curr = curr->next;
      ++count;
    }
    DNode* groupEnd = curr;
    DNode* nextGroupStart = groupEnd->next;
    DNode* x = groupStart;
    DNode* temp = nullptr;
    while (true) {
      temp = x->next;
      x->next = x->prev;
      x->prev = temp;
      if(x == groupEnd) break;
      x = temp;
    }
    DNode* newGroupHead = groupEnd;
    DNode* newGroupTail = groupStart;

    if (!newHead) newHead = newGroupHead;
    if (prevGroupTail) {
      prevGroupTail->next = newGroupHead;
      newGroupHead->prev = prevGroupTail;
    } else newGroupHead->prev = nullptr;

    newGroupTail->next = nextGroupStart;
    if (nextGroupStart) nextGroupStart->prev = newGroupTail;
    prevGroupTail = newGroupTail;
    curr = nextGroupStart;
  }
  return newHead;
}

int main(){
    std::vector<int> v1 = { 1, 2, 3, 4, 5, 6 };
    DNode* head1 = buildList(v1);
    int k1 = 2;
    DNode* res1 = reverseInGroups(head1, k1);
    printDLL(res1);

    std::vector<int> v2 = { 1, 2, 3, 4, 5, 6 };
    DNode* head2 = buildList(v2);
    int k2 = 4;
    DNode* res2 = reverseInGroups(head2, k2);
    printDLL(res2);

    return 0;
}
