#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b)
{
    return *(int*)a < *(int*)b ? -1 : 1;
}

int majorityElement(int* nums, int numsSize)
{
    qsort(nums, numsSize, sizeof(int), cmp);
    return nums[numsSize / 2];
}