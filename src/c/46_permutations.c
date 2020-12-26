#include <stdio.h>
#include <stdlib.h>
long long getCnt(int n)
{
    long val = 1;
    for (int i = 1; i <= n; i++) {
        val *= i;
    }

    return val;
}

void dfs(int* nums, int numsSize, int* returnSize, int** result, int* tmp, int tmpSize, int* visited)
{
    if (tmpSize == numsSize) {
        int* ans = (int*)malloc(sizeof(int) * numsSize);
        memcpy(ans, tmp, sizeof(int) * tmpSize);
        result[(*returnSize)++] = ans;
        return;
    }

    for (int i = 0; i < numsSize; i++) {
        if (visited[i]) {
            continue;
        }

        tmp[tmpSize] = nums[i];
        visited[i] = 1;
        dfs(nums, numsSize, returnSize, result, tmp, tmpSize + 1, visited);
        visited[i] = 0;
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    *returnSize = 0;
    if (numsSize == 0) {
        return NULL;
    }

    int cnt = getCnt(numsSize);
    int** result = (int**)malloc(sizeof(int*) * cnt);
    *returnColumnSizes = (int*)malloc(sizeof(int) * cnt);
    for (int i = 0; i < cnt; i++) {
        (*returnColumnSizes)[i] = numsSize;
    }
    int* tmp = (int*)malloc(sizeof(int) * numsSize);
    int* visited = (int*)calloc(numsSize, sizeof(int));
    dfs(nums, numsSize, returnSize, result, tmp, 0, visited);
    return result;
}