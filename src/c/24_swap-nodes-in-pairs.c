#include <stdio.h>
#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* swapPairs(struct ListNode* head)
{
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode* p1 = head;
    struct ListNode* p2 = head->next;

    struct ListNode* p3 = swapPairs(p2->next);

    p2->next = p1;
    p1->next = p3;

    return p2;
}

void print(struct ListNode* head)
{
    while (head) {
        printf("%d\n", head->val);
        head = head->next;
    }
}

int main()
{
    struct ListNode* p1 = malloc(sizeof(*p1));
    struct ListNode* p2 = malloc(sizeof(*p2));
    struct ListNode* p3 = malloc(sizeof(*p3));
    struct ListNode* p4 = malloc(sizeof(*p4));

    p1->val = 1;
    p2->val = 2;
    p3->val = 3;
    p4->val = 4;

    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = NULL;

    struct ListNode* result = swapPairs(p1);
    print(result);
}