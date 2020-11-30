#include <stdio.h>
int getMaxNum(int n)
{
    int ans = 1;
    for (int i = 0; i < n; i++) {
        ans *= 10;
    }

    return ans;
}
int* printNumbers(int n, int* returnSize)
{
    int maxNum = getMaxNum(n);
    int* ret = malloc(sizeof(int) * maxNum - 1);
    for (int i = 0; i < maxNum - 1; i++) {
        ret[i] = i + 1;
    }
    *returnSize = maxNum - 1;
    return ret;
}