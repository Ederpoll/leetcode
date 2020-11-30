#include <stdio.h>
struct ListNode {
    int val;
    struct ListNode* next;
};
struct ListNode* reverseList(struct ListNode* head)
{
    if (!head || !head->next) {
        return head;
    }

    struct ListNode* tmp1 = head->next;
    struct ListNode* tmp = reverseList(head->next);
    tmp1->next = head;
    head->next = NULL;
    return tmp;
}