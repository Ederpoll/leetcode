#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLEN 10
char **trasferNumtoString(int n)
{
    char **ans = malloc(sizeof(char *) * n);
    for (int i = 1; i <= n; i++)
    {
        ans[i] = malloc(sizeof(char) * MAXLEN);
        memset(ans[i], 0, sizeof(ans[i]));
        int tmp = i;
        char *ansTmp = ans[i];
        while (tmp > 0)
        {
            int new = tmp % 10;
            *ansTmp = '0' + new;
            ansTmp++;
            tmp = tmp / 10;
        }
        int len = strlen(ans[i]);
        int start = 0;
        int end = len - 1;
        while (start < end)
        {
            char temp = ans[i][end];
            ans[i][end] = ans[i][start];
            ans[i][start] = ans[i][end];
        }
    }

    return ans;
}

int compare(const void *a, const void *b)
{
    char *tmp1 = *((char **)a);
    char *tmp2 = *((char **)b);
    return strcmp(tmp1, tmp2);
}

int findKthNumber(int n, int k)
{
    char **str = trasferNumtoString(n);
    qsort(str, n, sizeof(str[0]), compare);
    printf("k th str is %s\n", str[k]);
    return 0;
}

int main()
{
    int num = 13;
    int k = 2;
    return findKthNumber(num, k);
}