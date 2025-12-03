#include <iostream>

class DNode {
public:
  int data;
  DNode* prev;
  DNode* next;
  DNode(int d){ data=d; }
};

void correctPointer(DNode* head) {
    if (!head) return;
    if (head->next && head->next->prev != head) {
        head->next->prev = head;
        return;
    }
    if (head->prev) {
        head->prev = nullptr;
        return;
    }
    DNode* temp = head->next;
    while (temp) {
        if (temp->next && temp->next->prev != temp) {
            temp->next->prev = temp;
            return;
        }
        if (temp->prev && temp->prev->next != temp) {
            temp->prev->next = temp;
            return;
        }
        temp = temp->next;
    }
}

void printList(DNode* head) {
    DNode* temp = head;
    while(temp) {
        std::cout << temp->data << " (";
        if (temp->prev) std::cout << temp->prev->data << ") ";
        else std::cout << -1 << ") ";
        temp = temp->next;
    }
    std::cout << "\n";
}

int main(){
    DNode* head = new DNode(1);
    head->next = new DNode(2);
    head->next->prev = head;
    head->next->next = new DNode(3);
    head->next->next->prev = head; 
    head->next->next->next = new DNode(4);
    head->next->next->next->prev = head->next->next;

    std::cout << "Incorrect Linked List:\n";
    printList(head);

    correctPointer(head);

    std::cout << "Corrected Linked List:\n";
    printList(head);

    return 0;
}
