#include <stdio.h>
#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode* next;
};
#define MAX_SIZE 10000
int* reversePrint(struct ListNode* head, int* returnSize)
{
    if (!head) {
        *returnSize = 0;
        return head;
    }
    int* ans = malloc(sizeof(int) * MAX_SIZE);
    *returnSize = 0;
    int end = MAX_SIZE - 1;
    while (head) {
        ans[end--] = head->val;
        head = head->next;
        (*returnSize)++;
    }

    memmove(ans, ans + MAX_SIZE - *returnSize, sizeof(int) * (*returnSize));
    return ans;
}