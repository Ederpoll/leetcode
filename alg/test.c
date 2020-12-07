#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dfs(int* nums, int numsSize, int** result, int* returnSize, int** returnColumnSizes, int* temp, int tempSize, int cur)
{
    int* ans = (int*)malloc(sizeof(int) * tempSize);
    memcpy(ans, temp, sizeof(int) * tempSize);
    (*returnColumnSizes)[*returnSize] = tempSize;
    result[(*returnSize)++] = ans;

    for (int i = cur; i < numsSize; i++) {
        temp[tempSize] = nums[i];
        dfs(nums, numsSize, result, returnSize, returnColumnSizes, temp, tempSize + 1, cur + 1);
    }
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    if (numsSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    int size = 1 << numsSize;

    int** result = (int**)malloc(sizeof(int*) * size);
    int* temp = (int*)malloc(sizeof(int) * size);
    *returnColumnSizes = (int*)malloc(sizeof(int) * size);
    dfs(nums, numsSize, result, returnSize, returnColumnSizes, temp, 0, 0);
    return result;
}

int main()
{
    int nums[3] = { 1, 2, 3 };
    int size = 0;
    int* returncol;
    int** p = subsets(nums, 3, &size, &returncol);
    printf("%d\n", size);
    return 0;
}