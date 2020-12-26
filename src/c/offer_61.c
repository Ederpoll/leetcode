#include "../include/uthash.h"
#include <stdbool.h>
#include <stdio.h>
typedef struct hash {
    int key;
    bool cnt;
    UT_hash_handle hh;
} hashTable;
bool isStraight(int* nums, int numsSize)
{
    int min = 14;
    int max = 0;
    hashTable* hashPtr = NULL;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 0)
            continue;
        hashTable* tmp = NULL;
        HASH_FIND_INT(hashPtr, &nums[i], tmp);
        if (tmp) {
            return false;
        } else {
            tmp = malloc(sizeof(hashTable));
            tmp->key = nums[i];
            tmp->cnt = 1;
            HASH_ADD_INT(hashPtr, key, tmp);
        }
        min = fmin(min, nums[i]);
        max = fmax(max, nums[i]);
    }
    return max - min >= 5 ? false : true;
}