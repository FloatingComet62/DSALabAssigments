#include "linked_list.hpp"

void removeLoop(Node* head) {
    if (!head || !head->next) return;
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
    }
    if (slow != fast) return;
    slow = head;
    if (slow == fast) {
        while (fast->next != slow) fast = fast->next;
        fast->next = NULL;
        return;
    }
    while (slow->next != fast->next) {
        slow = slow->next;
        fast = fast->next;
    }
    fast->next = NULL;
}

int main() {
    return 0;
}
