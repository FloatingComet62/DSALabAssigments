#include "linked_list.hpp"

Node* rotateLeft (Node* head, int k) {
    if (!head || !head->next || k == 0) return head;
    int len = 1;
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
        len++;
    }
    k %= len;
    if (k == 0) return head;
    temp->next = head;
    int steps = len-k;
    while (steps--) temp = temp->next;
    Node* newHead = temp->next;
    temp->next = NULL;
    return newHead;
}

int main() {
    return 0;
}
