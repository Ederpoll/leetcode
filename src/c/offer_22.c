#include <stdio.h>
struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* getKthFromEnd(struct ListNode* head, int k)
{
    if (!head) {
        return head;
    }

    struct ListNode* slow = head;
    struct ListNode* fast = head;

    for (int i = 0; i < k; i++) {
        fast = fast->next;
    }

    while (fast != NULL) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}