#include <stdio.h>
#include <stdlib.h>
long long getCnt(int n, int k)
{
    long long ans = 1;
    for (int i = k + 1; i <= n; i++) {
        ans *= i;
    }

    for (int i = 1; i <= n - k; i++) {
        ans = ans / i;
    }

    return ans;
}

void dfs(int cur, int n, int k, int* returnSize, int** result, int* tmp,
    int tmpSize)
{
    if (tmpSize + n - cur + 1 < k) {
        return;
    }

    if (tmpSize == k) {
        int* ans = (int*)malloc(sizeof(int) * k);
        memcpy(ans, tmp, sizeof(int) * k);
        result[(*returnSize)++] = ans;
        return;
    }

    tmp[tmpSize++] = cur;
    dfs(cur + 1, n, k, returnSize, result, tmp, tmpSize);
    tmpSize--;
    dfs(cur + 1, n, k, returnSize, result, tmp, tmpSize);
}
int** combine(int n, int k, int* returnSize, int** returnColumnSizes)
{
    int cnt = getCnt(n, k);
    int** result = (int**)malloc(sizeof(int*) * cnt);
    int* tmp = (int*)calloc(k, sizeof(int));
    *returnColumnSizes = (int*)malloc(sizeof(int) * cnt);
    for (int i = 0; i < cnt; i++) {
        (*returnColumnSizes)[i] = k;
    }

    *returnSize = 0;
    dfs(1, n, k, returnSize, result, tmp, 0);
    return result;
}

int main()
{
    int cnt = getCnt(25, 12);
    printf("%d\n", cnt);
    return 0;
}