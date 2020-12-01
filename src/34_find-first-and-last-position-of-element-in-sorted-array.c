#include <stdio.h>
int getLeftBound(int* nums, int numsSize, int target)
{
    int left = 0;
    int right = numsSize - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] >= target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    if (left >= numsSize || nums[left] != target)
        return -1;
    return left;
}
int getRightBound(int* nums, int numsSize, int target)
{
    int left = 0;
    int right = numsSize - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] <= target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (right < 0 || nums[right] != target)
        return -1;
    return right;
}
int* searchRange(int* nums, int numsSize, int target, int* returnSize)
{
    int left = getLeftBound(nums, numsSize, target);
    int right = getRightBound(nums, numsSize, target);
    int* ans = malloc(sizeof(int) * 2);
    ans[0] = left;
    ans[1] = right;
    *returnSize = 2;
    return ans;
}