#include <iostream>

class Node {
public:
    int coeff;
    int pow;
    Node* next;
    Node(int c, int p) {
      coeff = c;
      pow = p;
      next = nullptr;
    }
};

Node* addPoly(Node* p1, Node* p2) {
    Node dummy(0,0);
    Node* tail = &dummy;
    while (p1 && p2) {
        if (p1->pow == p2->pow) {
            int s = p1->coeff + p2->coeff;
            if (s != 0) {
              tail->next = new Node(s, p1->pow);
              tail = tail->next;
            }
            p1 = p1->next;
            p2 = p2->next;
            continue;
        }
        if (p1->pow > p2->pow) {
            tail->next = new Node(p1->coeff, p1->pow);
            tail = tail->next;
            p1 = p1->next;
            continue;
        }
        tail->next = new Node(p2->coeff, p2->pow);
        tail = tail->next;
        p2 = p2->next;
    }
    while (p1) {
      tail->next = new Node(p1->coeff, p1->pow);
      tail = tail->next;
      p1 = p1->next;
    }
    while (p2) {
      tail->next = new Node(p2->coeff, p2->pow);
      tail = tail->next;
      p2 = p2->next;
    }
    return dummy.next;
}

void printPoly(Node* head) {
    if (!head) {
      std::cout<<"0\n";
      return;
    }

    bool first = true;
    while (head) {
        if(!first){
            if (head->coeff > 0) std::cout << " + ";
            else std::cout << " - ";
        } else {
            if (head->coeff < 0) std::cout << "-";
            first = false;
        }
        int c = abs(head->coeff);
        if (head->pow == 0) std::cout << c;
        else if (head->pow == 1){
            if (c != 1) std::cout << c << "x";
            else std::cout << "x";
        } else {
            if (c != 1) std::cout << c << "x^" << head->pow;
            else std::cout << "x^" << head->pow;
        }
        head = head->next;
    }
    std::cout << "\n";
}

Node* push(Node* head, int coeff, int pow) {
    Node* n = new Node(coeff, pow);
    n->next = head;
    return n;
}

int main() {
    Node* poly1 = nullptr;
    poly1 = push(poly1, 5, 2);
    poly1 = push(poly1, 4, 1);
    poly1 = push(poly1, 2, 0);

    Node* poly2 = nullptr;
    poly2 = push(poly2, 5, 1);
    poly2 = push(poly2, 5, 0);
    poly2 = push(poly2, 3, 2);

    poly1 = nullptr;
    poly1 = push(poly1, 2, 0);
    poly1 = push(poly1, 4, 1);
    poly1 = push(poly1, 5, 2);

    poly2 = nullptr;
    poly2 = push(poly2, 5, 0);
    poly2 = push(poly2, 5, 1);
    poly2 = push(poly2, 3, 2);

    Node* result = addPoly(poly1, poly2);
    printPoly(result);
    return 0;
}
