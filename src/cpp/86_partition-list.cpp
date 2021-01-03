#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x)
        : val(x)
        , next(NULL) {};
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x)
    {
        ListNode* big = new ListNode(-1);
        ListNode* l1 = big;
        ListNode* small = new ListNode(-1);
        ListNode* l2 = small;
        while (head) {
            if (head->val < x) {
                l2->next = head;
                l2 = l2->next;
            } else {
                l1->next = head;
                l1 = l1->next;
            }
            head = head->next;
        }

        l1->next = NULL;
        l2->next = NULL;
        l2->next = big->next;
        return small->next;
    }
};