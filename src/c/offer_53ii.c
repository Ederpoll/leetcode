#include <stdio.h>
// 这个题目主要是需要考虑：排序数组内部的查找问题，大部分可以使用二分法来解决

int missingNumber(int* nums, int numsSize)
{
    if (numsSize == 0) {
        return 0;
    }

    int left = 0;
    int right = numsSize - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == mid) {
            left = mid + 1;
        } else if (nums[mid] > mid) {
            right = mid - 1;
        }
    }
    //printf("%d, %d\n", left, right);
    return left;
}