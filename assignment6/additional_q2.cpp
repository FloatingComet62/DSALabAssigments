#include <iostream>

class CNode {
public:
  int data;
  CNode* next;
  CNode(int v) { data=v; }
};

class DNode {
public:
  int data;
  DNode* prev;
  DNode* next;
  DNode(int v) { data=v; }
};

bool evenParity(int x){
  return x % 2 == 0;
}

CNode* removeEvenParityFromCLL(CNode* head) {
  if (!head) return nullptr;
  while (head && evenParity(head->data)) {
    if(head->next == head){
      delete head;
      return nullptr;
    }
    CNode* tail = head;
    while(tail->next != head) tail=tail->next;
    CNode* tmp = head;
    head = head->next;
    tail->next = head;
    delete tmp;
  }
  if (!head) return nullptr;
  CNode* prev = head;
  CNode* curr = head->next;
  while (curr!=head) {
    if (evenParity(curr->data)) {
      prev->next = curr->next;
      delete curr;
      curr = prev->next;
    } else {
      prev = curr;
      curr = curr->next;
    }
  }
  return head;
}

DNode* removeEvenParityFromDLL(DNode* head) {
  DNode* curr = head;
  while (curr) {
    if (!evenParity(curr->data)) {
      curr = curr->next;
      continue;
    }
    DNode* del = curr;
    if (curr == head) {
      head = head->next;
      if (head) head->prev=nullptr;
      curr = head;
      delete del;
      continue;
    }
    DNode* p = curr->prev;
    DNode* n = curr->next;
    p->next = n;
    if (n) n->prev = p;
    curr = n;
    delete del;
  }
  return head;
}

void printCLL(CNode* head) {
    if (!head) {
      std::cout<<"Empty\n";
      return;
    }
    CNode* cur = head;
    bool first = true;
    while (first || cur!=head) {
        first = false;
        std::cout << cur->data;
        cur = cur->next;
        if (cur != head) std::cout << " -> ";
    }
    std::cout<<"\n";
}

void printDLL(DNode* head) {
    if (!head) {
      std::cout<<"Empty\n";
      return;
    }
    DNode* cur = head;
    bool first = true;
    while (cur) {
        if (!first) std::cout << " <=> ";
        first = false;
        std::cout << cur->data;
        cur = cur->next;
    }
    std::cout << "\n";
}

int main() {
    CNode* c1 = new CNode(9);
    CNode* c2 = new CNode(11);
    CNode* c3 = new CNode(34);
    CNode* c4 = new CNode(6);
    CNode* c5 = new CNode(13);
    CNode* c6 = new CNode(21);
    c1->next=c2; c2->next=c3; c3->next=c4; c4->next=c5; c5->next=c6; c6->next=c1;

    CNode* cres = removeEvenParityFromCLL(c1);
    printCLL(cres);

    DNode* d1 = new DNode(18);
    DNode* d2 = new DNode(15);
    DNode* d3 = new DNode(8);
    DNode* d4 = new DNode(9);
    DNode* d5 = new DNode(14);
    d1->next = d2; d2->prev = d1;
    d2->next = d3; d3->prev = d2;
    d3->next = d4; d4->prev = d3;
    d4->next = d5; d5->prev = d4;

    DNode* dres = removeEvenParityFromDLL(d1);
    printDLL(dres);

    return 0;
}
