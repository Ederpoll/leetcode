#include <stdio.h>
#define MAX_CNT 10000
void dfs(int n, char *str, int index, int leftCnt, int rightCnt, char **arr, int *returnSize)
{
    if (leftCnt == n && rightCnt == n)
    {
        char *tmp = (char *)malloc(sizeof(char) * (2 * n + 1));
        memset(tmp, 0, sizeof(char) * (2 * n + 1));
        //memcpy(tmp, str, sizeof(char) * (2 * n + 1));
        strcpy(tmp, str);
        arr[(*returnSize)++] = tmp;
        return;
    }

    if (leftCnt < n)
    {
        str[index] = '(';
        dfs(n, str, index + 1, leftCnt + 1, rightCnt, arr, returnSize);
    }

    if (rightCnt < leftCnt && rightCnt < n)
    {
        str[index] = ')';
        dfs(n, str, index + 1, leftCnt, rightCnt + 1, arr, returnSize);
    }
}

char **generateParenthesis(int n, int *returnSize)
{
    char **ans = (char **)malloc(sizeof(char *) * MAX_CNT);
    *returnSize = 0;
    char *str = (char *)malloc(sizeof(char) * (2 * n + 1));
    memset(str, 0, sizeof(char) * (2 * n + 1));
    dfs(n, str, 0, 0, 0, ans, returnSize);
    return ans;
}