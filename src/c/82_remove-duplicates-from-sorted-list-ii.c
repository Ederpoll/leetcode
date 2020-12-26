#include "../include/uthash.h"
#include <stdbool.h>
#include <stdio.h>
struct ListNode {
    int val;
    struct ListNode* next;
};

typedef struct hash {
    int val;
    bool repeat;
    UT_hash_handle hh;
} myHash;

struct ListNode* deleteDuplicates(struct ListNode* head)
{
    if (!head) {
        return head;
    }
    myHash* glbHash = NULL;
    struct ListNode* p = head;
    while (p) {
        myHash* tmp = NULL;
        HASH_FIND_INT(glbHash, &(p->val), tmp);
        if (tmp) {
            tmp->repeat = true;
        } else {
            tmp = (myHash*)malloc(sizeof(myHash));
            tmp->val = p->val;
            tmp->repeat = false;
            HASH_ADD_INT(glbHash, val, tmp);
        }
        p = p->next;
    }

    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* prev = &dummy;
    struct ListNode* cur = head;
    while (cur) {
        myHash* tmp = NULL;
        HASH_FIND_INT(glbHash, &(cur->val), tmp);
        if (tmp->repeat) {
            prev->next = cur->next;
            cur = cur->next;
        } else {
            prev = cur;
            cur = cur->next;
        }
    }

    return dummy.next;
}