#include <stdio.h>
struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    if (!head) {
        return head;
    }
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->val = 0;
    dummy->next = head;
    struct ListNode* first = head;
    struct ListNode* second = dummy;

    int m = n;
    while (m > 0) {
        first = first->next;
        m--;
    }

    while (first != NULL) {
        first = first->next;
        second = second->next;
    }

    second->next = second->next->next;
    struct ListNode* ans = dummy->next;
    free(dummy);
    return ans;
}