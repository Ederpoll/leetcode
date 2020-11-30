#include <stdio.h>
struct ListNode {
    int val;
    struct ListNode* next;
};
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
{
    if (!headA || !headB) {
        return NULL;
    }

    struct ListNode* p1 = headA;
    struct ListNode* p2 = headB;
    while (p1 != p2) {
        p1 = p1 ? p1->next : headB;
        p2 = p2 ? p2->next : headA;
    }

    return p1;
}