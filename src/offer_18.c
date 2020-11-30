#include <stdio.h>
struct ListNode {
    int val;
    struct ListNode* next;
};
struct ListNode* deleteNode(struct ListNode* head, int val)
{
    if (!head) {
        return head;
    }
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode* pre = dummy;
    struct ListNode* cur = head;
    while (cur) {
        if (cur->val == val) {
            pre->next = cur->next;
            free(cur);
            break;
        }
        cur = cur->next;
        pre = pre->next;
    }

    struct ListNode* ans = dummy->next;
    free(dummy);
    return ans;
}