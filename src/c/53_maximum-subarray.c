#define MAX_LEN 10000
#if 0
// 普通的dp版本
int maxSubArray(int* nums, int numsSize){
    int dp[MAX_LEN];
    int max = INT_MIN;
    dp[0] = nums[0];
    for (int i = 1; i < numsSize; i++) {
        dp[i] = fmax(dp[i -1] + nums[i], nums[i]);
        max = fmax(dp[i], max);
    }

    return max;
}
#endif
// 优化了空间复杂度的dp
int maxSubArray(int *nums, int numsSize)
{
    int pre = nums[0];
    int max = nums[0];
    for (int i = 1; i < numsSize; i++)
    {
        pre = fmax(pre + nums[i], nums[i]);
        max = fmax(max, pre);
    }

    return max;
}