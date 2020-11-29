#include "../include/uthash.h"
#include <stdio.h>
#include <stdlib.h>
struct hash_table {
    int key;
    int val;
    UT_hash_handle hh;
};

typedef struct hash_table* hash_ptr;

struct pair {
    int first;
    int second;
};

void swap(struct pair* a, struct pair* b)
{
    struct pair t = *a;
    *a = *b, *b = t;
}

void sort(struct pair* v, int start, int end, int* ret, int* retSize, int k)
{
    int picked = rand() % (end - start + 1) + start;
    swap(&v[picked], &v[start]);

    int pivot = v[start].second;
    int index = start;
    for (int i = start + 1; i <= end; i++) {
        if (v[i].second >= pivot) {
            swap(&v[index + 1], &v[i]);
            index++;
        }
    }
    swap(&v[start], &v[index]);

    if (k <= index - start) {
        sort(v, start, index - 1, ret, retSize, k);
    } else {
        for (int i = start; i <= index; i++) {
            ret[(*retSize)++] = v[i].first;
        }
        if (k > index - start + 1) {
            sort(v, index + 1, end, ret, retSize, k - (index - start + 1));
        }
    }
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize)
{
    hash_ptr head = NULL;
    hash_ptr p = NULL, tmp = NULL;

    for (int i = 0; i < numsSize; i++) {
        HASH_FIND_INT(head, &nums[i], p);
        if (p == NULL) {
            p = malloc(sizeof(struct hash_table));
            p->key = nums[i];
            p->val = 1;
            HASH_ADD_INT(head, key, p);
        } else {
            p->val++;
        }
    }
    struct pair values[numsSize];
    int valuesSize = 0;

    HASH_ITER(hh, head, p, tmp)
    {
        values[valuesSize].first = p->key;
        values[valuesSize++].second = p->val;
    }
    int* ret = malloc(sizeof(int) * k);
    *returnSize = 0;
    sort(values, 0, valuesSize - 1, ret, returnSize, k);
    return ret;
}